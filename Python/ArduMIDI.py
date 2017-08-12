import os
import midi

def get_num2tag(num=100):
    tag = 'C CS D DS E F FS G GS A AS B'.split()
    l = len(tag)
    num2tag = {i:tag[i%l] + str((i / l) - 1) for i in range (num)}
    num2tag[-1] = 0
    return num2tag

def extract_noteEvent(events):
    tones, d, tick = [], {}, 0
    for e in events:
        tick += e.tick
        if type(e) == midi.events.NoteOnEvent:
            if e.data[1] == 0:
                tones.append({'tone':e.data[0], 'tick':d[e.data[0]], 'dulation':tick -d[e.data[0]]})
            else:
                d[e.data[0]] = tick
        elif type(e) == midi.events.NoteOffEvent:
            tones.append({'tone':e.data[0], 'tick':d[e.data[0]], 'dulation':tick -d[e.data[0]]})
    return tones

def split_track(tones, max_track_num):
    max_track_idx = 0
    track = [{'tick':0, 'tones':[]} for i in range(max_track_num)]
    for d in tones:
        for i in range(max_track_num):
            if track[i]['tick'] <= d['tick']:
                track[i]['tick'] = d['tick'] + d['dulation']
                track[i]['tones'].append(d)
                max_track_idx = max([max_track_idx, i])
                break
    return track[:max_track_idx + 1]

def decode_track(track):
    track_d = []
    pt = None
    for i, t in enumerate(track):
        if i != 0:
            if not pt['tick'] + pt['dulation'] == t['tick']:
                track_d.append({'tone':-1, 'tick':pt['tick'] + pt['dulation'], 'dulation':t['tick'] - pt['tick'] - pt['dulation']})
        else:
            track_d.append({'tone':-1, 'tick':0, 'dulation':t['tick']})
        track_d.append(t)
        pt = t
    return track_d
    
def to_code(name, track):
    tn = ['NOTE_%s, ' %(num2tag[t['tone']]) for t in track]
    dt = ['%s, ' %(t['dulation']) for t in track] 
    r = ['PROGMEM const unsigned int %s%s[] = {%s};\n' %(name, k, ''.join(txt)) for k, txt in [['T', tn], ['D', dt]]]
    return r[0] + r[1]

def write_preprocess(f):
    f.write('#include <avr/pgmspace.h>\n')
    f.write('#include "pitches.h"\n')
    f.write('#define NOTE_0 0\n\n')

def write_tracks(track, max_track_num, save_name, variable_name='mel'):
    with open(save_name, 'w') as f:
        write_preprocess(f)
        f.write('int trackNum = %s;\n' %(len(track)))
        for i, t in enumerate(track):
            new_track = decode_track(t['tones'])
            txt = to_code(variable_name + str(i), new_track)
            f.write(txt + '\n')
        for _i in range(i + 1, max_track_num):
            new_track = []
            txt = to_code(variable_name + str(_i), new_track)
            f.write(txt + '\n')

def midi_to_arduino(f_name, max_track_num=6, save_dir='out/'):
    save_name = save_dir + '%s.h' % os.path.basename(f_name)
    pat = midi.read_midifile(f_name)
    tones = [extract_noteEvent(p) for p in pat]
    tones = [t for ts in tones for t in ts]
    tones = sorted(tones, key=lambda x: x['tick'])
    track = split_track(tones, max_track_num)
    write_tracks(track, max_track_num, save_name)


f_name = 'Data/Mario-Sheet-Music-Flagpole-Fanfare.mid'

num2tag = get_num2tag()
midi_to_arduino(f_name)

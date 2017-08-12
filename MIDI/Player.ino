// http://garretlab.web.fc2.com/arduino/introduction/memory/

#include "h/Mario-Sheet-Music-Flagpole-Fanfare.mid.h"

unsigned int* TONE_PINS;
long cDuration;
int maxTrackNum = 6; // TODO:

long* microF = new long[trackNum];
long* microD = new long[trackNum];
bool* flip = new bool[trackNum];
unsigned int* pointer = new unsigned int[trackNum];
unsigned int* len = new unsigned int[trackNum];
long* frequency = new long[trackNum];
long* duration = new long[trackNum];
long* tones = new long[trackNum];

const unsigned int** melT = new const unsigned int*[maxTrackNum];
const unsigned int** melD = new const unsigned int*[maxTrackNum];
int* melSize = new int[trackNum];

void initPlayer(unsigned int* _TONE_PINS, long _cDuration) {
  TONE_PINS = _TONE_PINS;
  cDuration = _cDuration;

  // TODO:
  melT[0] = mel0T;
  melT[1] = mel1T;
  melT[2] = mel2T;
  melT[3] = mel3T;
  melT[4] = mel4T;
  melT[5] = mel5T;
  melSize[0] = sizeof(mel0T);
  melSize[1] = sizeof(mel1T);
  melSize[2] = sizeof(mel2T);
  melSize[3] = sizeof(mel3T);
  melSize[4] = sizeof(mel4T);
  melSize[5] = sizeof(mel5T);
  melD[0] = mel0D;
  melD[1] = mel1D;
  melD[2] = mel2D;
  melD[3] = mel3D;
  melD[4] = mel4D;
  melD[5] = mel5D;

  for (int i = 0; i < trackNum; i++) {
    flip[i] = false;
    pointer[i] = -1;
    pinMode(TONE_PINS[i], OUTPUT);
  }

  for (int i = 0; i < trackNum; i++)
    len[i] = getSize(i);
}

long freqToTone(long freq) {
  return 1000000L / (2 * freq);
}

void updateFrequencyDuration(int p) {
  pointer[p]++;
  frequency[p] = getTone(pointer[p], p);
  duration[p] = getDuration(pointer[p], p) * cDuration;
  if (frequency[p] != 0)
    tones[p] = freqToTone(frequency[p]);
  setLED(p, frequency[p], duration[p]);
}

void updateTone() {
  for (int p = 0; p < trackNum; p++) {
    if (pointer[p] == -1) {
      microF[p] = micros();
      microD[p] = micros();
      updateFrequencyDuration(p);
    }

    if (pointer[p] < len[p]) {
      if (microD[p] + duration[p] < micros()) {
        microD[p] = micros();
        updateFrequencyDuration(p);
      }

      if (frequency[p] != 0) {
        if (microF[p] + tones[p] < micros()) {
          microF[p] = micros();
          digitalWrite(TONE_PINS[p], flip[p] = !flip[p]);
        }
      }
    }
  }
}

unsigned int getTone(int p, int m) {
  return pgm_read_word(melT[m] + p);
}

unsigned int getDuration(int p, int m) {
  return pgm_read_word(melD[m] + p);
}

int getSize(int m) {
  return melSize[m] / sizeof(*melT[m]);
}

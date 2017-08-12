#include <Adafruit_NeoPixel.h>

unsigned int LED_PIN = 11;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, LED_PIN, NEO_GRB + NEO_KHZ800);

// i番目のtrackがon,offの時にarr[i]番目のLEDを使う
int* ledMapOn;
int* ledMapOff;

unsigned int* fMax;
unsigned int* fMin;
unsigned int* dMax;
unsigned int* dMin;

void initLED(int trackNum, int* _ledMapOn, int* _ledMapOff) {
  ledMapOn = _ledMapOn;
  ledMapOff = _ledMapOff;

  fMax = new unsigned int[trackNum];
  fMin = new unsigned int[trackNum];
  dMax = new unsigned int[trackNum];
  dMin = new unsigned int[trackNum];
  for (int i = 0; i < trackNum; i++) {
    fMin[i] = 1000;
    dMin[i] = 1000;
  }

  strip.setBrightness(5);
  strip.begin();
  strip.show();
}

void setLED(int led, unsigned int freq, unsigned int d) {
  if (freq != 0) { // これまでのfreqに基づいて光らせる
    fMax[led] = max(fMax[led], freq);
    fMin[led] = min(fMin[led], freq);
    int c = map(freq, fMin[led], fMax[led], 0, 200);
    strip.setPixelColor(ledMapOn[led], wheel(c));
  } else { // 無音の時は無音が続く時間に基づいて光らせる
    strip.setPixelColor(ledMapOn[led], strip.Color(55, 55, 55));
    dMax[led] = max(dMax[led], d);
    dMin[led] = min(dMin[led], d);
    int c = map(d, dMin[led], dMax[led], 0, 200);
    strip.setPixelColor(ledMapOff[led], wheel(c));
  }
  strip.show();
}

uint32_t wheel(byte wheelPos) { // AdaFruitのコードそのまま
  wheelPos = 255 - wheelPos;
  if (wheelPos < 85) {
    return strip.Color(255 - wheelPos * 3, 0, wheelPos * 3);
  }
  if (wheelPos < 170) {
    wheelPos -= 85;
    return strip.Color(0, wheelPos * 3, 255 - wheelPos * 3);
  }
  wheelPos -= 170;
  return strip.Color(wheelPos * 3, 255 - wheelPos * 3, 0);
}


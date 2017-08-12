void setup() {
  Serial.begin(9600);

  unsigned int TONE_PINS[] = {2, 3, 4, 5, 6, 7};
  long cDuration = 160L; // Mario
  // long cDuration = 1000L;
  initPlayer(TONE_PINS, cDuration);

  extern int trackNum;
  int ledMapOn[3] = {2, 3, 4};
  int ledMapOff[3] = {1, 6, 5};
  initLED(trackNum, ledMapOn, ledMapOff);
}

void loop() {
  updateTone();
}

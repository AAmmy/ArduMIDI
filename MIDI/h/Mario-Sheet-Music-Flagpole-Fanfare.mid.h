#include <avr/pgmspace.h>
#include "pitches.h"
#define NOTE_0 0

int trackNum = 5;
PROGMEM const unsigned int mel0T[] = {NOTE_0, NOTE_G3, NOTE_0, NOTE_B3, NOTE_0, NOTE_D4, NOTE_0, NOTE_F4, NOTE_0, NOTE_A4, NOTE_0, NOTE_C5, NOTE_0, NOTE_E5, NOTE_0, NOTE_G5, NOTE_0, NOTE_B5, NOTE_0, NOTE_D6, NOTE_0, NOTE_F6, NOTE_0, NOTE_G3, NOTE_0, NOTE_E4, NOTE_0, NOTE_C5, NOTE_0, NOTE_G5, NOTE_0, NOTE_E5, NOTE_0, NOTE_GS3, NOTE_0, NOTE_DS4, NOTE_0, NOTE_C5, NOTE_0, NOTE_GS5, NOTE_0, NOTE_DS5, NOTE_0, NOTE_AS3, NOTE_0, NOTE_F4, NOTE_0, NOTE_D5, NOTE_0, NOTE_AS5, NOTE_0, NOTE_AS5, NOTE_0, NOTE_AS5, NOTE_0, NOTE_AS5, };
PROGMEM const unsigned int mel0D[] = {10, 360, 20, 370, 20, 370, 20, 370, 20, 370, 20, 370, 20, 370, 20, 370, 20, 370, 20, 370, 20, 218, 4074, 754, 633, 724, 641, 702, 642, 2070, 1, 2024, 1, 754, 633, 724, 641, 702, 642, 2070, 1, 2024, 1, 754, 633, 724, 641, 702, 642, 2070, 1, 680, 1, 661, 1, 722, };

PROGMEM const unsigned int mel1T[] = {NOTE_0, NOTE_A3, NOTE_0, NOTE_C4, NOTE_0, NOTE_E4, NOTE_0, NOTE_G4, NOTE_0, NOTE_B4, NOTE_0, NOTE_D5, NOTE_0, NOTE_F5, NOTE_0, NOTE_A5, NOTE_0, NOTE_C6, NOTE_0, NOTE_E6, NOTE_0, NOTE_G6, NOTE_0, NOTE_C4, NOTE_0, NOTE_G4, NOTE_0, NOTE_E5, NOTE_0, NOTE_C4, NOTE_0, NOTE_C4, NOTE_0, NOTE_GS4, NOTE_0, NOTE_DS5, NOTE_0, NOTE_C4, NOTE_0, NOTE_D4, NOTE_0, NOTE_AS4, NOTE_0, NOTE_F5, NOTE_0, NOTE_D4, NOTE_0, NOTE_D4, NOTE_0, NOTE_D4, };
PROGMEM const unsigned int mel1D[] = {195, 370, 20, 370, 20, 370, 20, 370, 20, 370, 20, 370, 20, 370, 20, 370, 20, 370, 20, 370, 21, 275, 4535, 713, 644, 721, 622, 722, 2031, 2024, 715, 713, 644, 721, 622, 722, 2031, 2024, 715, 713, 644, 721, 622, 722, 2031, 680, 1, 661, 1, 722, };

PROGMEM const unsigned int mel2T[] = {NOTE_0, NOTE_E3, NOTE_0, NOTE_C3, NOTE_0, NOTE_G3, NOTE_0, NOTE_DS3, NOTE_0, NOTE_C3, NOTE_0, NOTE_GS3, NOTE_0, NOTE_F3, NOTE_0, NOTE_D3, NOTE_0, NOTE_AS3, NOTE_0, NOTE_C6, };
PROGMEM const unsigned int mel2D[] = {8906, 713, 644, 721, 622, 722, 4770, 713, 644, 721, 622, 722, 4770, 713, 644, 721, 622, 722, 4056, 4095, };

PROGMEM const unsigned int mel3T[] = {NOTE_0, NOTE_G3, NOTE_0, NOTE_E3, NOTE_0, NOTE_E4, NOTE_0, NOTE_GS3, NOTE_0, NOTE_DS3, NOTE_0, NOTE_DS4, NOTE_0, NOTE_AS3, NOTE_0, NOTE_F3, NOTE_0, NOTE_F4, NOTE_0, NOTE_C4, };
PROGMEM const unsigned int mel3D[] = {9579, 724, 641, 702, 642, 2070, 3413, 724, 641, 702, 642, 2070, 3413, 724, 641, 702, 642, 2070, 2026, 4095, };

PROGMEM const unsigned int mel4T[] = {NOTE_0, NOTE_E4, };
PROGMEM const unsigned int mel4D[] = {32768, 4095, };

PROGMEM const unsigned int mel5T[] = {};
PROGMEM const unsigned int mel5D[] = {};

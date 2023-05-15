#ifndef BLED_H
#define BLED_H

#include "Actuator.h"
#include <FastLED.h>
#include <vector>

using namespace std;

template <uint8_t N>
struct LEDParams {
  static const uint8_t pin = N;
  static const int num_leds = 10;
};

template<uint8_t N>
class BLED : protected Actuator {
private:
  LEDParams<N> Params;
  int nb_led;
  CRGB leds[10];
public:
  BLED(int nport, int nbLED);
  void setup();
  void display(vector<int> colortab);
  void setLED(int Led, int color);
  void setLEDs(int color);
};

#endif

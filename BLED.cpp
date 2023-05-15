#include "BLED.h"

using namespace std;

/*
template <uint8_t N>
struct LEDParams {
  static const uint8_t pin = N;
  static const int num_leds = 10;
};*/

template<uint8_t N>
BLED<N>::BLED(int nport, int nbLED)
  : Actuator(nport), leds(), nb_led(nbLED) {
}

template<uint8_t N>
void BLED<N>::setup() {
  FastLED.addLeds<WS2813, N, GRB>(leds, LEDParams<D6>::num_leds);
}

template<uint8_t N>
void BLED<N>::display(vector<int> colortab) {
  int LED2Update;
  if (colortab.size() < this->nb_led) {
    LED2Update = colortab.size();
  } else {
    LED2Update = this->nb_led;
  }
  for (int i = 0; i < LED2Update; i++) {
    leds[i] = colortab[i];
  }

  // Actualiser les LEDs
  FastLED.show();
}

template<uint8_t N>
void BLED<N>::setLED(int Led, int color) {
  leds[Led] = color;
  FastLED.show();
}

template<uint8_t N>
void BLED<N>::setLEDs(int color) {
  for (int i = 0; i < this->nb_led; i++) {
    leds[i] = color;
  }
  FastLED.show();
}
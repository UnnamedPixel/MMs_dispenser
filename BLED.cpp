#include "BLED.h"

using namespace std;

template <uint8_t N>
struct LEDParams {
  static const uint8_t pin = N;
  static const int num_leds = 10;
};

BLED::BLED(int nport, int nbLED)
  : Actuator(nport), leds(), nb_led(nbLED) {
}

void BLED::setup() {
  FastLED.addLeds<WS2813, LEDParams<D6>::pin, GRB>(leds, LEDParams<D6>::num_leds);
}

void BLED::display(vector<int> colortab) {
  int LED2Update;
  if (colortab.size() < nb_led) {
    LED2Update = colortab.size();
  } else {
    LED2Update = nb_led;
  }
  for (int i = 0; i < LED2Update; i++) {
    leds[i] = colortab[i];
  }

  // Actualiser les LEDs
  FastLED.show();
}

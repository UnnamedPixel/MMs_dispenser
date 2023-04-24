
#include "BLED.h"

using namespace std;


BLED::BLED(int nport, int nbLED)
  : Actuator(nport), leds(),nb_led(nbLED) {
}

void BLED::setup() {
  FastLED.addLeds<WS2813, D5, GRB>(leds, nb_led);
}


void BLED::display(vector<int> colortab) {
  int LED2Update;
  if (colortab.size() < nb_led){LED2Update = colortab.size();}
  else {LED2Update=nb_led;}
  for (int i = 0; i < LED2Update; i++) {
    leds[i] = colortab[i];
  }

  // Actualiser les LEDs
  FastLED.show();
}

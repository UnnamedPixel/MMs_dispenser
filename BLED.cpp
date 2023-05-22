#include "BLED.h"

using namespace std;

template<uint8_t N>
BLED<N>::BLED(int nport, int nbLED)
  : Driver(nport), leds(), nb_led(nbLED) {
}

template<uint8_t N>
void BLED<N>::setup() {
  FastLED.addLeds<WS2813, N, GRB>(leds, LEDParams<D6>::num_leds);  // Ajouter les LEDs et définir le type de LED, le port et le format de couleur
}

template<uint8_t N>
void BLED<N>::display(vector<int> colortab) {
  int LED2Update;
  if (colortab.size() < this->nb_led+1) {
    LED2Update = colortab.size();
  } else {
    LED2Update = this->nb_led+1;
  }
  for (int i = 0; i < LED2Update; i++) {
    leds[i] = colortab[i];  // Mettre à jour les couleurs des LEDs en fonction du tableau de couleurs fourni
  }

  // Actualiser les LEDs
  FastLED.show();
}

template<uint8_t N>
void BLED<N>::setLED(int Led, int color) {
  leds[Led] = color;  // Définir la couleur de la LED spécifiée
  FastLED.show();
}

template<uint8_t N>
void BLED<N>::setLEDs(int color) {
  for (int i = 0; i < this->nb_led+1; i++) {
    leds[i] = color;  // Définir la couleur de toutes les LEDs
  }
  FastLED.show();
}

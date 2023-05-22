#ifndef BLED_H
#define BLED_H

#include "Driver.h"
#include <FastLED.h>
#include <vector>

using namespace std;

template <uint8_t N>
struct LEDParams {
  static const uint8_t pin = N;  // Numéro du port utilisé pour les LEDs
  static const int num_leds = 10;  // Nombre total de LEDs
};

template<uint8_t N>
class BLED : protected Driver {
private:
  LEDParams<N> Params;
  int nb_led;  // Nombre de LEDs utilisées
  CRGB leds[10];  // Tableau de LEDs
public:
  // Constructeur de la classe BLED avec un argument "nport" pour le numéro du port et "nbLED" pour le nombre de LEDs
  BLED(int nport, int nbLED);

  // Effectue la configuration initiale des LEDs
  void setup();

  // Affiche les couleurs spécifiées dans le tableau "colortab" sur les LEDs
  void display(vector<int> colortab);

  // Définit la couleur de la LED spécifiée par "Led"
  void setLED(int Led, int color);

  // Définit la couleur de toutes les LEDs
  void setLEDs(int color);
};

#endif

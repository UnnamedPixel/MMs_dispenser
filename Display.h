#ifndef DISPLAY_H
#define DISPLAY_H

#include "Driver.h"
#include <string>
#include "rgb_lcd.h"
#include <Wire.h>
#include "BLED.h"

using namespace std;

class Display : protected Driver {
public:
  // Affiche le message "mess" à l'écran pendant la durée spécifiée "t" (en millisecondes)
  void Print(String mess, int t);

  // Constructeur de la classe Display avec un argument "n" pour le numéro du driver
  Display(int n);

  // Effectue la configuration initiale de l'écran
  void setup();

  // Affiche le message "mess" à l'écran
  void PrintL(String mess);

  // Efface le contenu de l'écran
  void Clear();

  // Affiche le message numérique "mess" à l'écran
  void PrintL(int mess);

  // Définit la couleur RGB de l'écran en spécifiant les valeurs de rouge "R", vert "G" et bleu "B"
  void setColor(int R, int G, int B);

  // Déplace le curseur à la position spécifiée sur la ligne spécifiée
  void Line(int line);

  rgb_lcd lcd;
};

#endif

#ifndef KEYPAD_H
#define KEYPAD_H

#include "Driver.h"
#import <Arduino.h>
#include "SoftwareSerial.h"

#include <vector>
using namespace std;

class Keypad : protected Driver {
  private:
  SoftwareSerial SerialCom; // Objet SoftwareSerial pour la communication série
  
  public:
  Keypad(int nport); // Constructeur prenant le numéro du port en argument
  void setup(); // Méthode pour l'initialisation
  char WaitForEntry(); // Méthode pour attendre une entrée depuis le clavier
  char WaitForEntry(char resp, int maxWaitTime); // Méthode pour attendre une entrée avec un temps d'attente maximum spécifié
  char WaitForEntry(int maxWaitTime); // Méthode pour attendre une entrée avec un temps d'attente maximum spécifié
  char Entry(char var);
};

#endif

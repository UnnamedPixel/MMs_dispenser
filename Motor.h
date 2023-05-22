#ifndef MOTOR_H
#define MOTOR_H

#include "Driver.h"
#include <Servo.h>  // Inclure la bibliothèque Servo

using namespace std;

template<uint8_t N>
struct MotorParams {
  static const uint8_t pin = N;  // Numéro de la broche utilisée pour le servomoteur
};

template<uint8_t N>
class Motor : protected Driver {
private:
  MotorParams<N> Params;
  Servo myservo;     // Créer un objet Servo
  int position = 0;  // Variable pour stocker la position du servomoteur
public:
  // Constructeur de la classe Motor avec un argument "nport" pour le numéro du port
  Motor(int nport);

  // Effectue la configuration initiale du servomoteur
  void setup();

  // Déplace le servomoteur vers la position spécifiée "pos" et renvoie la position définie
  int move2pos(int pos);
};

#endif

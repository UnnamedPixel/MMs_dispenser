#include "Motor.h"

using namespace std;

template<uint8_t N>
Motor<N>::Motor(int nport)
  : Driver(nport), myservo() {
}

template<uint8_t N>
void Motor<N>::setup() {
  myservo.attach(Params.pin);  // Attacher le servomoteur à la broche spécifiée
}

template<uint8_t N>
int Motor<N>::move2pos(int pos) {
  myservo.write(pos);  // Définir la position du servomoteur
  return pos;  // Renvoyer la position définie
}

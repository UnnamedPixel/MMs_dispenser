#include "Motor.h"

using namespace std;

/*
template<uint8_t N>
struct MotorParams {
  static const uint8_t pin = N;
};*/

template<uint8_t N>
Motor<N>::Motor(int nport)
  : Actuator(nport), myservo() {
}

template<uint8_t N>
void Motor<N>::setup() {
  myservo.attach(Params.pin);  // attach the servo to the specified pin
}

template<uint8_t N>
int Motor<N>::move2pos(int pos) {
  myservo.write(pos);  // set the servo position
  return pos;
}

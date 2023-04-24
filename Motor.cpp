#include "Motor.h"

using namespace std;


template<uint8_t N>
struct MotorParams {
  static const uint8_t pin = N;
};

Motor::Motor(int nport)
  : Actuator(nport), myservo() {
}


void Motor::setup() {
  myservo.attach(MotorParams<D6>::pin);  // attach the servo to the specified pin
}

int Motor::move2pos(int pos) {
  myservo.write(pos);  // set the servo position
  return pos;
}

#ifndef MOTOR_H
#define MOTOR_H

#include "Actuator.h"
#include <Servo.h>  // include the Servo library
//#include "MotorParams.h"

using namespace std;

template<uint8_t N>
struct MotorParams {
  static const uint8_t pin = N;
};


template<uint8_t N>
class Motor : protected Actuator {
private:
  MotorParams<N> Params;
  Servo myservo;     // create a servo object
  int position = 0;  // variable to store the servo position
public:
  Motor(int nport);
  void setup();
  int move2pos(int pos);
};

#endif

  #ifndef MOTOR_H
  #define MOTOR_H

  #include "Actuator.h"
  #include <Servo.h> // include the Servo library

  using namespace std;

  class Motor : protected Actuator {
  private:
    Servo myservo; // create a servo object
    int position = 0; // variable to store the servo position
  public:
    Motor(int nport);
    void setup();
    int move2pos(int pos);
  };

  #endif

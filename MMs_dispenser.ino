#include "MMS_dispenser.h"
<<<<<<< HEAD
#include "BLED.cpp"
#define BLED_DATA_PIN D6

BLED<BLED_DATA_PIN> Banc(BLED_DATA_PIN,6);
vector<int> tabint1  = {0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow};
vector<int> tabint2  = {CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE};
=======
#include "motor.cpp"

#define MOTOR_DATA_PIN D7

Motor<MOTOR_DATA_PIN> theMOTOR(D7);
>>>>>>> MotorDONE

void setup() {
  theMOTOR.setup();
}

void loop() {
  theMOTOR.move2pos(120);
  delay(2000);
  theMOTOR.move2pos(20);
  delay(2000);
}

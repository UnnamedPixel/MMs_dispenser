#include "MMS_dispenser.h"
#include "motor.cpp"

#define MOTOR_DATA_PIN D7

Motor<MOTOR_DATA_PIN> theMOTOR(D7);

void setup() {
  theMOTOR.setup();
}

void loop() {
  theMOTOR.move2pos(120);
  delay(2000);
  theMOTOR.move2pos(20);
  delay(2000);
}

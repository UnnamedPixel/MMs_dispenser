#include "MMS_dispenser.h"
#include "BLED.cpp"
#include "motor.cpp"

#define BLED_DATA_PIN D6
#define MOTOR_DATA_PIN D7


BLED<BLED_DATA_PIN> Banc(BLED_DATA_PIN,6);
Motor<MOTOR_DATA_PIN> theMOTOR(MOTOR_DATA_PIN);
Speaker LEnceinte(D5);

vector<int> tabint1  = {0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow};
vector<int> tabint2  = {CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE};


void setup() {
  Banc.setup();
  theMOTOR.setup();
  LEnceinte.setup();
}

void loop() {
  theMOTOR.move2pos(120);
  Banc.display(tabint1);
  LEnceinte.playTone(4000);
  delay(2500);
  theMOTOR.move2pos(20);
  Banc.display(tabint2);
  delay(2500);
}

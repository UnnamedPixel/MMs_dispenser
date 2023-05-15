#ifndef KEYPAD_H
#define KEYPAD_H

#include "Actuator.h"
#import <Arduino.h>
#include "SoftwareSerial.h"

#include <vector>
using namespace std;

class Keypad : protected Actuator {
  private:
  SoftwareSerial SerialCom;
  public:
  Keypad(int nport);
  void setup();
  char WaitForEntry();
  char WaitForEntry(int maxWaitTime);
};


#endif
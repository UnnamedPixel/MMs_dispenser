#ifndef DISPLAY_H
#define DISPLAY_H

#include "Driver.h"
#include <string>
#include "rgb_lcd.h"
#include <Wire.h>
#include "BLED.h"

using namespace std;

class Display : protected Driver {
public:
  void Print(String mess, int t);
  Display(int n);
  void setup();
private:
  rgb_lcd lcd;
};

#endif

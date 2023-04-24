#include "MMS_dispenser.h"
#include "BLED.cpp"
#define BLED_DATA_PIN D6

BLED<BLED_DATA_PIN> Banc(BLED_DATA_PIN,6);
vector<int> tabint1  = {0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow};
vector<int> tabint2  = {CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE};

void setup(){
  Banc.setup();
}

void loop(){    
    Banc.display(tabint1);
    delay(1500);
    Banc.display(tabint2);
    delay(1500);
}

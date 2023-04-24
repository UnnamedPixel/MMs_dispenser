#include "MMS_dispenser.h"

#define BLED_DATA_PIN D5

BLED Banc(D6,6);
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

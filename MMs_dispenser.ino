#include "MMS_dispenser.h"
 
BLED Banc(5,6);
vector<int> tabint  = {0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow};
void setup(){
  Banc.setup();
}

void loop(){    
    Banc.display(tabint);
    delay(5000);
}

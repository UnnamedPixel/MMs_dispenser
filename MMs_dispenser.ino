#include "MMS_dispenser.h"

Display Ecran(0);
void setup() {
  Ecran.setup();
}

void loop() {
  Ecran.Print("bonjour", 400);
  delay(10000);
}

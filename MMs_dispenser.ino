#include "Color.h"
#include "BLED.h"
#include "Display.h"

Display Ecran(0);
//BLED Banc(5,10);
void setup(){
  Ecran.setup();
  
}

void loop(){
    Ecran.Print("bonjour",400);
    delay(10000);

}

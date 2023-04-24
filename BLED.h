  #ifndef BLED_H
  #define BLED_H

  #include "Actuator.h"
  #include <FastLED.h>
  #include <vector>

  using namespace std;

  class BLED : protected Actuator {
  private:
    int nb_led;
    CRGB leds[10];
  public:
    BLED(int nport, int nbLED);
    void setup();
    void display(vector<int> colortab);
  };

  #endif

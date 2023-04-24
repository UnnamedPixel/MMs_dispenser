#ifndef SPEAKER_H
#define SPEAKER_H

#include "Actuator.h"
#import <Arduino.h>

class Speaker : protected Actuator {
  public:
  Speaker(int nport);
  void setup();
  void playTone(int freq);
};


#endif

#ifndef ACTUATOR_H
#define ACTUATOR_H

#include "Driver.h"

class Actuator : protected Driver {
  private:
    int getINOUT();
  public:
    Actuator(int nport);
};

#endif
 


#ifndef ACTUATOR_H
#define ACTUATOR_H

#include "Driver.h"

class Actuator : protected Driver {
  public:
    Actuator(int nport);
};

#endif
 

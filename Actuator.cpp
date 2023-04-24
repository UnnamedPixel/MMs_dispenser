
#include "Actuator.h"

// Actuator is an output for the Microcontroller
int Actuator::getINOUT(){
        return 1;
    }

Actuator::Actuator(int nport):Driver(nport){}

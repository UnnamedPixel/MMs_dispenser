
#include "Actuator.h"

int Actuator::getINOUT(){
        return 1;
    }

Actuator::Actuator(int nport):Driver(nport){}

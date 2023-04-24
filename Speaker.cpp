#include "speaker.h"

Speaker::Speaker(int nport):Actuator(nport){};


void Speaker::setup(){pinMode(nport,OUTPUT);}

void Speaker::playTone(int freq){tone(nport,freq);}
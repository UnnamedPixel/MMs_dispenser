#include "Color.h"
int S[] = {
  Pink1, 0, Pink1, 0, Pink1, Blue1,  0, Pink1, 0, Orange2, 0, Pink1, 0, Green1, Blue1, 0, Pink1, 0, Pink1, 0, Pink1,  Blue1, 0, Pink1, 0, LGreen2, 0, Yellow2, 0, Orange2, Blue1, 0, Pink1, 0, Pink1,  0, Pink1, Blue1, 0, Pink1, 0, Orange2, 0, Pink1, 0, Green1, Blue1, 0, Pink1, 0,  Pink1, 0, Pink1, Blue1, Pink1, Orange2, 0, LGreen2, 0, Yellow2, 0, Orange2, Blue1,  0, Pink1, 0, Pink1, 0, Pink1, Blue1, 0, Pink1, 0, Orange2, 0, Pink1, 0, Green1,  Blue1, 0, Pink1, 0, Pink1, 0, Pink1, Blue1, 0, Pink1, 0, LGreen2, 0, Yellow2, 0,  Orange2, Blue1, 0, Pink1, 0, Pink1, 0, Pink1, Blue1, 0, Pink1, 0, Orange2, 0, Pink1,  0, Green1, Blue1, 0, Pink1, 0, Pink1, 0, Pink1, 0, Blue1, Pink1, 0, 0, 0, 0, Pink1,  0,
  Orange2, 0, Yellow2, LGreen2, 0, Green2, 0, Blue2, 0, Green2, 0, Blue2,  Purple2, 0, Pink2, 0, Purple2, 0, Blue2, Green2, 0, Yellow2, 0, Orange2, LBlue1,  0, Blue1, 0, Purple1, 0, Pink1, 0, Orange2, 0, Yellow2, LGreen2, 0, Green2, 0, Blue2,  0, Green2, 0, Blue2, Purple2, 0, Pink2, 0, Blue2, Pink2, Blue2, 0, Purple2, Pink2,  0, LBlue1, 0, LBlue1, Blue1, Blue1, Purple1, 0, Pink1, 0, Orange2, 0, Yellow2, LGreen2,  0, Green2, 0, Blue2, 0, Green2, 0, Blue2, Purple2, 0, Pink2, 0, Purple2, 0, Blue2,  Green2, 0, Yellow2, 0, Orange2, LBlue1, 0, Blue1, 0, Purple1, 0, Pink1, 0, Orange2,  0, Yellow2, LGreen2, 0, Green2, 0, Blue2, 0, Green2, 0, Blue2, Purple2, 0, Pink2,  0, Blue2, Pink2, Blue2, 0, Purple2, Pink2, 0, LBlue1, 0, LBlue1, Blue1, Blue1, Purple1,  0,
  Orange2, DOrange2, Pink1, 0, Blue1, 0, 0, Pink1, 0, 0, Pink1, 0, 0, 0, Green1,  0, Blue1, 0, Pink1, 0, DOrange2, 0, 0, Blue1, 0, 0, Pink1, 0, 0, 0, 0, 0, Orange2,  DOrange2, Pink1, 0, Blue1, 0, 0, Pink1, 0, 0, Pink1, 0, 0, Green1, 0, 0, DOrange2,  0, Orange2, 0, DOrange2, 0, 0, Blue1, 0, DOrange1, Yellow1, Green1, DOrange1, Green1,  LBlue1, Pink1, Orange2, DOrange2, Pink1, 0, Blue1, 0, 0, Pink1, 0, 0, Pink1, 0,  0, 0, Green1, 0, Blue1, 0, Pink1, 0, DOrange2, 0, 0, Blue1, 0, 0, Pink1, 0, 0, 0,  0, 0, Orange2, DOrange2, Pink1, 0, Blue1, Orange2, 0, Green2, Yellow2, Orange2,  Pink1, 0, Blue2, LBlue2, 0, Green2, Orange2, DOrange2, 0, Pink1, Blue1, Pink1, 0,  Blue1, Pink1, 0, Blue1, Pink1, 0, Blue1, Pink1, 0, Blue1, Pink1, Orange2, 0,
  Green2, 0, 0, 0, 0, 0, Orange2, 0, 0, 0, 0, 0, 0, Orange2, Yellow2, LGreen2, 0,  0, Yellow2, 0, 0, Orange2, 0, DOrange2, 0, 0, Orange2, 0, 0, Yellow2, 0, Green2,  0, 0, 0, 0, 0, Pink2, 0, 0, 0, 0, 0, Pink1, 0, DOrange2, 0, Orange2, 0, 0, Yellow2,  0, 0, Orange2, 0, DOrange2, 0, 0, Blue2, 0, 0, DGreen2, 0, Green2, 0, 0, 0, 0, 0,  Orange2, 0, 0, 0, 0, 0, 0, Orange2, Yellow2, LGreen2, 0, 0, Yellow2, 0, 0, Orange2,  0, DOrange2, 0, 0, Orange2, 0, 0, Yellow2, 0, Green2, 0, 0, 0, 0, 0, Pink2, 0, 0,  0, 0, 0, Green2, 0, Purple2, 0, Pink2, 0, 0, DGreen2, 0, 0, Green2, 0, LGreen2,  0, 0, Pink2, 0, 0, Green2, 0, Green2
};
int L = sizeof(S);
int nds = 10;

void  setup() {  
  Serial.begin(115200);
  pinMode(D8, OUTPUT);
  L = L / 2;
  Serial.println(L);
  
}

void loop() {
  Tone();
}

void Tone()  {
  digitalWrite(D8, HIGH);
  for (int n = 0; n < 510; n++) {
    int nd =  1000 / nds;
    tone(D8, S[n], nd);
    Serial.println(n);
    int d = nd * 1.2;
    delay(d);
    noTone(6);
  }
}
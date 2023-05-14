#include "KeyPad.h"

Keypad::Keypad(int nport)
  : Actuator(nport), SerialCom(nport) {
}

void Keypad::setup() {
  this->SerialCom.begin(9600);  // initialize the SoftwareSerial port
}

char Keypad::WaitForEntry() {
  while (this->SerialCom.available() == 0) {
    delay(100);
  }
  vector<uint8_t> corres1 = { 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC };
vector<char> corres2 = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '0', '#' };

  uint8_t data = this->SerialCom.read();
  for (int i = 0; i < 10; i++) {
    if (data == corres1[i]) {
      return (corres2[i]);
    }
  }
  return data;
}

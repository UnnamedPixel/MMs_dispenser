#include "KeyPad.h"

Keypad::Keypad(int nport)
  : Driver(nport), SerialCom(nport) {
}

void Keypad::setup() {
  this->SerialCom.begin(9600);  // initialise le port SoftwareSerial
}

// Attend une entrée depuis le clavier
char Keypad::WaitForEntry() {
  while (this->SerialCom.available() == 0) {
    delay(100);
  }
  // Correspondances entre les codes et les caractères
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

// Attend une entrée depuis le clavier avec un temps d'attente maximum spécifié
char Keypad::WaitForEntry(char resp, int maxWaitTime) {
  int timer = 0 ;
  while (this->SerialCom.available() == 0 && timer < maxWaitTime) {
    delay(100);
    timer += 100;
  }
  // Si le temps d'attente maximum est dépassé, retourne resp
  if (timer >= maxWaitTime){
    return resp;
  }
  // Correspondances entre les codes et les caractères
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

// Attend une entrée depuis le clavier avec un temps d'attente maximum spécifié
char Keypad::WaitForEntry(int maxWaitTime) {
  int timer = 0 ;
  while (this->SerialCom.available() == 0 && timer < maxWaitTime) {
    delay(100);
    timer += 100;
  }
  // Si le temps d'attente maximum est dépassé, retourne 'Q'
  if (timer > maxWaitTime){
    return 'Q';
  }
  // Correspondances entre les codes et les caractères
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

// Renvoi l'entree si une entree clavier est en attente, sinon ne change pas la variable
char Keypad::Entry(char var) {
  int timer = 0 ;
  if (this->SerialCom.available() == 0) {
    return var;
  }

  // Correspondances entre les codes et les caractères
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
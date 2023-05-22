#include "MMS_dispenser.h"
#include "BLED.cpp"
#include "motor.cpp"

//DEFINE DES PINS
#define MOTOR_LOCK_DATA_PIN D3
#define ECRAN_DATA_PIN D4
#define MOTOR_ROTOR_DATA_PIN D5
#define PIN_CLAVIER D6
#define ENCEINTE_DATA_PIN D7
#define LED_DATA_PIN D8

#define NB_LED 10


//CREATION DES OBJETS
Display Lecran(ECRAN_DATA_PIN);
BLED<LED_DATA_PIN> Banc(LED_DATA_PIN, NB_LED);
Motor<MOTOR_ROTOR_DATA_PIN> MOTOR_rotor(MOTOR_ROTOR_DATA_PIN);
Motor<MOTOR_LOCK_DATA_PIN> MOTOR_lock(MOTOR_LOCK_DATA_PIN);
Speaker LEnceinte(ENCEINTE_DATA_PIN);
Keypad Clavier(PIN_CLAVIER);


void setup() {
  //SETUP DES DRIVERS
  Dispenser_setup(Lecran, MOTOR_rotor, MOTOR_lock, LEnceinte, Banc, Clavier);
  delay(1000);
  //DEMARRAGE
  Dispenser_start(Lecran, MOTOR_rotor, MOTOR_lock, LEnceinte, Banc, Clavier);
}

char resp;

void loop() {
  Serial.println("WESH");
  Lecran.setColor(255, 255, 255);
  //MENU DU CHOIX
  do {
    resp = 'M';
    resp = Clavier.Entry(resp);
    if (resp == 'M') {
      Lecran.Clear();
      Lecran.PrintL("Choix 1 :");
      Lecran.Line(2);
      Lecran.PrintL("Manger?");
      Lecran.Line(1);
      resp = Clavier.WaitForEntry(resp, 1500);
    }

    if (resp == 'M') {
      Lecran.Clear();
      Lecran.PrintL("Choix 2 :");
      Lecran.Line(2);
      Lecran.PrintL("Devine-couleur");
      Lecran.Line(1);
      resp = Clavier.WaitForEntry(resp, 1500);
    }

    if (resp == 'M') {
      Lecran.Clear();
      Lecran.PrintL("Choix 3 :");
      Lecran.Line(2);
      Lecran.PrintL("Devine-nombre");
      Lecran.Line(1);
      resp = Clavier.WaitForEntry(resp, 1500);
    }
    delay(100);
  } while ((resp != 'Q') && (resp != '1') && (resp != '2') && (resp != '3'));
  LEnceinte.playTone(400, 150);
  switch (resp) {
    case '1':
      Distribution(Lecran, MOTOR_rotor, MOTOR_lock, LEnceinte, Banc);
      break;
    case '2':
      Game_Color_guess(Lecran, MOTOR_rotor, MOTOR_lock, LEnceinte, Banc, Clavier);
      break;
    case '3':
      Game_Number_guess(Lecran, MOTOR_rotor, MOTOR_lock, LEnceinte, Banc, Clavier);
      break;
  }
}

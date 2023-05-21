#include "MMS_dispenser.h"
#include "BLED.cpp"
#include "motor.cpp"

//DEFINE DES PINS
#define MOTOR_LOCK_DATA_PIN D3
#define MOTOR_ROTOR_DATA_PIN D5
#define PIN_CLAVIER D6
#define ENCEINTE_DATA_PIN D7
#define LED_DATA_PIN D8
#define ECRAN_DATA_PIN D3  // useless

//AUTRES
#define NB_LED 10


//DEFINE A MODIFIER
// ml motor lock
// mr motor rotor
#define ml_pos_lock 40  //OK   //position de repos qui bloque les MMs


#define mr_pos_large_recup 180   //OK
#define mr_pos_large_distr 0     //OK
#define mr_pos_little_distr 180  //OK

#define ml_pos_unlock 180  //position de repos qui debloque les MMs
/*
#define mr_large_recup 0   //position qui recup bcp de MMS
#define mr_large_give 0    //position qui donnent bcp de MMS
#define mr_little_recup 0  //position qui recup 1 MMS pour le jeu
#define mr_little_give 0   //position qui donne le MMS du jeu
#define mr_color_sensor 0  //position pour id. la couleur du MMS durant le jeu
*/

//VARIABLES TABLEAUX
//tableau du Banc de LED pour proposer les couleurs

/*
BLED<BLED_DATA_PIN> Banc(BLED_DATA_PIN,6);
Motor<MOTOR_DATA_PIN> theMOTOR(MOTOR_DATA_PIN);*/


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

  //ajouter init color sensor

  //DEBUG
  Serial.begin(9600);
  Serial.println("Setup Done...");
  delay(5000);

  //DEMARRAGE - a faire une fois
  Dispenser_start(Lecran, MOTOR_rotor, MOTOR_lock, LEnceinte, Banc, Clavier);
}

char resp = 'M';

void loop() {
  vector<int> tabint1 = { 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow };
  vector<int> tabint2 = { CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE };
  vector<int> choixcouleur = { CRGB::Yellow, CRGB::Orange, CRGB::Blue, CRGB::Green, CRGB::Brown, CRGB::Red, 0, 0, 0, 0 };
  Lecran.lcd.noBlinkLED();
  Banc.display(tabint1);
  Lecran.setColor(255, 255, 255);
  //MENU DU CHOIX
  do {
    resp = 'M';
    Lecran.Clear();
    Lecran.PrintL("Choix 1 :");
    Lecran.Line(2);
    // + clignotement LED
    Lecran.PrintL("Manger?");
    Lecran.Line(1);
    // + clignotement LED
    delay(1500);
    Lecran.Clear();
    Lecran.PrintL("Choix 2 :");
    Lecran.Line(2);
    Lecran.PrintL("Devine-couleur");
    Lecran.Line(1);
    // + clignotement LED
    delay(1500);
    Lecran.Clear();
    Lecran.PrintL("Choix 3 :");
    Lecran.Line(2);
    Lecran.PrintL("Devine-nombre");
    Lecran.Line(1);
    // + clignotement LED
    resp = Clavier.WaitForEntry(1000);
    Serial.print("resp:");
    Serial.println(resp);
  } while ((resp != 'Q') && (resp != '1') && (resp != '2') && (resp != '3') && (resp != '4'));
  LEnceinte.playTone(400, 150);

  delay(1000);
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

#include "MMS_dispenser.h"
#include "BLED.cpp"
#include "motor.cpp"

//DEFINE DES PINS
#define MOTOR_ROTOR_DATA_PIN D5
#define MOTOR_LOCK_DATA_PIN D3
#define ENCEINTE_DATA_PIN D7
#define LED_DATA_PIN D8
#define ECRAN_DATA_PIN D3
#define PIN_CLAVIER D6

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

//#define BLED_DATA_PIN D6
//#define MOTOR_DATA_PIN D7
/*
BLED<BLED_DATA_PIN> Banc(BLED_DATA_PIN,6);
Motor<MOTOR_DATA_PIN> theMOTOR(MOTOR_DATA_PIN);*/
//vector<int> tabint1  = {0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow};
//vector<int> tabint2  = {CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE};
vector<int> choixcouleur = { CRGB::Yellow, CRGB::Orange, CRGB::Blue, CRGB::Green, CRGB::Brown, CRGB::Red, 0, 0, 0, 0 };


//CREATION DES OBJETS
Display Lecran(ECRAN_DATA_PIN);
BLED<LED_DATA_PIN> Banc(LED_DATA_PIN, NB_LED);
Motor<MOTOR_ROTOR_DATA_PIN> MOTOR_rotor(MOTOR_ROTOR_DATA_PIN);
Motor<MOTOR_LOCK_DATA_PIN> MOTOR_lock(MOTOR_LOCK_DATA_PIN);
Speaker LEnceinte(ENCEINTE_DATA_PIN);
Keypad Clavier(PIN_CLAVIER);


void setup() {

  //SETUP DES DRIVERS
  Banc.setup();
  MOTOR_rotor.setup();
  MOTOR_lock.setup();
  LEnceinte.setup();
  Lecran.setup();
  Clavier.setup();

  //ajouter init color sensor

  //DEBUG
  Serial.begin(9600);
  Serial.println("Setup Done...");
  delay(5000);

  //DEMARRAGE - a faire une fois
  MOTOR_lock.move2pos(ml_pos_lock);
  MOTOR_rotor.move2pos(mr_pos_little_distr);
  //LEnceinte.playMelody(START);
  // ajouter clignotement banc de LED
  // ajouter affichage ecran
}

char resp = 'M';

void loop() {

  //MENU DU CHOIX
  do {
    resp = 'M';
    Lecran.Clear();
    Lecran.PrintL("Choix 1\nManger");
    // + clignotement LED
    Lecran.Clear();
    delay(1500);
    Lecran.PrintL("1 - Manger?");
    // + clignotement LED
    delay(1500);
    Lecran.Clear();
    Lecran.PrintL("2 - Jouer?");
    // + clignotement LED
    delay(1500);
    Lecran.Clear();
    Lecran.PrintL("Alors?");
    resp = Clavier.WaitForEntry(1000);
    Serial.print("resp:");
    Serial.println(resp);
  } while ((resp != 'Q') && (resp != '1') && (resp != '2'));
  delay(2000);
  switch (resp) {
    case '1':
      //DISTRIBUTION
      Serial.println("1111");
      MOTOR_lock.move2pos(ml_pos_lock);

      MOTOR_rotor.move2pos(mr_pos_large_recup);  //recup
      Serial.println("prep distrib OK");
      delay(1000);
      MOTOR_lock.move2pos(ml_pos_unlock);
      Serial.println("unlock OK");

      //TREMBLEMENTS
      delay(2000);
      Serial.println("debut tremblements");
      MOTOR_lock.move2pos(0);
      delay(1000);
      MOTOR_lock.move2pos(ml_pos_unlock);
      delay(1000);
      MOTOR_lock.move2pos(0);
      delay(1000);
      MOTOR_lock.move2pos(ml_pos_unlock);
      Serial.println("fin tremblements");
      delay(2000);

      //FIN TREMBLEMENTS
      MOTOR_lock.move2pos(ml_pos_lock);
      delay(1000);
      MOTOR_rotor.move2pos(mr_pos_large_distr);
      Serial.println("distrib OK");
      //MOTOR_rotor.move2pos(mr_pos_large_give);  //distrib

      delay(5000);

      break;
    case '2':
      Serial.println("2222");
      /*
      //JEU
      //LEnceinte.playMelody(Jojo);
      //recup 1 MMs
      MOTOR_rotor.move2pos(mr_little_recup);  //recup
      MOTOR_lock.move2pos(ml_pos_unlock);
      delay(100);
      MOTOR_lock.move2pos(ml_pos_lock);
      //alignage MMS
      MOTOR_rotor.move2pos(mr_color_sensor);  //recup
      //couleur = color_sensor.captage();

      //demander choix
      Lecran.Print("Couleur du MMs ?", 1000);

      //choix OK
      //LEnceinte.playMelody(win);
      // distribution de tous et de 1 MMS


      //DEFAITE choix pas OK
      //LEnceinte.playMelody(loser);
      //actualiser tableau de LED pour supprimer une couleur
      LEnceinte.playMelody(LOSER);
      Banc.display(choixcouleur);*/
      break;
    default:
      Serial.println("Impossible");
      break;
  }
  //ATTENTE
  //LEnceinte.playMelody(attente);

  /*



 

  Banc.display(choixcouleur);
  //choix
  */
}

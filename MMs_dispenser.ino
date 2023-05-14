#include "MMS_dispenser.h"
#include "BLED.cpp"
#include "motor.cpp"

//DEFINE DES PINS
#define MOTOR_ROTOR_DATA_PIN D5
#define MOTOR_LOCK_DATA_PIN D3
#define ENCEINTE_DATA_PIN D7
#define LED_DATA_PIN D8
#define ECRAN_DATA_PIN D1

//AUTRES
#define NB_LED 10


//DEFINE A MODIFIER
// ml motor lock
// mr motor rotor
#define ml_pos_lock 0    //position de repos qui bloque les MMs
#define ml_pos_unlock 0  //position de repos qui debloque les MMs

#define mr_pos_repos 0     //DONE   //position de repos
#define mr_large_recup 0   //position qui recup bcp de MMS
#define mr_large_give 0    //position qui donnent bcp de MMS
#define mr_little_recup 0  //position qui recup 1 MMS pour le jeu
#define mr_little_give 0   //position qui donne le MMS du jeu
#define mr_color_sensor 0  //position pour id. la couleur du MMS durant le jeu

//VARIABLES TABLEAUX
//tableau du Banc de LED pour proposer les couleurs

//vector<int> tabint1  = {0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow};
//vector<int> tabint2  = {CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE};
vector<int> choixcouleur = { CRGB::Yellow, CRGB::Orange, CRGB::Blue, CRGB::Green, CRGB::Brown, CRGB::Red, 0, 0, 0, 0 };


//CREATION DES OBJETS
Display Lecran(ECRAN_DATA_PIN);
BLED<LED_DATA_PIN> Banc(LED_DATA_PIN, NB_LED);
Motor<MOTOR_ROTOR_DATA_PIN> MOTOR_rotor(MOTOR_ROTOR_DATA_PIN);
Motor<MOTOR_LOCK_DATA_PIN> MOTOR_lock(MOTOR_LOCK_DATA_PIN);
Speaker LEnceinte(D6);


int duration1 = 150;
int pause = 100;

void setup() {
  //SETUP DES DRIVERS
  Banc.setup();
  MOTOR_rotor.setup();
  MOTOR_lock.setup();
  LEnceinte.setup();
  Lecran.setup();
  //ajouter init du keypad
  //ajouter init color sensor

  //DEBUG
  Serial.begin(9600);
  Serial.println("Setup Done...");
  delay(5000);

  //DEMARRAGE - a faire une fois
  MOTOR_lock.move2pos(ml_pos_lock + 180);
  MOTOR_rotor.move2pos(0);
  MOTOR_rotor.move2pos(180);
  LEnceinte.playMelody(START);
  // ajouter clignotement banc de LED
  // ajouter affichage ecran
}

void loop() {
  //MENU DU CHOIX
  Lecran.PrintL("Choix?");
  // + clignotement LED
  delay(1500);
  Lecran.PrintL("1 - Manger?");
  // + clignotement LED

  delay(1500);
  Lecran.PrintL("2 - Jouer?");
  // + clignotement LED

  delay(1500);





  //ATTENTE
  //LEnceinte.playMelody(attente);


  //DISTRIBUTION
  MOTOR_rotor.move2pos(mr_large_recup);  //recup
  MOTOR_lock.move2pos(ml_pos_unlock);
  MOTOR_rotor.move2pos(mr_large_give);  //distrib
  MOTOR_lock.move2pos(ml_pos_lock);


  //JEU
  //LEnceinte.playMelody(Jojo);

  //recup 1 MMs
  MOTOR_rotor.move2pos(mr_little_recup);  //recup
  MOTOR_lock.move2pos(ml_pos_unlock);
  delay(1000);
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
  Banc.display(choixcouleur);

  Banc.display(choixcouleur);
  //choix
}
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
vector<int> tabint1 = { 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow };
vector<int> tabint2 = { CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE };
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
  LEnceinte.playMelody(START);
  Banc.display(tabint1);
  delay(1000);
  Banc.display(tabint2);
  delay(1000);
  // ajouter clignotement banc de LED
  Lecran.PrintL("Bienvenue !");
}

char resp = 'M';

void loop() {
  Banc.display(tabint1);
  Lecran.setColor(255, 255, 0);
  //MENU DU CHOIX
  do {
    resp = 'M';
    Lecran.Clear();
    Lecran.PrintL("Choix 1 :");
    // + clignotement LED
    Lecran.PrintL("Manger?");
    // + clignotement LED
    delay(1500);
    Lecran.Clear();
    Lecran.PrintL("Choix 2 :");
    Lecran.PrintL("Jouer?");
    // + clignotement LED
    delay(1500);
    Lecran.Clear();
    Lecran.PrintL("Choix 3 :");
    Lecran.PrintL("Jouer2?");
    // + clignotement LED
    delay(1500);
    Lecran.Clear();
    Lecran.PrintL("Alors?");
    resp = Clavier.WaitForEntry(1000);
    Serial.print("resp:");
    Serial.println(resp);
  } while ((resp != 'Q') && (resp != '1') && (resp != '2') && (resp != '3'));
  delay(2000);
  switch (resp) {
    case '1':
      //DISTRIBUTION
      Lecran.Clear();
      Lecran.PrintL("Distribution en cours...");

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
      LEnceinte.playMelody(JOJO);
      delay(5000);

      break;
    case '2':
      Serial.println("2222");
      Distribution(Lecran, MOTOR_rotor, MOTOR_lock, LEnceinte, Banc);
      
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


    case '3':
      int nombre_a_deviner;
      int nombre_essais = 3;
      Banc.setLEDs(CRGB::Grey);
      while (nombre_essais != 0) {
        randomSeed(analogRead(0));         // Initialise la fonction de nombre aléatoire avec une valeur aléatoire
        nombre_a_deviner = random(0, 10);  // Choisi un nombre aléatoire entre 1 et 10
        int nombre_devine;
        Lecran.Clear();
        Lecran.PrintL("Essai ");
        Lecran.PrintL(4 - nombre_essais);  // Affiche le numéro d'essai en cours
        Lecran.PrintL(": ");

        char resp;
        //LECTURE PAR PAD
        do {
          resp = Clavier.WaitForEntry(1000);
        } while ((resp != '0') && (resp != '1') && (resp != '2') && (resp != '3') && (resp != '4') && (resp != '5') && (resp != '6') && (resp != '7') && (resp != '8') && (resp != '9'));
        delay(5000);
        nombre_devine = (int)resp;  // Lit le nombre entré par l'utilisateur
        nombre_devine -= 48;
        if (nombre_devine == nombre_a_deviner) {  // Si le nombre est correct
          //WIN
          Lecran.setColor(0, 255, 0);
          LEnceinte.playMelody(WINNER);
          //LED VERT
          //distribution
          break;
        } else {
          Lecran.setColor(255, 0, 0);
          Lecran.Clear();
          LEnceinte.playMelody(LOSER);
          Lecran.PrintL("FAUX :  ");
          //LE NOMBRE A DEVINER EST PLUS GRAND
          //mi
          Banc.setLED(nombre_devine,CRGB::Red);
          if (nombre_devine < nombre_a_deviner) {
            Lecran.Line(2);
            Lecran.PrintL("\ntrop petit");
          } else {  // Si le nombre est plus grand
            Lecran.Line(2);
            Lecran.PrintL("\ntrop grand");
            //LE NOMBRE A DEVINER EST PLUS PETIT
          }
          Lecran.Line(1);
        }
        nombre_essais--;
        delay(5000);
      }
      Lecran.Clear();
      Lecran.PrintL("PERDU !!!");
      //LED ROUGE SAUF LA VRAIE
      for (int i = 0 ; i < 10 ; i++){
         Banc.setLED(nombre_a_deviner,CRGB::Orange);
         delay(400);
      }
     
      for (int i = 0 ; i < 3 ; i++){
        LEnceinte.playMelody(Loser);
        delay(400);
      }
      delay(5000);
      break;
  }
}

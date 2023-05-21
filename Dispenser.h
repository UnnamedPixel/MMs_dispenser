#ifndef DISPENSER_H
#define DISPENSER_H

#include "Display.h"
#include "Keypad.h"
#include <FASTLED.h>
#include "BLED.h"

#include "Motor.h"

#include "Speaker.h"

#include "Melodies.h"

#include "Melody.h"

#define ml_pos_lock 40  //OK   //position de repos qui bloque les MMs


#define mr_pos_large_recup 180   //OK
#define mr_pos_large_distr 0     //OK
#define mr_pos_little_distr 180  //OK

#define ml_pos_unlock 180  //position de repos qui debloque les MMs



template<uint8_t PINM1, uint8_t PINM2, uint8_t PINBLED>
void Dispenser_setup(Display& Lecran, Motor<PINM1>& MOTOR_rotor, Motor<PINM2>& MOTOR_lock, Speaker& LEnceinte, BLED<PINBLED>& Banc, Keypad& Clavier) {
  Banc.setup();
  MOTOR_rotor.setup();
  MOTOR_lock.setup();
  LEnceinte.setup();
  Lecran.setup();
  Clavier.setup();
}


template<uint8_t PINM1, uint8_t PINM2, uint8_t PINBLED>
void Distribution(Display& Lecran, Motor<PINM1>& MOTOR_rotor, Motor<PINM2>& MOTOR_lock, Speaker& LEnceinte, BLED<PINBLED>& Banc) {
  Banc.setLEDs(0xEE82EE);
  //DISTRIBUTION
  delay(5000);
  Lecran.Clear();
  Lecran.PrintL("Distribution...");
  Banc.setLED(0, CRGB::Red);



  Serial.println("1111");
  MOTOR_lock.move2pos(ml_pos_lock);

  MOTOR_rotor.move2pos(mr_pos_large_recup);  //recup
  Serial.println("prep distrib OK");
  delay(1000);
  Banc.setLED(1, CRGB::Red);

  delay(1000);
  Banc.setLED(2, CRGB::Red);

  MOTOR_lock.move2pos(ml_pos_unlock);
  Serial.println("unlock OK");

  //TREMBLEMENTS
  delay(1000);
  Banc.setLED(3, CRGB::Red);


  Serial.println("debut tremblements");
  MOTOR_lock.move2pos(0);
  delay(1000);
  Banc.setLED(4, CRGB::Red);

  MOTOR_lock.move2pos(ml_pos_unlock);
  delay(1000);
  Banc.setLED(5, CRGB::Red);

  MOTOR_lock.move2pos(0);
  delay(1000);
  Banc.setLED(6, CRGB::Red);
  delay(100);

  MOTOR_lock.move2pos(ml_pos_unlock);
  Serial.println("fin tremblements");
  delay(1000);
  Banc.setLED(7, CRGB::Red);
  //FIN TREMBLEMENTS
  MOTOR_lock.move2pos(ml_pos_lock);
  delay(1000);
  Banc.setLED(8, CRGB::Red);

  //ESSAI
  MOTOR_rotor.move2pos(mr_pos_large_distr);
  delay(1500);
  MOTOR_rotor.move2pos(mr_pos_large_distr + 20);
  delay(200);
  MOTOR_rotor.move2pos(mr_pos_large_distr);
  delay(200);
  MOTOR_rotor.move2pos(mr_pos_large_distr + 20);
  delay(200);

  MOTOR_rotor.move2pos(mr_pos_large_distr);
  Serial.println("distrib OK");
  Lecran.Clear();
  Banc.setLED(9, CRGB::Red);
  Banc.setLED(10, CRGB::Red);
  Lecran.PrintL("Bon appetit !");
  LEnceinte.playMelody(shortJOJO);
  delay(5000);
}


template<uint8_t PINM1, uint8_t PINM2, uint8_t PINBLED>
void Game_Number_guess(Display& Lecran, Motor<PINM1>& MOTOR_rotor, Motor<PINM2>& MOTOR_lock, Speaker& LEnceinte, BLED<PINBLED>& Banc, Keypad& Clavier) {
  int nombre_essais = 3;
  int nombre_devine;
  int nombre_a_deviner;
  nombre_essais = 3;
  bool gagne = false;
  Banc.setLEDs(CRGB::Grey);
  randomSeed(analogRead(0));         // Initialise la fonction de nombre aléatoire avec une valeur aléatoire
  nombre_a_deviner = random(0, 10);  // Choisi un nombre aléatoire entre 1 et 10
  Serial.print("A DEVINER:");
  Serial.print(nombre_a_deviner);
  while (nombre_essais != 0) {
    Lecran.Clear();
    Lecran.PrintL("Essai ");
    Lecran.PrintL(4 - nombre_essais);  // Affiche le numéro d'essai en cours
    Lecran.PrintL(": ");
    char resp;
    //LECTURE PAR PAD
    do {
      resp = Clavier.WaitForEntry(1000);
    } while ((resp != '0') && (resp != '1') && (resp != '2') && (resp != '3') && (resp != '4') && (resp != '5') && (resp != '6') && (resp != '7') && (resp != '8') && (resp != '9'));
    delay(1500);
    nombre_devine = (int)resp;  // Lit le nombre entré par l'utilisateur
    nombre_devine -= 48;
    Serial.print("essai sur nb :");
    Serial.print(nombre_devine);
    if (nombre_devine == nombre_a_deviner) {  // Si le nombre est correct
      //WIN
      Lecran.setColor(0, 255, 0);
      Lecran.lcd.blinkLED();
      Lecran.Clear();
      Lecran.PrintL("BRAVO !!!!!!");
      LEnceinte.playMelody(WINNER);

      Distribution(Lecran, MOTOR_rotor, MOTOR_lock, LEnceinte, Banc);

      gagne = true;
      Lecran.lcd.noBlinkLED();

      break;
    } else {
      Lecran.setColor(255, 0, 0);
      Lecran.Clear();
      LEnceinte.playMelody(LOSER);
      Lecran.PrintL("FAUX :  ");
      //LE NOMBRE A DEVINER EST PLUS GRAND
      //mi
      Banc.setLED(nombre_devine - 1, CRGB::Red);
      if (nombre_devine < nombre_a_deviner) {
        Lecran.Line(2);
        Lecran.PrintL("trop petit");
      } else {  // Si le nombre est plus grand
        Lecran.Line(2);
        Lecran.PrintL("trop grand");
        //LE NOMBRE A DEVINER EST PLUS PETIT
      }
      Lecran.Line(1);
    }
    nombre_essais--;
    delay(1500);
  }
  if (gagne == false) {
    Lecran.Clear();
    Lecran.PrintL("PERDU !!!");
    //LED ROUGE SAUF LA VRAIE
    for (int i = 0; i < 10; i++) {
      Banc.setLED(nombre_a_deviner - 1, CRGB::Orange);
      delay(400);
    }

    Lecran.lcd.blinkLED();
    for (int i = 0; i < 3; i++) {
      LEnceinte.playMelody(Loser);
      Banc.setLED(nombre_a_deviner - 1, CRGB::Orange);
      delay(250);
      Banc.setLED(nombre_a_deviner - 1, 0);
      delay(250);
    }
    Lecran.lcd.noBlinkLED();

    delay(5000);
  }
}

template<uint8_t PINM1, uint8_t PINM2, uint8_t PINBLED>
void Game_Color_guess(Display& Lecran, Motor<PINM1>& MOTOR_rotor, Motor<PINM2>& MOTOR_lock, Speaker& LEnceinte, BLED<PINBLED>& Banc, Keypad& Clavier) {
  Banc.setLEDs(CRGB::Red);
  Serial.print("22222");
  Lecran.Clear();
  Lecran.PrintL("Desole");
  Lecran.Line(2);
  Lecran.PrintL("Jeu HS :c");
  Lecran.Line(1);
  delay(5000);
};

template<uint8_t PINM1, uint8_t PINM2, uint8_t PINBLED>
extern void Dispenser_start(Display& Lecran, Motor<PINM1>& MOTOR_rotor, Motor<PINM2>& MOTOR_lock, Speaker& LEnceinte, BLED<PINBLED>& Banc, Keypad& Clavier) {
  vector<int> tabint1 = { 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow };
  vector<int> tabint2 = { CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE, CRGB::Yellow, 0xEE82EE };
  vector<int> choixcouleur = { CRGB::Yellow, CRGB::Orange, CRGB::Blue, CRGB::Green, CRGB::Brown, CRGB::Red, 0, 0, 0, 0 };
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


template<uint8_t PINM1, uint8_t PINM2, uint8_t PINBLED>
extern void Game_Color_guess(Display& Lecran, Motor<PINM1>& MOTOR_rotor, Motor<PINM2>& MOTOR_lock, Speaker& LEnceinte, BLED<PINBLED>& Banc, Keypad& Clavier);

template<uint8_t PINM1, uint8_t PINM2, uint8_t PINBLED>
extern void Game_Number_guess(Display& Lecran, Motor<PINM1>& MOTOR_rotor, Motor<PINM2>& MOTOR_lock, Speaker& LEnceinte, BLED<PINBLED>& Banc, Keypad& Clavier);

template<uint8_t PINM1, uint8_t PINM2, uint8_t PINBLED>
extern void Distribution(Display& Lecran, Motor<PINM1>& MOTOR_rotor, Motor<PINM2>& MOTOR_lock, Speaker& LEnceinte, BLED<PINBLED>& Banc);

template<uint8_t PINM1, uint8_t PINM2, uint8_t PINBLED>
extern void Dispenser_setup(Display& Lecran, Motor<PINM1>& MOTOR_rotor, Motor<PINM2>& MOTOR_lock, Speaker& LEnceinte, BLED<PINBLED>& Banc, Keypad& Clavier);

template<uint8_t PINM1, uint8_t PINM2, uint8_t PINBLED>
extern void Dispenser_start(Display& Lecran, Motor<PINM1>& MOTOR_rotor, Motor<PINM2>& MOTOR_lock, Speaker& LEnceinte, BLED<PINBLED>& Banc, Keypad& Clavier);

#endif
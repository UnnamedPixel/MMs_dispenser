#ifndef DISPENSER_H
#define DISPENSER_H

#include "Display.h"

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
void Distribution(Display Lecran, Motor<PINM1> MOTOR_rotor, Motor<PINM2> MOTOR_lock, Speaker LEnceinte, BLED<PINBLED> Banc) {
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

  MOTOR_rotor.move2pos(mr_pos_large_distr);
  Serial.println("distrib OK");
  Lecran.Clear();
  Banc.setLED(9, CRGB::Red);
  Banc.setLED(10, CRGB::Red);
  Lecran.PrintL("Bon appetit !");
  LEnceinte.playMelody(shortJOJO);
}

template<uint8_t PINM1, uint8_t PINM2, uint8_t PINBLED>
extern void Distribution(Display Lecran, Motor<PINM1> MOTOR_rotor, Motor<PINM2> MOTOR_lock, Speaker LEnceinte, BLED<PINBLED> Banc);


#endif
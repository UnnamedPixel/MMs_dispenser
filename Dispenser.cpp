#include "Dispenser.h"

/*
template <uint8_t PINM1, uint8_t PINM2,uint8_t PINBLED>
void Distribution(Display Lecran, const Motor<PINM1> &  MOTOR_rotor, const Motor<PINM2> & MOTOR_lock, Speaker LEnceinte, BLED<PINBLED> Banc) {
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
}*/
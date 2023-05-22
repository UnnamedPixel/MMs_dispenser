#ifndef SPEAKER_H
#define SPEAKER_H

#include "Driver.h"
#import <Arduino.h>
#include "Melody.h"

class Speaker : protected Driver {
public:
  // Constructeur de la classe Speaker avec un argument "nport" pour le numéro du port
  Speaker(int nport);

  // Effectue la configuration initiale du haut-parleur
  void setup();

  // Joue une tonalité de fréquence spécifiée
  void playTone(int freq);

  // Joue une tonalité de fréquence spécifiée pendant une durée spécifiée
  void playTone(int freq, int duration);

  // Joue une mélodie composée de notes et de durées spécifiées
  void playMelody(int nbNotes, int *Notes, int *NotesDuration);

  // Joue une mélodie avec des notes et des durées spécifiées, en utilisant un délai fixe après chaque note
  void playMelody(int nbNotes, int *Notes, int *NotesDuration, int fixedDelay);

  // Joue une mélodie avec des notes, des durées spécifiées et des délais spécifiques après chaque note
  void playMelody(int nbNotes, int *Notes, int *NotesDuration, int *DelayAfterNoteI);

  // Joue une mélodie spécifiée par un objet Melody contenant des notes, des durées et des délais
  void playMelody(Melody &theMelody);
};

#endif
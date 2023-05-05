#ifndef SPEAKER_H
#define SPEAKER_H

#include "Actuator.h"
#import <Arduino.h>
#include "Melody.h"

class Speaker : protected Actuator {
  public:
  Speaker(int nport);
  void setup();
  void playTone(int freq);
  void playTone(int freq, int duration);

  void playMelody(int nbNotes, int * Notes, int * NotesDuration);
  void playMelody(int nbNotes, int * Notes, int * NotesDuration, int fixedDelay);
  void playMelody(int nbNotes, int * Notes, int * NotesDuration, int * DelayAfterNoteI);
  void playMelody(Melody & theMelody);
};


#endif
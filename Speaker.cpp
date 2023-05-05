#include "speaker.h"

Speaker::Speaker(int nport):Actuator(nport){};


void Speaker::setup(){pinMode(nport,OUTPUT);}

void Speaker::playTone(int freq){tone(nport,freq);}
void Speaker::playTone(int freq, int duration){
  tone(nport,freq,duration);
  }

void Speaker::playMelody(int nbNotes, int * Notes, int * NotesDuration){
  for (int i = 0 ; i < nbNotes ; i ++){
    this->playTone(Notes[i],NotesDuration[i]);
    delay(NotesDuration[i]*1.3);
  }
};

void Speaker::playMelody(int nbNotes, int * Notes, int * NotesDuration, int fixedDelay){
  for (int i = 0 ; i < nbNotes ; i ++){
    this->playTone(Notes[i],NotesDuration[i]);
    delay(fixedDelay);
  }
};

void Speaker::playMelody(int nbNotes, int * Notes, int * NotesDuration, int * DelayAfterNoteI){
    for (int i = 0 ; i < nbNotes ; i ++){
    this->playTone(Notes[i],NotesDuration[i]);
    delay(DelayAfterNoteI[i]);
  }
};

void Speaker::playMelody(Melody & theMelody){
    for (int i = 0 ; i < theMelody.nbNotes ; i ++){
    this->playTone(theMelody.Notes[i],theMelody.NotesDuration[i]);
    delay(theMelody.DelayAfterNotes[i]);
  }

};
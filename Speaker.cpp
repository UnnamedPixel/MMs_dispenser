#include "speaker.h"

Speaker::Speaker(int nport):Driver(nport){};


void Speaker::setup(){pinMode(nport,OUTPUT);}  // Définit le mode de la broche du haut-parleur en mode sortie

void Speaker::playTone(int freq){tone(nport,freq);}  // Joue une tonalité de fréquence spécifiée

void Speaker::playTone(int freq, int duration){
  tone(nport,freq,duration);  // Joue une tonalité de fréquence spécifiée pendant une durée spécifiée
}

void Speaker::playMelody(int nbNotes, int * Notes, int * NotesDuration){
  for (int i = 0 ; i < nbNotes ; i ++){
    this->playTone(Notes[i],NotesDuration[i]);  // Joue chaque note de la mélodie avec sa durée correspondante
    delay(NotesDuration[i]*1.3);  // Attend un court instant après chaque note
  }
};

void Speaker::playMelody(int nbNotes, int * Notes, int * NotesDuration, int fixedDelay){
  for (int i = 0 ; i < nbNotes ; i ++){
    this->playTone(Notes[i],NotesDuration[i]);  // Joue chaque note de la mélodie avec sa durée correspondante
    delay(fixedDelay);  // Attend un délai fixe après chaque note
  }
};

void Speaker::playMelody(int nbNotes, int * Notes, int * NotesDuration, int * DelayAfterNoteI){
    for (int i = 0 ; i < nbNotes ; i ++){
    this->playTone(Notes[i],NotesDuration[i]);  // Joue chaque note de la mélodie avec sa durée correspondante
    delay(DelayAfterNoteI[i]);  // Attend un délai spécifique après chaque note
  }
};

void Speaker::playMelody(Melody & theMelody){
    for (int i = 0 ; i < theMelody.nbNotes ; i ++){
    this->playTone(theMelody.Notes[i],theMelody.NotesDuration[i]);  // Joue chaque note de la mélodie avec sa durée correspondante
    delay(theMelody.DelayAfterNotes[i]);  // Attend un délai spécifique après chaque note
  }
};

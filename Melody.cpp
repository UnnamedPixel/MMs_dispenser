#include "Melody.h"

// Constructeur avec des notes, des durées et des délais spécifiés
Melody::Melody(int nbN, int* N, int* NDuration) {
  this->Notes = new int[nbN];
  this->NotesDuration = new int[nbN];
  this->DelayAfterNotes = new int[nbN];
  
  // Copie des valeurs spécifiées dans les tableaux membres
  for (int i = 0; i < nbN; i++) {
    this->Notes[i] = N[i];
    this->NotesDuration[i] = NDuration[i];
    this->DelayAfterNotes[i] = NDuration[i] * 0.1;
  }
  
  this->nbNotes = nbN;
}

// Constructeur avec des notes, des durées et des délais spécifiés
Melody::Melody(int nbN, int* N, int* NDuration, int* DelayAfterN) {
  this->nbNotes = nbN;
  this->Notes = new int[nbN];
  this->NotesDuration = new int[nbN];
  this->DelayAfterNotes = new int[nbN];
  
  // Copie des valeurs spécifiées dans les tableaux membres
  for (int i = 0; i < nbN; i++) {
    this->Notes[i] = N[i];
    this->NotesDuration[i] = NDuration[i];
    this->DelayAfterNotes[i] = DelayAfterN[i];
  }
}

// Constructeur avec des notes, une durée fixe et un délai fixe spécifiés
Melody::Melody(int nbN, int* N, int NDuration, int DelayAfterN) {
  this->nbNotes = nbN;
  this->Notes = new int[nbN];
  this->NotesDuration = new int[nbN];
  this->DelayAfterNotes = new int[nbN];
  
  // Copie des valeurs spécifiées dans les tableaux membres
  for (int i = 0; i < nbN; i++) {
    this->Notes[i] = N[i];
    this->NotesDuration[i] = NDuration;
    this->DelayAfterNotes[i] = DelayAfterN;
  }
}

// Constructeur avec des notes, une durée fixe et des délais spécifiés pour chaque note
Melody::Melody(int nbN, int* N, int NDuration, int* DelayAfterN) {
  this->nbNotes = nbN;
  this->Notes = new int[nbN];
  this->NotesDuration = new int[nbN];
  this->DelayAfterNotes = new int[nbN];
  
  // Copie des valeurs spécifiées dans les tableaux membres
  for (int i = 0; i < nbN; i++) {
    this->Notes[i] = N[i];
    this->NotesDuration[i] = NDuration;
    this->DelayAfterNotes[i] = DelayAfterN[i];
  }
}

// Constructeur avec des notes, des durées spécifiées et un délai fixe
Melody::Melody(int nbN, int* N, int* NDuration, int DelayAfterN) {
  this->nbNotes = nbN;
  this->Notes = new int[nbN];
  this->NotesDuration = new int[nbN];
  this->DelayAfterNotes = new int[nbN];
  
  // Copie des valeurs spécifiées dans les tableaux membres
  for (int i = 0; i < nbN; i++) {
    this->Notes[i] = N[i];
    this->NotesDuration[i] = NDuration[i];
    this->DelayAfterNotes[i] = DelayAfterN;
  }
}

// Destructeur de la classe Melody
Melody::~Melody() {
  delete[] Notes;
  delete[] NotesDuration;
  delete[] DelayAfterNotes;
}

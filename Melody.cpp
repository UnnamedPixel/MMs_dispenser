#include "Melody.h"

Melody::Melody(int nbN, int* N, int* NDuration) {
  this->Notes = new int[nbN];
  this->NotesDuration = new int[nbN];
  this->DelayAfterNotes = new int[nbN];
    for (int i = 0; i < nbN; i++) {
    this->Notes[i] = N[i];
    this->NotesDuration[i] = NDuration[i];
    this->DelayAfterNotes[i] = 100;
  }
  this->nbNotes = nbN;
};

Melody::Melody(int nbN, int* N, int* NDuration, int* DelayAfterN) {
  this->nbNotes = nbN;
  this->Notes = new int[nbN];
  this->NotesDuration = new int[nbN];
  this->DelayAfterNotes = new int[nbN];
  for (int i = 0; i < nbN; i++) {
    this->Notes[i] = N[i];
    this->NotesDuration[i] = NDuration[i];
    this->DelayAfterNotes[i] = DelayAfterN[i];
  }
};

Melody::~Melody() {
  delete[] Notes;
  delete[] NotesDuration;
  delete[] DelayAfterNotes;
}
#ifndef MELODY_H
#define MELODY_H

//#include "Notes.h"


class Melody {
public:
  int nbNotes;
  int* Notes;
  int* NotesDuration;
  int* DelayAfterNotes;

  Melody(int nbN, int* N, int* NDuration);
  Melody(int nbN, int* N, int* NDuration, int* DelayAfterN);
  Melody(int nbN, int* N, int* NDuration, int DelayAfterN);
  Melody(int nbN, int* N, int NDuration, int* DelayAfterN);
  Melody(int nbN, int* N, int NDuration, int DelayAfterN);

  ~Melody();
};


#endif
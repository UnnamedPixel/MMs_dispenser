// Ce fichier contient la classe Melody qui représente une mélodie pour le distributeur de M&Ms.

#ifndef MELODY_H
#define MELODY_H

class Melody {
public:
  int nbNotes; // Nombre de notes dans la mélodie
  int* Notes; // Tableau des notes
  int* NotesDuration; // Tableau des durées des notes
  int* DelayAfterNotes; // Tableau des délais après chaque note

  // Constructeurs
  Melody(int nbN, int* N, int* NDuration);
  Melody(int nbN, int* N, int* NDuration, int* DelayAfterN);
  Melody(int nbN, int* N, int* NDuration, int DelayAfterN);
  Melody(int nbN, int* N, int NDuration, int* DelayAfterN);
  Melody(int nbN, int* N, int NDuration, int DelayAfterN);

  // Destructeur
  ~Melody();
};

#endif
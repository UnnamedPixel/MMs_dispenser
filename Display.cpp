#include "Display.h"

Display::Display(int n)
  : Driver(n), lcd() {
}

void Display::setup() {
  lcd.begin(16, 2);       // Initialiser l'écran avec 16 colonnes et 2 lignes
  lcd.setRGB(255, 255, 0);  // Régler la couleur d'arrière-plan à jaune
}

void Display::setColor(int R, int G, int B){
  lcd.setRGB(R,G,B);  // Définir la couleur RGB de l'écran
}

void Display::Print(String mess, int t) {
  lcd.print((const String)mess);  // Afficher le message "mess" à l'écran
  delay(t);  // Attendre pendant la durée spécifiée
  lcd.clear();  // Effacer le contenu de l'écran
}

void Display::PrintL(String mess) {
  lcd.print((const String)mess);  // Afficher le message "mess" à l'écran
}

void Display::PrintL(int mess) {
  lcd.print(mess);  // Afficher le message "mess" à l'écran
}

void Display::Clear(){
  lcd.clear();  // Effacer le contenu de l'écran
}

void Display::Line(int line){
  lcd.setCursor(0, line);  // Déplacer le curseur à la position spécifiée sur la ligne spécifiée
}

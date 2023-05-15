
#include "Display.h"

Display::Display(int n)
  : Driver(n), lcd() {
}

void Display::setup() {
  lcd.begin(16, 2);       // initialiser l'écran avec 16 colonnes et 2 lignes
  lcd.setRGB(255, 255, 0);  // régler la couleur d'arrière-plan à jaune
}

void Display::setColor(int R, int G, int B){
  lcd.setRGB(R,G,B);
}

void Display::Print(String mess, int t) {
  lcd.print((const String)mess);  // afficher le message mess on the screen
  delay(t);
  lcd.clear();
}

void Display::PrintL(String mess) {
  lcd.print((const String)mess);  // afficher le message mess on the screen
}

void Display::PrintL(int mess) {
  lcd.print(mess);  // afficher le message mess on the screen
}
void Display::Clear(){
  lcd.clear();
}

void Display::Line(int line){
  lcd.setCursor(0, line);
}

#include "Display.h"
 
Display::Display(int n):Driver(n),lcd(){
}

void Display::setup(){
    lcd.begin(16, 2); // initialiser l'écran avec 16 colonnes et 2 lignes
    lcd.setRGB(255, 0, 0); // régler la couleur d'arrière-plan à rouge
}
void Display::Print(String mess, int t)
{
    lcd.print((const String)mess); // afficher le message "Bonjour!" sur l'écran
    delay(t);
    lcd.clear();
}

int Display::getINOUT(){return -1;}

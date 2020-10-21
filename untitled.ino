#include <Arduino.h>
int ledPin = 3;                     //pin de la led
String inputString = "";            // les caracteres transmis
boolean stringComplete = false;     // la chaine complète
int arduinoledState=0;              // led on ou off

void setup() {
    Serial.begin(9600);               //debute la communication serie à 9600 bauds
    pinMode(ledPin,OUTPUT);           // pin en mode sortie
}

void loop() {

    while (Serial.available()) {
        char inChar = (char)Serial.read();  // lecture octet par octet stockage dans un char:
        inputString += inChar;              // ajout dans la chaine provisoire
        if (inChar == '\n') {               // si retour)à la ligne
            stringComplete = true;          // la chaine est complète
            break;                          //casse la boucle
        }
    }

    if (stringComplete){                    // si la chaine est complète
        stringComplete = false;
        if (inputString == "ON\n")
            arduinoledState = 1;            // tounne la led on
        else if (inputString=="OFF\n")

            arduinoledState=0;              // tourne la led off
        inputString = "";               // efface la chaine temporaire

    }

    digitalWrite(ledPin, arduinoledState);                 // ecrit la valeur sur la carte

}
  /**************/
 /** INCLUDES **/
/**************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <TMRpcm.h>
#include <SD.h>
#include <SPI.h>

  /***************/
 /** CONSTANTS **/
/***************/

const int CS_PIN = 4;
const int SPEAKER_PIN = 9;

  /***************/
 /** VARIABLES **/
/***************/

TMRpcm speaker;

//=======================================================================================================================================================

  /****************/
 /** Prototypes **/
/****************/

void log(String text);

//=======================================================================================================================================================

  /***********/
 /** SETUP **/
/***********/

void setup(){  
  //===== SERIAL =====
  
  Serial.begin(9600);       //Start serial communication

  //===== SPEAKER =====
  
  //pinMode(SPEAKER_PIN,OUTPUT);
  //digitalWrite(SPEAKER_PIN,LOW);
  
  //===== Carte SD =====

  speaker.speakerPin = SPEAKER_PIN;
  
  if (!SD.begin(CS_PIN)){
    log("SD fail");
    return;
  }
  else {
    log("SD ok");
    speaker.setVolume(4);
    speaker.loop(1);
    speaker.play("A.wav");
  }
}

  /***********/
 /** LOOP ***/
/***********/

void loop()
{
  //Attend que quelqu'un monte sur la balance
  //Modifie l'affichage
  //Choisi un fichier à jouer
}

//=======================================================================================================================================================

  /*************/
 /** DISPLAY **/
/**************/

//Display 4 characters on the screen for a known time in ms
void display(char A, char B, char C, char D, boolean Point1, boolean Point2, int timeOut){

  A = char2segements(A);
  B = char2segements(B);
  C = char2segements(C);
  D = char2segements(D);

  for(int i=0;i<timeOut/16;i++){
    //Attente du premier front montant;
    //Envoyer A
    delay(4);
    //Envoyer B
    delay(4);
    //Envoyer C
    delay(4);
    //Envoyer D
  }  
}

//Convert a character to 7 segments display + point
char char2segements(char character){
  //    1 byte =(7)(6)(5)(4)(3)(2)(1)(0)
  //    On = 0 / Off = 1
  //       _______
  //      |   0   |
  //    3 |       | 2
  //      |_______|
  //      |   4   |
  //    5 |       | 6
  //      |_______|   1
  //          7       *
  switch(character){
    case 'A'|'a': return 0b01111101;
    case 'B'|'b': return 0b11111000;
    case 'c': return 0b10110000;
    case 'C': return 0b10101001;
    case 'D'|'d': return 0b11110100;
    case 'E'|'e': return 0b10111001;
    case 'F'|'f': return 0b00111001;
    case 'G'|'g'|'9': return 0b11011101;
    case 'h': return 0b01111000;
    case 'H': return 0b01111100;
    case 'i': return 0b00100000;
    case 'I': return 0b00101000;
    case 'j': return 0b11000000;
    case 'J': return 0b11100100;
    case 'L'|'l': return 0b10101000;
    case 'M'|'m': return 0b01101101;
    case 'N'|'n': return 0b01110000;
    case 'O'|'o': return 0b11110000;
    case 'P'|'p': return 0b00111101;
    case 'Q'|'q': return 0b01011101;
    case 'R'|'r': return 0b00110000;
    case 'S'|'s'|'5': return 0b11011001;
    case 'T'|'t': return 0b10111000;
    case 'u': return 0b11100000;
    case 'U': return 0b11101100;
    case '0': return 0b11101101;
    case '1': return 0b01000100;
    case '2': return 0b10110101;
    case '3': return 0b11010101;
    case '4': return 0b01011100;
    case '6': return 0b11111001;
    case '7': return 0b01000101;
    case '8': return 0b11111111;
    default: return 0b10000000;
  }
}

//=======================================================================================================================================================

  /*********/
 /** LOG **/
/*********/

//Print a log on the terminal
void log(String text){
  Serial.println(text); //Log via serial
}


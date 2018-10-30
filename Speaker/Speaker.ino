  /**************/
 /** INCLUDES **/
/**************/

#include <stdio.h>
#include <stdlib.h>

  /***************/
 /** CONSTANTS **/
/***************/

int SPEAKER_PIN = 9;

  /***************/
 /** VARIABLES **/
/***************/

int BassTab[]={1911,1702,1516,1431,1275,1136,1012};

//=======================================================================================================================================================

  /****************/
 /** Prototypes **/
/****************/

void sound(uint8_t note_index);
void log(String text);

//=======================================================================================================================================================

  /***********/
 /** SETUP **/
/***********/

void setup(){
  //===== SERIAL =====
  
  Serial.begin(115200);       //Start serial communication

  //===== SPEAKER =====
  
  pinMode(SPEAKER_PIN,OUTPUT);
  digitalWrite(SPEAKER_PIN,LOW);
}

  /***********/
 /** LOOP ***/
/***********/

void loop()
{
  for(int note_index=0;note_index<7;note_index++){
    sound(note_index);
    delay(500);
  }
}

//=======================================================================================================================================================

  /***********/
 /** SOUND **/
/***********/

void sound(uint8_t note_index)
{
    for(int i=0;i<100;i++)
    {
        digitalWrite(SPEAKER_PIN,HIGH);
        delayMicroseconds(BassTab[note_index]);
        digitalWrite(SPEAKER_PIN,LOW);
        delayMicroseconds(BassTab[note_index]);
    }
}

//=======================================================================================================================================================

  /*********/
 /** LOG **/
/*********/

//Print a log on the terminal
void log(String text){
  Serial.print(text); //Log via serial
}

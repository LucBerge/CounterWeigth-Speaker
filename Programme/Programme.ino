  /************/
 /* INCLUDES */
/************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <TMRpcm.h>
#include <SD.h>
#include <SPI.h>

  /*************/
 /* CONSTANTS */
/*************/

//#define SPEAKER 18
int CS_PIN = 10;
int SPEAKER_PIN = A5;

  /*************/
 /* VARIABLES */
/*************/

TMRpcm tmrcpm;

//=======================================================================================================================================================

  /**********************/
 /***** Prototypes *****/
/**********************/

void sound(uint8_t note_index);
void log(String text);

//=======================================================================================================================================================

  /*****************/
 /***** SETUP *****/
/*****************/

void setup()
{
  //===== PIN =====
  
  pinMode(SPEAKER_PIN,OUTPUT);
  
  //===== SERIAL =====
  
  Serial.begin(115200);       //Start serial communication

  //===== SPEAKER =====
  
  digitalWrite(SPEAKER_PIN,LOW);
  
  //===== Carte SD =====

  tmrpcm.speakerPin = SPEAKER_PIN;
  
  if (!SD.begin(CHIP_SELECT_PIN))
    log("SD fail");
  else {
    tmrpcm.play( "ton.wav" );
    delay(5);
  }
}

  /*****************/
 /***** LOOP ******/
/*****************/

void loop()
{
  for(unsigned int frequency=100;frequency<20000;frequency++)
  {
    //tone(SPEAKER,frequency,500);
    //delay(500);
  }
}

  /************************/
 /***** Log function *****/
/************************/

void log(String text) //Log function
{
  Serial.print(text); //Log via serial
}

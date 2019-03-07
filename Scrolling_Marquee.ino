// Use the Parola library to scroll text on the display
//
// Demonstrates the use of the scrolling function to display text 
// Scrolling direction is controlled by a switch on DIRECTION_SET digital in.
// Invert ON/OFF is set by a switch on INVERT_SET digital in.
//
// MD_MAX72XX library can be found at https://github.com/MajicDesigns/MD_MAX72XX
//

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Define the number of devices we have in the chain and the hardware interface
// NOTE: Check your Hardware to see what pins are used (using H/W SPI here) your hardware may need to be adapted

#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW  //was set to PAROLA_HW //<-- THIS took way too long to find
#define MAX_DEVICES 5
#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10

// Global message buffers shared by Serial and Scrolling functions
#define  BUF_SIZE  75

// HARDWARE SPI
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

textEffect_t scrollEffect = PA_SCROLL_LEFT;
textPosition_t scrollAlign = PA_LEFT;

bool getFirstMessage = true;
bool getSecondMessage = false;

uint8_t scrollSpeed = 75;    // default frame delay value, smaller is faster
uint16_t scrollPause = 2000; // in milliseconds

//I used a var here called Timer but that isn't really what I wanted it to be used for
//I was thinking of having more than one message and cycling through each one using the 
//value of the var to cycle the message.  I only had two messages, so I used two flaggs
//but left the var in for future switch case. 
int Timer = 1; //"time" before next message
char IntroMessage[BUF_SIZE] = {" Please Take A Number "};
char FirstMessage[BUF_SIZE] = {" Now Serving --> 00001" };
char SecondMessage[BUF_SIZE] = {" Now Serving --> " };

void setup()
{
  Serial.begin(57600);//left in for debug
  Serial.println(("Here we go!"));
  P.begin();
  P.setIntensity(1);//(0-15)
  P.displayText(FirstMessage, scrollAlign, scrollSpeed, scrollPause, scrollEffect, scrollEffect);
}

void loop()
{
   if (P.displayAnimate())
   {
       getMessage(); 
       --Timer;
       P.displayReset();
   }
}

/********************************************************************************/
//  ---------Scrolling Marquee for cubical visitor optimization------------- 
//  H/W includes an Arduino Nano, several MAX7219 single color Matrix LEDs, and a  
//  TTP223B CTS.  There are four general messages cases and a fifth case that requires a 
//  Serial connection for "Alternative" user input.  There is an LED three bit case # user feedback 
//  to show which message will come next.
// 
//    SPI Connections;
//      CS_PIN    10
//      MOSI_PIN  11
//      CLK_PIN   13
//    CTS Connection;
//      DI_PIN    02
//
//    LED three bit Feedback;
//      DO1_PIN   04
//      DO2_PIN   07
//      DO3_PIN   08
//
//  Serial Connection is used for "Alternative Message" Input
//
//  Special thanks to Marco Colli for use of their libraries and http://henrysbench.capnfatz.com/ 
/********************************************************************************/
#include "Wire.h"
#include "SPI.h"
#include "MD_Parola.h"
#include "MD_MAX72xx.h"
#include "RTClib.h"
#include "SolarCalculator.h"

#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW  //was set to PAROLA_HW //<-- THIS took way too long to find
#define MAX_DEVICES 5                         //# of connected devices to set up array
#define CLK_PIN   13                          //SPI Clock pin
#define DATA_PIN  11                          //MOSI
#define CS_PIN    10                          //Chip select - these displays are "daisy chained" on one CS
#define ctsPin 2                              // Pin for capactitive touch sensor (cts)
#define  BUF_SIZE  75                         //Message Buffer

DS3231 rtc;       //DS3231 rtc support; 
 
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
textEffect_t scrollEffect = PA_SCROLL_LEFT;
textPosition_t scrollAlign = PA_LEFT;

uint8_t scrollSpeed = 25;                     // default frame delay value, smaller is faster
uint16_t scrollPause = 1500;                  // in milliseconds

bool toggle = false;                          //Used for simple "touched the button" feedback
bool newMessageAvailable = true;              //Var to set serial input logic
//added to get crap code to compile due to missing files
bool getFirstMessage = true;              //Var to set serial input logic
bool getSecondMessage = false;              //Var to set serial input logic

int Case = 0;                                 //sent ti switch case logic to set case
//added to get crap code to compile due to missing files
int Timer = 0;

String TestString;                            //Temp string to feed upcomming message

char OutputMessage[BUF_SIZE] = {" Now Serving --> 00001"};
char FirstMessage[BUF_SIZE] = {" Please Take A Number " };
//added to get crap code to compile due to missing files
char IntroMessage[BUF_SIZE] = {" Please Take A Number " };
char SecondMessage[BUF_SIZE] = {" Now Serving --> 00001"};
char newMessage[BUF_SIZE] = { "Hello! Enter new message?" };
char RandomNumber[9];
char HourinASCII[9];
char MininASCII[9];
char SecinASCII[9];

int seconds = 0;  // variable to store the seconds from clock
int minutes = 0;  // variable to store the minutes from clock
int hours   = 0;  // variable to store the hours from clock
int days    = 0;  // variable to store the seconds from clock
int months  = 0;  // variable to store the minutes from clock
int years   = 0;  // variable to store the hours from clock

int DSTSwitch_mode = 1;
int DelayPeriod = 10;           //setup for using millis() instead of delay()
unsigned long Current_Time = 0; //the "other part" of millis() (roll over around 50 days which might not work in this application)

// Location
double transit, sunrise, sunset;
double latitude = 39.7565;
double longitude = -77.966;
double HoursOLight = 0;
int utc_offset = -5;

int SunRiseHour = 0;
int SunRiseMinute = 0;
int SunSetHour = 0;
int SunSetMinute = 0;

bool DebugOn = true; //set to true for debug serial messages

void setup() 
{
  //setup output pins, this works wihout being here
  pinMode(LED_BUILTIN, OUTPUT); 
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  //setup input pins
  pinMode(ctsPin, INPUT);
  //startup serial and display
  Serial.begin(57600);        //most of the serial is for debug, I added serial input to case#5
  P.begin();
  P.setIntensity(1);//(0-15)
  P.displayText(OutputMessage, scrollAlign, scrollSpeed, scrollPause, scrollEffect, scrollEffect);
  Serial.println("initializing Scrolling Marquee 11/14/22...");
  
  //Serial.println("initializing DS3231...");
  SetupRTC();          //start the clock
  
  Serial.println("initializing Scrolling Marquee DONE. ");
}//end of void setup()
 
void loop() 
{
   getInput();
   UpdateTime();

    if (P.displayAnimate())
    {
      updateCase();
      //Serial.println(Case);
      P.displayReset();
    }
    readSerial();
}//end of void loop() 

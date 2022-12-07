# Scolling_Marquee
/********************************************************************************/
//  ---------Scrolling Marquee for cubical visitor optimization------------- 
//  H/W includes an Arduino Nano, several MAX7219 single color Matrix LEDs, and a  
//  TTP223B CTS.  There are four general messages cases and a fifth case that requires a 
//  Serial connection for "Alternative" user input.  There is an LED three bit case # user feedback 
//  to show which message will come next. * an RTC and BME280 has also been added to this project. 
//  It is hoped to display time & temp.  Later It may also be used to display sunrise and sunset.  
//  Still later pressure from the BME280 may be used to predict weather conditions 
//  (pressure rise ~= "good" weather, pressure falling ~= stormy weather)
// 
//    SPI Connections;
//      CS_PIN     --> 10
//      MOSI_PIN   --> 11
//      CLK_PIN    --> 13
//  	SCL        --> A04
//  	SDA        --> A05
//
//    CTS Connection;
//      DI_PIN     --> 02
//
//    LED three bit Feedback;
//      DO1_PIN    --> 04
//      DO2_PIN    --> 07
//      DO3_PIN    --> 08
//
//  Serial Connection is used for "Alternative Message" Input
//
/********************************************************************************/
Using library MD_Parola at version 3.6.1 in folder: D:\Github\libraries\MD_Parola 
Using library MD_MAX72XX at version 3.3.1 in folder: D:\Github\libraries\MD_MAX72XX 
Using library SPI at version 1.0 in folder: C:\Users\ut4445o\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.6\libraries\SPI 
"C:\\Users\\ut4445o\\AppData\\Local\\Arduino15\\packages\\arduino\\tools\\avr-gcc\\7.3.0-atmel3.6.1-arduino7/bin/avr-size" -A "C:\\Users\\ut4445o\\AppData\\Local\\Temp\\arduino-sketch-2EDC5685D286BC96B589E6C2DE8AC2DF/Scrolling_Marquee.ino.elf"
Sketch uses 23174 bytes (75%) of program storage space. Maximum is 30720 bytes.
Global variables use 664 bytes (32%) of dynamic memory, leaving 1384 bytes for local variables. Maximum is 2048 bytes.

Using library MD_Parola at version 3.6.1 in folder: D:\Github\libraries\MD_Parola 
Using library MD_MAX72XX at version 3.3.1 in folder: D:\Github\libraries\MD_MAX72XX 
Using library SPI at version 1.0 in folder: C:\Users\ut4445o\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.6\libraries\SPI 
Using library Wire at version 1.0 in folder: C:\Users\ut4445o\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.6\libraries\Wire 
"C:\\Users\\ut4445o\\AppData\\Local\\Arduino15\\packages\\arduino\\tools\\avr-gcc\\7.3.0-atmel3.6.1-arduino7/bin/avr-size" -A "C:\\Users\\ut4445o\\AppData\\Local\\Temp\\arduino-sketch-2EDC5685D286BC96B589E6C2DE8AC2DF/Scrolling_Marquee.ino.elf"
Sketch uses 24136 bytes (78%) of program storage space. Maximum is 30720 bytes.
Global variables use 777 bytes (37%) of dynamic memory, leaving 1271 bytes for local variables. Maximum is 2048 bytes.

Using library MD_Parola at version 3.6.1 in folder: D:\Github\libraries\MD_Parola 
Using library MD_MAX72XX at version 3.3.1 in folder: D:\Github\libraries\MD_MAX72XX 
Using library SPI at version 1.0 in folder: C:\Users\ut4445o\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.6\libraries\SPI 
Using library Wire at version 1.0 in folder: C:\Users\ut4445o\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.6\libraries\Wire 
Using library RTCLib by NeiroN at version 1.6.2 in folder: D:\Github\libraries\RTCLib_by_NeiroN 
"C:\\Users\\ut4445o\\AppData\\Local\\Arduino15\\packages\\arduino\\tools\\avr-gcc\\7.3.0-atmel3.6.1-arduino7/bin/avr-size" -A "C:\\Users\\ut4445o\\AppData\\Local\\Temp\\arduino-sketch-2EDC5685D286BC96B589E6C2DE8AC2DF/Scrolling_Marquee.ino.elf"
Sketch uses 24136 bytes (78%) of program storage space. Maximum is 30720 bytes.
Global variables use 777 bytes (37%) of dynamic memory, leaving 1271 bytes for local variables. Maximum is 2048 bytes.

Using library MD_Parola at version 3.6.1 in folder: D:\Github\libraries\MD_Parola 
Using library MD_MAX72XX at version 3.3.1 in folder: D:\Github\libraries\MD_MAX72XX 
Using library SPI at version 1.0 in folder: C:\Users\ut4445o\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.6\libraries\SPI 
Using library Wire at version 1.0 in folder: C:\Users\ut4445o\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.6\libraries\Wire 
Using library RTCLib by NeiroN at version 1.6.2 in folder: D:\Github\libraries\RTCLib_by_NeiroN 
Using library SolarCalculator at version 2.0.1 in folder: D:\Github\libraries\SolarCalculator 
"C:\\Users\\ut4445o\\AppData\\Local\\Arduino15\\packages\\arduino\\tools\\avr-gcc\\7.3.0-atmel3.6.1-arduino7/bin/avr-size" -A "C:\\Users\\ut4445o\\AppData\\Local\\Temp\\arduino-sketch-2EDC5685D286BC96B589E6C2DE8AC2DF/Scrolling_Marquee.ino.elf"
Sketch uses 24136 bytes (78%) of program storage space. Maximum is 30720 bytes.
Global variables use 777 bytes (37%) of dynamic memory, leaving 1271 bytes for local variables. Maximum is 2048 bytes.

Using library Wire at version 1.0 in folder: C:\Users\ut4445o\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.6\libraries\Wire 
Using library SPI at version 1.0 in folder: C:\Users\ut4445o\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.8.6\libraries\SPI 
Using library MD_Parola at version 3.6.2 in folder: D:\Github\libraries\MD_Parola 
Using library MD_MAX72XX at version 3.3.1 in folder: D:\Github\libraries\MD_MAX72XX 
Using library RTCLib by NeiroN at version 1.6.2 in folder: D:\Github\libraries\RTCLib_by_NeiroN 
Using library SolarCalculator at version 2.0.1 in folder: D:\Github\libraries\SolarCalculator 
"C:\\Users\\ut4445o\\AppData\\Local\\Arduino15\\packages\\arduino\\tools\\avr-gcc\\7.3.0-atmel3.6.1-arduino7/bin/avr-size" -A "C:\\Users\\ut4445o\\AppData\\Local\\Temp\\arduino-sketch-2EDC5685D286BC96B589E6C2DE8AC2DF/Scrolling_Marquee.ino.elf"
Sketch uses 25064 bytes (81%) of program storage space. Maximum is 30720 bytes.
Global variables use 785 bytes (38%) of dynamic memory, leaving 1263 bytes for local variables. Maximum is 2048 bytes.

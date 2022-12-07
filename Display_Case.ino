void updateCase()
{     //I had the int below in case #2 but it gave me grief and at the time I didn't know why.
      //Case statements are only labels. This means the compiler will interpret this as a jump directly to the label.
      //I could do this if I used more curly brackets or some interesting "stuff" with semicolons or split it in two.
      //https://stackoverflow.com/questions/92396/why-cant-variables-be-declared-in-a-switch-statement
      //but reading too much of that hurts my tiny brain
      //I applied the fix of adding {} to the case but never tried to compile and test, I figured if it ain't broke...
      
     unsigned int Random = random(3, 32767); //grab a random number that is (3 to 32767)
                  itoa (Random, RandomNumber, 10);//turn that # into ascii
  switch (Case)
    {
      case 1:
            // Serial.println("case #1");
            // TestString = String(" Please Take A Number ");
            // TestString.toCharArray(FirstMessage,BUF_SIZE);
            // strcpy(OutputMessage, FirstMessage);  //{" Please Take A Number " }
            // digitalWrite(7,LOW);
            // digitalWrite(8,LOW);
            // digitalWrite(4,HIGH);
            // Case = 2; //this will send it to the next case
       break;
      
      case 2:
            // Serial.println("case #2");      
            // Serial.println((RandomNumber));
            // TestString = String(" Now Serving --> ");
            // TestString.toCharArray(FirstMessage,BUF_SIZE);
            // strcpy(OutputMessage, FirstMessage); //{" Now Serving --> " }now plus a random
            // strcat(OutputMessage,RandomNumber);   //add the "new" random number
            // digitalWrite(8,LOW);
            // digitalWrite(7,HIGH);
            // digitalWrite(4,LOW);
            // Case = 6; //this will send on until User input changes
        break;
      
      case 3:
            // Serial.println("case #3");
            // //TestString = String(" Out to Lunch "+String((char)232)+String((char)126)+String((char)232));
            // TestString = String(" Out to Lunch " );//my ascii bicycle joke may not be appreaciated
            // TestString.toCharArray(FirstMessage,BUF_SIZE);
            // strcpy(OutputMessage, FirstMessage);  //{" Out to Lunch "};
            // digitalWrite(8,LOW);
            // digitalWrite(7,HIGH);
            // digitalWrite(4,HIGH);
        break;
      
      case 4:
            // Serial.println("case #4");
            // //TestString = String(" In A Meeting "+String((char)001));
            // TestString = String(" In A Meeting ");
            // TestString.toCharArray(FirstMessage,BUF_SIZE);
            // strcpy(OutputMessage, FirstMessage); //{" In A Meeting "};
            // digitalWrite(8,HIGH);
            // digitalWrite(7,LOW);
            // digitalWrite(4,LOW);
        break;
      
      case 5:
            // Serial.println("case #5");
            //     if (newMessageAvailable)
            //       {
            //         strcpy(OutputMessage, newMessage);
            //         newMessageAvailable = false;
            //       }

            // digitalWrite(8,HIGH);
            // digitalWrite(7,LOW);
            // digitalWrite(4,HIGH);
       break;
      case 6:
            //Serial.println("case #6"); 
            itoa (hours, HourinASCII, 10);//turn that # into ascii
            Serial.println(hours); 
            Serial.println(HourinASCII);   
            itoa(minutes,MininASCII,10);
            Serial.println(minutes);
            Serial.println(MininASCII);
            itoa(seconds, SecinASCII,10); 
            Serial.println(seconds); 
            Serial.println(SecinASCII);             
            // strcpy(OutputMessage,HourinASCII);   //add the hours     
            // TestString = String(":");
            // TestString.toCharArray(FirstMessage,BUF_SIZE);
            // strcat(OutputMessage, FirstMessage); //{" Now Serving --> " }now plus a random
            // itoa(minutes,MininASCII,3);
            // strcat(OutputMessage,minutes);   //add the minutes
            // TestString.toCharArray(FirstMessage,BUF_SIZE);
            // strcat(OutputMessage, FirstMessage); //{" Now Serving --> " }now plus a random 
            // itoa(seconds, SecinASCII,3);        
            // strcat(OutputMessage,seconds);   //add the minutes
            digitalWrite(8,LOW);
            digitalWrite(7,HIGH);
            digitalWrite(4,HIGH);
            //Serial.println(OutputMessage); 
            Case = 6; //this will send it back until User input changes
            //Case = 1; //this will send it back until User input changes
        break;
//        case 7://added this to see what the ascii charaters looked like on the matrix display
//               //left in for future use, code compiled but did not play well with display needs work
//            Serial.println("case #7");
//            
//            for (int i = 1; i < 75; i++) 
//              {
//                TestString = String((char)i);
//                strcat(FourthMessage,i);
//                Serial.println(TestString);
//              }
//            
//            strcpy(OutputMessage, FourthMessage); //{" In A Meeting "};
//            digitalWrite(4,LOW);
//            digitalWrite(7,LOW);
//            digitalWrite(8,HIGH);
//        break;
        
      default:
            Serial.println("DEFAULT!");
            Case = 6;
            //Case = 1;
        break;
    }// end of switch (Message)
}//end of void updateCase()

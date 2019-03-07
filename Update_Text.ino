
void getMessage()
{
    if (getFirstMessage == true && getSecondMessage == false)
    {
        if (Timer <= 0) //if the time ticks down, reset timer and flaggs 
        {
          Serial.println(("Reset 1st MSG Timer"));
          Timer = 1;
          getFirstMessage = false;
          getSecondMessage = true;
        }
       
       strcpy(FirstMessage, IntroMessage);

    }//end if (getFirstMessage == true)
    
    else if (getFirstMessage == false && getSecondMessage == true)
    {
      unsigned int Random = random(3, 32767); //grab a random number
      char RandomNumber[9];
        
        if (Timer <= 0) //if the time ticks down, reset timer and flaggs 
        {
          Serial.println(("Reset 2nd MSG Timer"));
          Timer = 1;
          getFirstMessage = true;
          getSecondMessage = false;
        }
        
      
      itoa (Random, RandomNumber, 10);
      Serial.println((RandomNumber));
      Serial.println((Timer));
      strcpy(FirstMessage, SecondMessage);//this will clear out the "old" random number
      strcat(FirstMessage,RandomNumber);  //add the "new" random number
  
    }// end if (getSecondMessage == true)

}

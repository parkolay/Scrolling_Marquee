void getInput()
{
 int ctsValue = digitalRead(ctsPin);
    if (ctsValue == HIGH)
      {
          toggle = !toggle;
          ++Case;
          digitalWrite(LED_BUILTIN,toggle);
          Serial.println("touched");
      }

    else
      {
        //Serial.println("not touched");//removed, this ends up being a lot of updates
      } 
  delay(125);
}// end of void getInput()

void readSerial(void)
{
  static char *cp = newMessage;

  while (Serial.available())
  {
    *cp = (char)Serial.read();
    if ((*cp == '\n') || (cp - newMessage >= BUF_SIZE-2)) // end of message character or full buffer
    {
      *cp = '\0'; // end the string
      // restart the index for next filling spree and flag we have a message waiting
      cp = newMessage;
      newMessageAvailable = true;
    }
    else  // move char pointer to next position
      cp++;
  }// end of while (Serial.available())
}//end of void readSerial(void)

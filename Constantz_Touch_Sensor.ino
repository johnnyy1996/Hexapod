int valL = 0, valR = 0, counter = 0;
unsigned long time;
bool closed = 1;
void setup() 
{
  Serial.begin(115200);     // begin communication using 115.2K baud rate
  while(!Serial)
  {
    ;                       // wait while connecting
  }
  Serial.print("#14P1500 #13P1577 #12P1500");
  Serial.println();
  delay (3000);
}

void loop() 
{
  if (closed)
  {
    Serial.print("Open  ");
    Serial.print ("#28P1200 #29P1700");
    Serial.println();
    time = millis();
    while ((millis() - time) < 500)
    {
      Serial.print("time: ");
      Serial.print(millis()-time);
      Serial.println();
      valL = digitalRead(5);
      valR = digitalRead(10);
      Serial.print(valL);
      Serial.print("\t");
      Serial.print(valR);
      Serial.println();
      Serial.println();
      delay(10);
    }
    closed=0;
  }
  if (!closed)
  {
    Serial.print("Close  ");
    Serial.print ("#28P1700 #29P1300");
    Serial.println();
    time = millis();
    while ((millis() - time) < 500)
    {
      Serial.print("time: ");
      Serial.print(millis()-time);
      Serial.println();
      valL = digitalRead(5);
      valR = digitalRead(10);
      Serial.print(valL);
      Serial.print("\t");
      Serial.print(valR);
      Serial.println();
      Serial.println();
      delay(10);
    }
    closed=1;
  }
  counter ++;
  if (counter == 100)
  {
    Serial.print ("trial Completed **********************");
    Serial.println();
    while(counter ==100);
    {
      ;
    }
  }
  
  
  

}

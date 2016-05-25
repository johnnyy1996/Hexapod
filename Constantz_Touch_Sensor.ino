int valL = 0, valR = 0, counter = 0, openVal [100], closeVal[100];
char qp;
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
    delay(500);
    valL = digitalRead(5);
    valR = digitalRead(10);
    Serial.print("L "); 
    Serial.print(valL);
    Serial.println();
    Serial.print("R "); 
    Serial.print(valR);
    Serial.println();
    Serial.println();
    if (!valL && !valR)
      openVal [counter] = 1;
    closed=0;
  }
  if (!closed)
  {
    Serial.print("Close  ");
    Serial.print ("#28P1700 #29P1300");
    Serial.println();
    delay (500);
    valL = digitalRead(5);
    valR = digitalRead(10);
    Serial.print("L "); 
    Serial.print(valL);
    Serial.println();
    Serial.print("R "); 
    Serial.print(valR);
    Serial.println();
    Serial.println();
    if (valL && valR)
      closeVal [counter] = 1;
    closed=1;
  }
  counter ++;
  if (counter == 100)
  {
    Serial.print ("trial Completed, Printing Data **********************");
    Serial.println();
    Serial.print ("Open val");
    Serial.print ("\t");
    Serial.print ("Close val");
    Serial.print ("\t");
    Serial.println();
    for (int i=0; i<100; i++)
    {
      Serial.print (openVal[i]);
      Serial.print ("\t\t");
      Serial.print (closeVal[i]);
      Serial.println();
    }
    while(counter ==100);
    {
      ;
    }
  }
  
  
  

}

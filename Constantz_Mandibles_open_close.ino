/* 
Victor Cuevas
This code simply makes the robot open and close its mandibles
This code was ment to take 4 inputs, 2 per jaw in order to fully open or fully close with slow and fast speed, but the architecture was abandoned.
*/

int inbyte = 0;
double lJaw [2] {0,0}; //#29 {F, S} 1700 fully open 1200 fully closed. F stands for fast and S for slow, an input of 1 on either of these will trigger appropiate response for the mandibles
double rJaw [2] {0,0}; //#28 {F, S} 1200 fully open 1700 fully closed

void setup() 
{
  Serial.begin(115200);     // begin communication using 115.2K baud rate
  while(!Serial)
  {
    ;                       // wait while connecting
  }
}

void jaws (double lJaw [], double rJaw [])
{
  double leftPOS, rightPOS, force;

  if (lJaw [0] > 0)
  {
    Serial.print ("#29P");
    Serial.print (-(500*lJaw[0]) + 1700);
    Serial.println();
  }
  else if (lJaw [1] > 0)
  {
    Serial.print ("#29P");
    Serial.print (-(500*lJaw[1]) + 1700);
    Serial.print ("T3000");
    Serial.println();
  }
  else 
  {
    Serial.print ("#29P1700");
    Serial.println();
  }

  if (rJaw [0] > 0)
  {
    Serial.print ("#28P");
    Serial.print (500*rJaw[0] + 1200);
    Serial.println();
  }
  else if (rJaw [1] > 0)
  {
    Serial.print ("#28P");
    Serial.print (500*rJaw[1] + 1200);
    Serial.print ("T3000");
    Serial.println();
  }
  else 
  {
    Serial.print ("#28P1200");
    Serial.println();
   }
  lJaw [0] = 0;
  lJaw [1] = 0;
  rJaw [0] = 0;
  rJaw [1] = 0;
}

void loop() 
{//this is hardcoded input testing the code
  Serial.print("0");
  Serial.println();
  lJaw [0] = 0;
  rJaw [0] = 0;
  jaws (lJaw, rJaw);
  delay(5000);
  Serial.print("1");
  Serial.println();
  lJaw [0] = 1;
  rJaw [0] = 1;
  jaws (lJaw, rJaw);
  delay(5000);
  lJaw [0] = 0.1;
  rJaw [0] = 0.1;
  jaws (lJaw, rJaw);
  delay(5000);
  lJaw [0] = 0.8;
  rJaw [0] = 0.8;
  jaws (lJaw, rJaw);
  delay(5000);
  
  lJaw [1] = 0;
  rJaw [1] = 0;
  jaws (lJaw, rJaw);
  delay(5000);
  lJaw [1] = 1;
  rJaw [1] = 1;
  jaws (lJaw, rJaw);
  delay(5000);
  lJaw [1] = 0.1;
  rJaw [1] = 0.1;
  jaws (lJaw, rJaw);
  delay(5000);
  lJaw [1] = 0.8;
  rJaw [1] = 0.8;
  jaws (lJaw, rJaw);
  delay(5000);
  

}

/* 
Victor Cuevas
This code simply makes the robot open and close its mandibles
*/

void setup() 
{
  Serial.begin(115200);     // begin communication using 115.2K baud rate
  while(!Serial)
  {
    ;                       // wait while connecting
  }
}

void openMouth() //sends 2 servos comands to make mandibles open
{
  Serial.print ("#28P1200 #29P1700");
  Serial.println();
  delay(1000);
}


void closeMouth() //sends 2 servos comands to make mandibles close
{
  Serial.print ("#28P1700 #29P1200");
  Serial.println();
  delay (500)
  if (QP 28 <cr> != 1700 || QP 29 <cr> != 1200)
	Serial.print ("#28P" + (QP 28)*10) + "#29P" + (QP 29)*10);
  Serial.println();
  delay(500);
}



void loop() 
{
  openMouth();
  closeMouth();
  delay(5000);

}

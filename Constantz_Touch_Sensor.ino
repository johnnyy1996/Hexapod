/* Author Victor Cuevas
 *  This code uses pin 5 and pin 10 to read input signals from installed pressured sensors.
 *  It displays the signal of the sensors before and after mandibles are comanded to open or close
 */

int valL = 0, valR = 0; //these variables will hold the value of the sensors
bool closed = 1;  //this variable will keep track of wether the mandibles are currently open or not
void setup() 
{
  Serial.begin(115200);     // begin communication using 115.2K baud rate
  while(!Serial)
  {
    ;                       // wait while connecting
  }
}

void loop() 
{
  if (closed) //if the mandibles are currently closed, then comand to open
  {
    valL = digitalRead(5);  //read pin 5 (presure sensor)
    valR = digitalRead(10);  //read pin 10 (pressure sensor)
    Serial.print("L "); 
    Serial.print(valL);
    Serial.println();
    Serial.print("R "); 
    Serial.print(valR);
    Serial.println();
    Serial.print("Open  ");
    Serial.print ("#28P1200 #29P1700"); //comand for mandibles to open
    Serial.println();
    delay(1000);
    valL = digitalRead(5);
    valR = digitalRead(10);
    Serial.print("L "); 
    Serial.print(valL);
    Serial.println();
    Serial.print("R "); 
    Serial.print(valR);
    Serial.println();
    Serial.println();
    closed=0;
  }
  if (!closed)
  {
    valL = digitalRead(5);
    valR = digitalRead(10);
    Serial.print("L "); 
    Serial.print(valL);
    Serial.println();
    Serial.print("R "); 
    Serial.print(valR);
    Serial.println();
    Serial.print("Close  ");
    Serial.print ("#28P1600 #29P1300");
    Serial.println();
    delay (1000);
    valL = digitalRead(5);
    valR = digitalRead(10);
    Serial.print("L "); 
    Serial.print(valL);
    Serial.println();
    Serial.print("R "); 
    Serial.print(valR);
    Serial.println();
    Serial.println();
    closed=1;
  }
  
  
  
  

}

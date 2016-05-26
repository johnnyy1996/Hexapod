/* Author Victor Cuevas
 *  This code performs 100 test trials on the mandibles pressure sensors and displays the output signal on the screen
 *  It uses pin 5 and pin 10 to read input signals from installed pressured sensors on the left and rigth mandibles.
 *  It displays the signal of the sensors every 10(+-1) miliseconds with an aproximate delay of 500 milliseconds
 *    for the movement to complete
 *  An output of 1 or 0 would represent if the sensor is activated
  */

int valL = 0, valR = 0;     //valL and valR hold the values of the sensor to ben printed
int counter = 0;            //the variable counter will be used to determine the amount of trials
unsigned long time;         //will hold the time a comand was started in order to determine length of comand
bool closed = 1;            //hold bool value wether the mandibles are open or not
void setup() 
{
  Serial.begin(115200);     // begin communication using 115.2K baud rate
  while(!Serial)
  {
    ;                       // wait while connecting
  }
  Serial.print("#14P1071 #13P1577 #12P1500");   //setup comands to position the head servos
  Serial.println();
  delay (3000);
}

void loop() 
{
  if (closed)                 //if mandibles are closed, comand to open
  {
    Serial.print("Open  ");
    Serial.print ("#28P1200 #29P1700");
    Serial.println();
    time = millis();          //record elapse time since program started, this would serve as tool to determine the delay we need
    while ((millis() - time) < 500) //while the time elapse since comand has been give is < 500 milliseconds
                                    //this acts as a delay in order for servos to complete the comand, in the meantime we read sensor inputs
                                    //we give it a delay of 500 milliseconds
    {
      Serial.print(millis()-time);
      Serial.print("\t");
      valL = digitalRead(5);        //read left sensor signal
      valR = digitalRead(10);       //read right sensor signal
      Serial.print(valL);
      Serial.print("\t");
      Serial.print(valR);
      Serial.println();
      Serial.println();
      delay(10);                    //we read sensor signal every 10 milliseconds in order to not overflow with data
                                    //we can read as fast as we can but keep in mind sensor data gets updated every 2-5 milliseconds
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
      //Serial.print("time: ");
      Serial.print(millis()-time);
      Serial.print("\t");
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
  if (counter == 100)               //this statement will check to see if given ammount of trials were completed
  {
    Serial.print ("trial Completed **********************");
    Serial.println();
    while(counter ==100);           //infinite loop to keep the robot from moving
    {
      ;
    }
  }
  
  
  

}

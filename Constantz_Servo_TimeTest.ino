/*  Author: Joyce Chiu
 *  This program was created for the "Constantz" LynxMotion Hexapod robot. This program was
 *  intended to utilize the class "servoIO" to measure the fastest speed at which the servos 
 *  can move from 0 to 180 degrees, but unfortunately, without a feedback connection from the 
 *  servos to the BotBoarduino, this measurement is not possible. Instead, this program shows 
 *  how long it takes (in microseconds) for the BotBoarduino to relay position information to 
 *  the servo controller and execute the commanded positions.
 */

#include <servoIO.h>

//Declare variables to record time
long start_time, end_time, time_elapsed;

//Declare an array of 18 servoIO objects
servoIO servoObj[18];

//Declare an array of integers to hold the servo pins
int servoPin[18] = {0,8,20,16,24,4,1,9,21,17,25,5,2,10,22,18,26,6};

void setup() {
  Serial.begin(115200);     /* Begin communication using 115.2K baud rate */
    while(!Serial) {
      ;                     /* wait while connecting */
    }

  //Assign the servo pin number to the variable servo_number in each servo object
  for(int i = 0; i < 18; i++) {
    servoObj[i].servo_number = servoPin[i];
  }
}

void loop() {

   /*
   * Directions: To see the serial print statments, connect the hexapod to the
   * computer via USB, compile and upload the program to the hexapod. Then,
   * without disconnecting the USB, click on the Serial Monitor magnifying glass 
   * icon located on the upper right hand corner of the Arduino IDE. A new window 
   * should appear, showing the serial print statments of the program. 
   */


  /* Command the 18 servos to move from position 500 to 2500 (0 to 180 degrees)
   * Check if the movement of each servo was completed
   * If movement was completed, print the servo nuumber and the elapsed time
   * If movement was not completed, print "Movement NOT completed"
   */
  for(int i = 0; i < 18; i++) {
    servoObj[i].setServoPosition(500);
    servoObj[i].writeToServo();
    servoObj[i].setServoPosition(2500);
    start_time = micros();              
    servoObj[i].writeToServo();

    if(servoObj[i].isMovementCompleted() == true) {
      Serial.println(servoObj[i].servo_number);
      Serial.println("Movement Completed");  
      end_time = micros();
      time_elapsed = end_time - start_time;
      Serial.println("Time Elapsed: ");
      Serial.println(time_elapsed);             /* time in microseconds */
      Serial.println(" ");
      Serial.println(" ");
    }
    else Serial.println("Movement NOT completed.");
  }
  delay(3000);
}

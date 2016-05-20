/*  Author: Joyce Chiu
 *  This program was created for the "Constantz" LynxMotion Hexapod robot. It utilizes the
 *  class "servoIO" to test if the servos are able to move synchroniously as we send commands
 *  to the 18 leg servos to move to 0, 90 and 180 degrees.
 */

#include <servoIO.h>

//Create an array to store the servo pins corresponding to each of the servos on the 6 legs
int servoPinArray[18] = {0,8,20,16,24,4,1,9,21,17,25,5,2,10,22,18,26,6};

//Declare an array of servoIO objects
servoIO servoObj[18];

void setup() {
  Serial.begin(115200);     /* Begin communication using 115.2K baud rate */
  while(!Serial) {
    ;                      /* wait while connecting */
  }

  //Assign the servo pin number to the servoNumber variable in each servo object
  for(int i = 0; i < 18; i++) {
    (servoObj[i]).setServoNumber(servoPinArray[i]);
  }

}

void loop() {
  //Command all of the servos to move to the default position (90 degrees)
  for(int i = 0; i < 18; i++) {  
    servoObj[i].writeToServo();      
  }
  
  //Command all of the servos to move to 0 degrees
  for(int i = 0; i < 18; i++) {  
    servoObj[i].setInputValue(0); /* An input value of 0 equates to 0 degrees */
    servoObj[i].convertInput();
    servoObj[i].updateServoPosition(); 
    servoObj[i].writeToServo();
  }
  
    //Command all of the servos to move to 90 degrees
    for(int i = 0; i < 18; i++) {  
    servoObj[i].setInputValue(0.5); /* An input value of 0.5 equates to 90 degrees */
    servoObj[i].convertInput();
    servoObj[i].updateServoPosition(); 
    servoObj[i].writeToServo();
  }

    //Command all of the servos to move to 180 degrees
    for(int i = 0; i < 18; i++) {  
    servoObj[i].setInputValue(1); /* An input value of 1 equates to 180 degrees */
    servoObj[i].convertInput();
    servoObj[i].updateServoPosition(); 
    servoObj[i].writeToServo();
  }
}

/*  Author: Joyce Chiu
 *  This program was created for the "Constantz" LynxMotion Hexapod robot. It utilizes the
 *	class "servoIO" to test for servo angle accuracy. We test if the servo is able to 
 *	move to the correct angle as we send commands to servo to move to 0, 30, 60, 90, 120, 
 *	150 and 180 degrees.
 */

#include <servoIO.h>

//Create a servoIO object and attach it to pin # 25 (this is the servo we will be testing)
servoIO servoObj(25);

//Create an array of servo positions ranging from 0 to 180 degrees, in intervals of 30 degrees.
//These angular positions are represented by the corresponding pulse width.
int positions[7] = {500, 833, 1167, 1500, 1833, 2167, 2500};

void setup() {
	Serial.begin(115200);     /* Begin communication using 115.2K baud rate */
  	while(!Serial) {
    	;                     /* wait while connecting */
  	}
}

void loop() {

  //Command the servo to move to the appropriate degrees
  for(int i = 0; i < 7; i++) {
    servoObj.setServoPosition(positions[i]);
    servoObj.writeToServo();
    //Set a delay to allow time for measurements
    delay(3000);
  }
  
}

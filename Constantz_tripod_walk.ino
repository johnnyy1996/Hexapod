/*
Author: Lisandra Jimenez 
This program lets BotBoarduino send commands to LynxMotion SSC-32 board to make hexapod robot move forward, 
which is an eight step (stage) process and each step take 1 second to complete. Adapted from Amrik Singh's code. 

Added parameters to the original code by creating the 3rd degree of freedom to the legs by enabling movement for 
each tibia (lower arm/wrist) and more flexibility in movement.
*/

void setup() 
{
  Serial.begin(115200);     // begin communication using 115.2K baud rate
  while(!Serial)
  {
    ;                       // wait while connecting
  }
  
  Serial.print("#1p2000 #9p2000 #21p900 #2p2000 #10p2000 #22p900 #17p900 #25p900 #5p2000 #18p900 #26p900 #6p2000 #0p1600 #4p1500 #8p1400 #16p1600 #20p1500 #24p1700");
  Serial.println();
  delay(200);
  Serial.print("#1p1000 #9p1000 #21p2000 #2p1500 #10p1500 #22p1500 #17p2000 #25p2000 #5p1000 #18p1500 #26p1500 #6p1500");
  delay(600);
  #define MOVETIME 500      //a constant to change the stride duration of each step
}

/*
tripodA: right front leg(RFL), right rear leg(RRL) and left middle leg(LML)
tripodB: left front leg(LFL), left rear leg(LRL) and right middle leg(RML)
*/

void triPodA_pickUp(){
  servoMove(1,1500,9,1500,21,1500,2,2000,10,2000,22,1000,MOVETIME);  
  }
void triPodA_forward(){
  servoMove(0,1700,8,1650,20,1300,2,2000,10,2000,22,1000,MOVETIME); 
  }
void triPodA_onGround(){
  servoMove(1,1000,9,1000,21,2000,2,1500,10,1500,22,1500,MOVETIME);   
  }
void triPodA_push(){
  servoMove(0,1500,8,1500,20,1500,2,1500,10,1500,22,1500,MOVETIME); 
  }

void triPodB_pickUp(){   
  servoMove(17,1500,25,1500,5,1500,18,1000,26,1000,6,2000,MOVETIME); 
  }
void triPodB_forward(){   
  servoMove(16,1300,24,1350,4,1700,18,1000,26,1000,6,2000,MOVETIME); 
  }
void triPodB_onGround(){   
  servoMove(17,2000,25,2000,5,1000,18,1500,26,1500,6,1500,MOVETIME);   
  }
void triPodB_push(){   
  servoMove(16,1500,24,1500,4,1500,18,1500,26,1500,6,1500,MOVETIME); 
  }

/* Comment Section Follows:
  void servoMove()
Input: 
       byte servo1 - the pin number of a servo to be moved
       int position1 – the end position for servo1 (values are 500-2500)
       byte servo2   pin number of the second servo to move
       int position2 the end position for servo2
       byte servo3 - the pin number of the third servo to move
       int position - the end position for servo3
	  byte servo4 – the pin # of the fourth servo to move (tibia’s initial setting)
	  int tibpos1 – the end position for the first tibia (repeated for tibia 2 and 3)
       int time - the time, in ms to complete the 3 servo moves (MOVETIME constant is set to 500)
Process:
       This function allows 6 servos (i.e. the elbows and wrists for one tripod) to be moved simultaneously 
       to the desired positions and includes a stride duration parameter in which we request that the hexapod 
       complete the move in the requested time.  The function converts the commands to a format which the 
       SSC-32 board will be able to understand.  Please refer to the SSC-32 manual 
       (http://www.lynxmotion.com/images/html/build136.htm) for this and more commands.

Output:
       This function returns a void value, but the output becomes the actual movement of the hexapod
End of Comment
*/ 

void servoMove(byte servo1, int position1, byte servo2, int position2, byte servo3, int position3, byte servo4, int tibpos1, byte servo5, int tibpos2, byte servo6, int tibpos3, int time) {
  
    Serial.print("#");                   //i.e. the # of the pin
    Serial.print(servo1);
    Serial.print(" P");
    Serial.print(position1);             //i.e. the position we want the servo1 to move to
    Serial.print("#");
    Serial.print(servo2);
    Serial.print(" P");
    Serial.print(position2);
    Serial.print("#");
    Serial.print(servo3);
    Serial.print(" P");
    Serial.print(position3);
    Serial.print("#");         		// 1st tibia pin number
    Serial.print(servo4);
    Serial.print(" P"); 
    Serial.print(tibpos1);      	//  first tibia position
    Serial.print("#");         		// 2nd tibia pin number
    Serial.print(servo5);
    Serial.print(" P");
    Serial.print(tibpos2);        	// second tibia position   
    Serial.print("#");         		// 3rd tibia pin number
    Serial.print(servo6);
    Serial.print(" P");
    Serial.print(tibpos3); 		// third tibia position
    Serial.print(" T");
    Serial.print(time);
    Serial.println(); 			// carriage return sends the Serial command
    delay(time); 			// force Arduino to wait for the move to complete
}

bool initialStartDelay = true;          // this variable allows the one time delay before
  				        // the hexapod starts to walk


// the loop routine runs over and over forever
/*
The hexapod picks up tripodA, brings it forward, brings tripodA on ground to hold the weight 
and then picks up tripodB, brings it forward, and the "tripodA" push robot forward and next 
tripodB makes contact with ground, and also pushes the hexapod forward
*/
//enter this loop only while initialStartDelay is true for one-time pause

void loop() {

  if (initialStartDelay){
    delay(6000); 	         // delay(do nothing) for 6 seconds
    initialStartDelay = false;   // set the variable to false so this loop is never entered again
  }

  triPodA_pickUp();
  triPodA_forward();
  triPodB_push();
  triPodA_onGround();
  triPodB_pickUp();
  triPodB_forward();
  triPodA_push(); 		// this is what propels the hexapod forward
  triPodB_onGround();
 }



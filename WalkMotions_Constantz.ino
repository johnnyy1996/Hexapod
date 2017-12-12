/*
 *Author: Eric Li 
 *This program is a program made to be able to walk forward and diagonally.
 *It utilizes the Botboarduino to send commands to the SSC-32 Control board.
 *These functions are built specifically for Constantz so keep in mind:
 *- Constantz has the servos flipped around hence pin 0 is the Top Left Horizontal Hip 
 *  on the SSC-32 manual but on Constantz it is the Bottom Right Horizontal Hip. 
 *- The right side and the left side of Constantz move opposite given the same pulse width hence
 *  the program is written as the difference of instead and the left side is the side I considered correct.
 */
#ifndef BAUDRATE
#define BAUDRATE 115200
#endif

#ifndef DEFAULT_POSITION
#define DEFAULT_POSITION 1500
#endif

#include "servoIO.h" //class created by Joyce Chiu
#include "tripod.h"

servoIO ApodServos[25];
bool firstMovement = true;
int servoPinNumbers[25] = {0,1,2,4,5,6,8,9,10,16,17,18,20,21,22,24,25,26,28,29,30,31,12,13,14};
//servoIO testServo(20); //LMH randomly chosen to test if BotBoarduino is transmitting commands to SSC-32 and that SSC-32 is receiving it
tripod A,B;

/*
 * void walkForward()
 * 
 * This function performs a walk forward.
 */
void walkForward(){
  A.lift();
  A.forward();
  if(firstMovement){
    firstMovement = false;
  }
  else{
    B.pushFoward(); 
  }
  A.down();
  B.lift();
  B.forward();
  A.pushFoward();
  B.down();
  
}
/*
 * void setup()
 * 
 * This function is called once at the start of the program.
 */
void setup() {
  Serial.begin(BAUDRATE); // begin communication using 115.2K baud rate
  while(!Serial){} // wait while connecting
  //Assign a pin number to each servoIO class
  for(int i = 0; i < 25; i++) {
    (ApodServos[i]).setServoNumber(servoPinNumbers[i]);
  }
  //Set Initial Position for Leg Servos
  for(int i = 0; i < 18; i+=9){
    for (int j = 0; j < 9; j++){
        if (i == 0){
          ApodServos[i+j].setReverse(true);
        }
        else{
          ApodServos[i+j].setReverse(false);
        }
    }
    for(int j = 0; j < 3; j++){
      ApodServos[i+(3*j)].setServoPosition(DEFAULT_POSITION);
      ApodServos[i+1+(3*j)].setServoPosition(DEFAULT_POSITION + (ApodServos[i+1+(3*j)].notReverse()*500));
      ApodServos[i+2+(3*j)].setServoPosition(DEFAULT_POSITION);
    }
    /*
    ApodServos[i].setServoPosition(DEFAULT_POSITION + (ApodServos[i].notReverse()*250));
    ApodServos[i+3].setServoPosition(DEFAULT_POSITION + (ApodServos[i+3].notReverse()*250));
    ApodServos[i+6].setServoPosition(DEFAULT_POSITION + (ApodServos[i+6].notReverse()*250));
    */
  }
  
  //The two tripods declared here.
  A = tripod(ApodServos[0] ,ApodServos[6] ,ApodServos[12] ,ApodServos[1] ,ApodServos[7] ,
    ApodServos[13] ,ApodServos[2] ,ApodServos[8] ,ApodServos[14] );
  B = tripod(ApodServos[9] ,ApodServos[15] ,ApodServos[3] ,ApodServos[10] ,ApodServos[16] ,
    ApodServos[4] ,ApodServos[11] ,ApodServos[17] ,ApodServos[5] );
  
  //Set Initial Position for Mandibles and Abdomen.
  for(int i = 18; i < 25; i++){
    ApodServos[i].setServoPosition(DEFAULT_POSITION);
  }
  //Send the positions for every servo to the SSC-32 via BotBoarduino
  for(int i = 0; i < 25; i++){
    ApodServos[i].writeToServo();
  }
  Serial.println("T1000");
}

/*
 * void loop()
 * 
 * The endless loop that is called by the BotBaorduino
 */
void loop() {
  walkForward();
}

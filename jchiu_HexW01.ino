/*  Author: Joyce Chiu
 *  This program lets the BotBoarduino send commands to the servos on the LynxMotion SSC-32 board to make the Hexapod robot move
 *  by updating the positions and writing their positions to the servos.
 */

String servoPosition;
String servoPin[18] = {"#0","#8","#20",         /* TripodA shoulder    Indices 0-5 are shoulders */
                       "#16","#24","#4",        /* TripodB shoulder                              */
                       "#1","#9","#21",         /* TripodA elbow       Indices 6-11 are elbows   */
                       "#17","#25","#5",        /* TripodB elbow                                 */
                       "#2","#10","#22",        /* TripodA wrist       Indices 12-17 are wrists  */
                       "#18","#26","#6"};       /* TripodB wrist                                 */
                       
String servoArray[18];                          /* Create an array to store the servo positions for each pin */


void setup() {
  Serial.begin(115200);     /* Begin communication using 115.2K baud rate */
  while(!Serial) {
    ;                      /* wait while connecting */
  }

  /* Initialize position of all servos to resting position */
  servoPosition = "1500";

  for(int i = 0; i < 18; i++) {
    servoArray[i] = servoPin[i] + "P" + servoPosition;
  }
}

/*
 *  void updateServoPosition()
 *  
 *  Input:
 *    servoArray - the array that holds the commands of the servos
 *    servoPin - the array that holds the pin # of the servos
 *    servoType - the string literal the specifies the type of servo (values are "shoulder", "elbow", "wrist", or "all")
 *    servoPos - the desired position of the servo (values are from 500-2500)
 *  Process: 
 *    This function checks the servoType to see which pin # needs to be updated with the servoPos value.
 *    Once the range of the array is identified, it updates the servo positions of those particular elements
 *    in the servoArray.
 *  Output:   
 *    This function stores the commands of each servo in the servoArray.
 *   
 */

void updateServoPosition(String (&servoArray)[18], const String (&servoPin)[18], String servoType, String servoPos) {
  int startIndex;
  int endIndex;

  if(servoType == "shoulder") {
    startIndex = 0;
    endIndex = 5;
  }

  if(servoType == "elbow") {
    startIndex = 6;
    endIndex = 11;
  }

  if(servoType == "wrist") {
    startIndex = 12;
    endIndex = 17;
  }

  if(servoType == "all") {
    startIndex = 0;
    endIndex = 17;
  }

  for(int i = startIndex; i <= endIndex; i++) {
    servoArray[i] = servoPin[i] + "P" + servoPos;
  }
}

/*
 *  void commandServo()
 *  
 *  Input: 
 *    servoArray - the array that holds the commands of the servos
 *  Process: 
 *    This function scans the servoArray for commands of each servo and prints the commands to the SSC-32 servo
 *    controller.
 *  Output: 
 *    The servo commands are executed, allowing the hexapod robot to move.
 *    
 */

void commandServo(String (&servoArray)[18]) {
  for(int i = 0; i < 18; i++) {
    Serial.print(servoArray[i]);
    Serial.println();
    delay(2000);                                  /* Time delay to allow servos to move */
  }
}

void loop() {
  
  /* Write to all 18 servos their positions to move */
  commandServo(servoArray);

  /* Change positions of servos and update commands (contracting)
     Update the servos according to type */
  updateServoPosition(servoArray, servoPin, "shoulder", "900");
  updateServoPosition(servoArray, servoPin, "elbow", "900");
  updateServoPosition(servoArray, servoPin, "wrist", "900");

  /* Write the updated positions to all the servos and move */
  commandServo(servoArray);

  /* Change positions of servos and update commands (midposition)
     Update all servo types at once */
  updateServoPosition(servoArray, servoPin, "all", "1500");
  commandServo(servoArray);
  
  /* Change position of servos and update commands (extending)
     Update all servo types at once */
  updateServoPosition(servoArray, servoPin, "all", "2000");
  commandServo(servoArray);
  
}


/*
 * Author: Jonathan Garcia
 * This class tests the head of the hexapod.
 * It runs a couple of different functions that
 * move the neck and mandibles around.
 * It also provides mobility functions for each
 * of the servos.
 */

#include "servoIO.h"

#ifndef BAUDRATE
#define BAUDRATE 115200
#endif

//the default position for servo #13 on the Constantz hexapod robot
#ifndef DEFAULT_POSITION_13
#define DEFAULT_POSITION_13 1550
#endif

//the default position for servo #12 on the Costantz hexapod robot
#ifndef DEFAULT_POSITION_12
#define DEFAULT_POSITION_12 1500
#endif

//the default position for servo #14 on the Constantz hexapod robot
#ifndef DEFAULT_POSITION_14
#define DEFAULT_POSITION_14 2000
#endif

//the default position for servo #28 (left mandible) on the Constantz hexapod robot
#ifndef DEFAULT_POSITION_28
#define DEFAULT_POSITION_28 1220
#endif

//the default position for servo #29 (right mandible) on the Constantz hexapod robot
#ifndef DEFAULT_POSITION_29
#define DEFAULT_POSITION_29 1720
#endif

#ifndef HEXAPODHEAD_H
#define HEXAPODHEAD_H

class hexapodHead{
    public:
        hexapodHead(); //this is the default constructor.
        hexapodHead(servoIO neck1, servoIO neck2, servoIO neck3, servoIO leftMandible, servoIO rightMandible); //this constructor allows the user to pass servoIO objects as parameters to initialize the servos of the head of the hexapod.
        hexapodHead(int neckServoNumOne, int neckServoOnePosition, int neckServoNumTwo, int neckServoTwoPosition,int neckServoNumThree, int neckServoThreePosition, int leftMandibleServoNum, int leftMandibleServoPosition, int rightMandibleServoNum, int rightMandibleServoPosition); //this constructor allows the user to pass the servo # and and position as parameters for each servo on the head of the hexapod.
        void testMandibles(int openLeftMandible, int openRightMandible, int closeLeftMandible, int closeRightMandible); //tests the mandibles of the hexapod by fully opening and closing them.
        void testLeftRight(int moveLeft, int moveRight); //tests the servo of the hexapod that allows it to turn left and right.
        void testUpDown(int moveUp, int moveDown); //tests the servos of the hexapod that allows it to turn up and down.
        void testNeckRotation(int rotateLeft, int rotateRight); //tests the servos of the hexapod that allows it to rotate its neck.
        void testRun(int openLeftMandible, int openRightMandible, int closeLeftMandible, int closeRightMandible, int moveLeft, int moveRight, int moveUp, int moveDown, int rotateLeft, int rotateRight); //runs all testing functions to check every function in one go.
        void setUpMandibles(int leftMandiblePosition, int rightMandiblePosition); //adjusts the mandibles to the default position. The default will set the mandibles to a closed position.
        void setUpLRServo(int leftRightPosition); //adjusts the servo that allows the head to move from left to right. It will center the head to look forward.
        void setUpUDServo(int upDownposition); //adjusts the servo that allows the head to move up and down. It will center the head to look forward.
        void setUpRoationServo(int rotationposition); //adjusts the servo that allows the head to rotate. It will center the head to look forward.
        void setUpAll(int leftMandiblePosition, int rightMandiblePosition, int leftRightPosition, int upDownPosition, int rotationPosition); //adjusts all the servos on the head. It positions all the servos in such a way that the head will be poiting forward and the mandibles are closed.
        void hexapodHead::cycleMotorOutput(char * motor_output_file_left, char * motor_output_file_right); //this function was designed to work with the Arduino software but was unable to work the way it was meant to due to the fact that Arduino does not support the fstream library.
    
    private:
        servoIO hexapodNeck[3]; // This array of servoIO objects is for the three servos on the neck of the hexapod.
        // hexapodNeck[0] = Servo #13 (Rotation Servo)
        // hexapodNeck[1] = Servo #12 (Left/Right Servo)
        // hexapodNeck[2] = Servo #14 (UP/Down Servo)
        servoIO mandibles[2]; // This array of servoIO objects is for the two mandibles, the left and right.
        //mandibles[0] = Servo #29 (Left Mandible)
        //mandibles[0] = Servo #28 (right Mandible)
};

#endif /* HexapodHead_h */

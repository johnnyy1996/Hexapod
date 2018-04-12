/*
 * Author: Jonathan Garcia
 */
#include "HexapodHead.h"
#include "servoIO.h"
#include "Arduino.h"

/*
 * This is the default constructor of the HexapodHead class.
 * It will initialize the 5 servos needed to aoperate the head.
 * 3 servos are for the neck and 2 are for the mandibles.
 */

hexapodHead::hexapodHead(){
    hexapodNeck[0].setServoNumber(13);
    hexapodNeck[0].setServoPosition(DEFAULT_POSITION_13);
    hexapodNeck[1].setServoNumber(12);
    hexapodNeck[1].setServoPosition(DEFAULT_POSITION_12);
    hexapodNeck[2].setServoNumber(14);
    hexapodNeck[2].setServoPosition(DEFAULT_POSITION_14);
    mandibles[0].setServoNumber(29);
    mandibles[0].setServoPosition(DEFAULT_POSITION_29);
    mandibles[1].setServoNumber(28);
    mandibles[1].setServoPosition(DEFAULT_POSITION_28);
}

/*
 * This is the constructor that takes 5 arguments as parameters to initialize the 5 servos used to operate the head.
 * The first three will be for the three parts of the neck.
 * The first will be for the servos that allows it to move its head left and right.
 * The second will be for the servos that allows it to move its head up and down.
 * The third will be for the servos that allows it to rotate its head.
 * The last two will be for the two mandibles.
 * The fourth will be for the servos used to move the left mandible
 * The fifth will be for the servos used to move the right mandible
 *servo arguments must already have the data members assigned.
 */
hexapodHead::hexapodHead(servoIO neck1, servoIO neck2, servoIO neck3, servoIO leftMandible, servoIO rightMandible){
    hexapodNeck[0] = neck1;
    hexapodNeck[1] = neck2;
    hexapodNeck[2] = neck3;
    mandibles[0] = leftMandible;
    mandibles[1] = rightMandible;
}
/*
 * This is the constructor that takes 10 arguments as parameters to initialize the 5 servos used to operate the head.
 * The first two are for the rotational servo.
 * The first is for the rotational servo # and the second is for the rotational servo position.
 * The second pair is for the left/right servo.
 * The first is for the left/right servo # and the second is for the left/right servo position.
 * The third pair is for the up/down servo.
 * The first is for the up/down servo # and the second is for the up/down servo position.
 * The fourth pair is for the left mandible servo.
 * The first is for the left mandible servo # and the second is for the left mandible servo position.
 * The fifth pair is for the right mandible servo.
 * The first is for the right mandible servo # and the second is for the right mandible servo position.
 */
hexapodHead::hexapodHead(int neckServoNumOne, int neckServoOnePosition, int neckServoNumTwo, int neckServoTwoPosition,int neckServoNumThree, int neckServoThreePosition, int leftMandibleServoNum, int leftMandibleServoPosition, int rightMandibleServoNum, int rightMandibleServoPosition){
    hexapodNeck[0].setServoNumber(neckServoNumOne);
    hexapodNeck[0].setServoPosition(neckServoOnePosition);
    hexapodNeck[1].setServoNumber(neckServoNumTwo);
    hexapodNeck[1].setServoPosition(neckServoTwoPosition);
    hexapodNeck[2].setServoNumber(neckServoNumThree);
    hexapodNeck[2].setServoPosition(neckServoThreePosition);
    mandibles[0].setServoNumber(leftMandibleServoNum);
    mandibles[0].setServoPosition(leftMandibleServoPosition);
    mandibles[1].setServoNumber(rightMandibleServoNum);
    mandibles[1].setServoPosition(rightMandibleServoPosition);
}

/*
 * This function will be used to test the mandibles of the hexapod.
 * You can pass four pulse widths as arguments to determine how much the mandibles should open and close.
 * The first two determine how much the left and right mandibles should open,
 * The next two are how much they should close.
 */

void hexapodHead::testMandibles(int openLeftMandible, int openRightMandible, int closeLeftMandible, int closeRightMandible){
        mandibles[0].setServoPosition(openLeftMandible);
        mandibles[1].setServoPosition(openRightMandible);
        mandibles[0].writeToServo();
        Serial.println();
        mandibles[1].writeToServo();
        Serial.println();
        delay(1500);
        mandibles[0].setServoPosition(closeLeftMandible);
        mandibles[1].setServoPosition(closeRightMandible);
        mandibles[0].writeToServo();
        Serial.println();
        mandibles[1].writeToServo();
        Serial.println();
        delay(1500);
}

/*
 * This function will be used to test the servos on the neck of the hexapod that allows it to move its head left and right.
 * This can take two arguments to dictate how far left and right, respectively, the head should move.
 */

void hexapodHead::testLeftRight(int moveLeft, int moveRight){
        hexapodNeck[0].setServoPosition(moveLeft); // move the head all the way  to the left
        hexapodNeck[0].writeToServo();
        Serial.println();
        delay(1500); // delay for 1.5 seconds
        hexapodNeck[0].setServoPosition(moveRight); //move the head all the way to the right
        hexapodNeck[0].writeToServo();
        Serial.println();
        delay(1500); // delay for 1.5 seconds
}

/*
 * This function will be used to test the servos on the neck of the hexapod that allows it to move its head up and down.
 * This function takes two arguments to dictate how far up and down, respectively, the head should move.
 * The head will move up and down three times.
 */

void hexapodHead::testUpDown(int moveUp, int moveDown){
        hexapodNeck[1].setServoPosition(moveUp); // move the head all the way  to the left
        hexapodNeck[1].writeToServo();
        Serial.println();
        delay(1500); // delay for 1.5 seconds
        hexapodNeck[1].setServoPosition(moveDown); //move the head all the way to the right
        hexapodNeck[1].writeToServo();
        Serial.println();
        delay(1500); // delay for 1.5 seconds
}

/*
 * This function will be used to test the servos on the neck of the hexapod that allows it to rotate its neck.
 * This function takes two arguments to dictate how far left and right, respectively, the head should rotate.
 * The head will rotate left and right three times.
 */

void hexapodHead::testNeckRotation(int rotateLeft, int rotateRight){
    hexapodNeck[2].setServoPosition(rotateLeft); // move the head all the way  to the left
    hexapodNeck[2].writeToServo();
    Serial.println();
    delay(1500); // delay for 1.5 seconds
    hexapodNeck[2].setServoPosition(rotateRight); //move the head all the way to the right
    hexapodNeck[2].writeToServo();
    Serial.println();
    delay(1500); // delay for 1.5 seconds
}

/*
 * This function will test the previous test functions with one call.
 * It takes eight arguments to load up the four test functions.
 * The first four are for the testMandibles function.
 * The next two are for the testLeftRight function.
 * Followed by two more for the testUpDown function.
 * The final two are for the testNeckRotation function.
 */

void hexapodHead::testRun(int openLeftMandible, int openRightMandible, int closeLeftMandible, int closeRightMandible, int moveLeft, int moveRight, int moveUp, int moveDown, int rotateLeft, int rotateRight){
    testMandibles(openLeftMandible, openRightMandible, closeLeftMandible, closeRightMandible);
    testLeftRight(moveLeft, moveRight);
    testUpDown(moveUp, moveDown);
    testNeckRotation(rotateLeft, rotateRight);
}

/*
 * This function will set the initial position of the mandibles.
 * It takes two arguments: the first is for the left mandible position and the second is for the right mandible position.
 */

void hexapodHead::setUpMandibles(int leftMandiblePosition, int rightMandiblePosition){
    mandibles[0].setServoPosition(leftMandiblePosition);
    mandibles[1].setServoPosition(rightMandiblePosition);
    mandibles[0].writeToServo();
    Serial.println();
    mandibles[1].writeToServo();
    Serial.println();
    delay(1000);
}

/*
 * This function will set the initial position of the servo that allows the head to rotate left and right.
 * It takes one argument for the initial position of the servo that allows the head to rotate left and right.
 */

void hexapodHead::setUpRoationServo(int rotationposition){
    hexapodNeck[0].setServoPosition(rotationposition);
    hexapodNeck[0].writeToServo();
    Serial.println();
    delay(1000);
}

/*
 * This function will set the initial position of the servo that allows the head to move left and right.
 * It takes one argument for the initial position of the servo that allows the head to move left and right.
 */

void hexapodHead::setUpLRServo(int leftRightPosition){
    hexapodNeck[1].setServoPosition(leftRightPosition);
    hexapodNeck[1].writeToServo();
    Serial.println();
    delay(1000);
}

/*
 * This function will set the initial position of the servo that allows the head to move up and down.
 * It takes one argument for the initial position of the servo that allows the head to move up and down.
 */

void hexapodHead::setUpUDServo(int upDownposition){
    hexapodNeck[2].setServoPosition(upDownposition);
    hexapodNeck[2].writeToServo();
    Serial.println();
    delay(1000);
}

/*
 * This function will set the initial position of all the servos of the hexapod's head.
 * It takes 5 argument for the initial position of the left mandible, right mandible, the rotational servo, the left/right servo, and the up/down servo.
 */

void hexapodHead::setUpAll(int leftMandiblePosition, int rightMandiblePosition, int rotationPosition, int leftRightPosition, int upDownPosition){
    setUpMandibles(leftMandiblePosition,rightMandiblePosition);
    setUpRoationServo(rotationPosition);
    setUpLRServo(leftRightPosition);
    setUpUDServo(upDownPosition);
}

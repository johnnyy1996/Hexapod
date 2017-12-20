#include "Arduino.h"
#include "servoIO.h"

/*                      servoIO()                       */
/* This is the default constructor that sets the        */
/* initial position of the servo to 1500 (90 degrees)   */

servoIO::servoIO() {
  servo_position = 1500;
  not_reverse = 1;
}

/*                   servoIO(int pin)                   */
/* Input: pin - An integer representing the pin number  */
/* This is the constructor that sets the initial        */
/* position of the servo to 1500 and takes an integer   */
/* value and assigns it to the variable servo_number.   */

servoIO::servoIO(int pin) {
  servo_number = pin;
  servo_position = 1500;
  not_reverse = 1;
}

/*          void setServoNumer(int pin)                 */
/* Input: pin - An integer representing the pin number  */
/* This method assigns pin to the variable servo_number.*/

void servoIO::setServoNumber(int pin) {
  servo_number = pin;
  return;
}

/*           void setInputValue(double val)             */
/* Input: val - A double representing the value         */
/* obtained from the artifical neural network.          */
/* This method takes a double and assigns it to         */
/* the variable value.                                  */

void servoIO::setInputValue(double val) {
  value = val;
  return;
}

/*         void setServoPosition(int pos)               */
/* Input: pos - An integer representing the pulse width */
/* angular position of the servo.                       */
/* This method takes an integer and assigns the value   */
/* to the variable servo_position.                      */

void servoIO::setServoPosition(int pos) {
  servo_position = pos;
  return;
}

/*                   int convertInput()                  */
/* This method converts the variable value to an         */
/* integer servo_position from [500,2500].               */
/* It returns an integer representing a servo position.  */

int servoIO::convertInput() {
  int position_val = 2000 * value + 500;
  return position_val;
}

/*                void updateServoPosition()              */
/* This method saves the servo position after is has      */
/* been converted.                                        */

void servoIO::updateServoPosition() {
  servo_position = convertInput();
  return; 
}

/*                  void writeToServo()                   */
/* This method writes the movement command to the SSC-32  */
/* servo controller.                                      */

void servoIO::writeToServo() {
  Serial.print("#" + String(servo_number) + 
               "P" + String(servo_position));
  return;
}

/*                  bool isMovementCompleted()            */
/* This method obtains the query movement status of the   */
/* servo and checks if the movement has been completed    */
/* or if it is still in progress. Return true if movement */
/* is completed, false otherwise.                         */

bool servoIO::isMovementCompleted() {
  Serial.print("Q <cr>");
  if(Serial.read() == '.') { 
    return true;
  } else if(Serial.read() == '+') {
    return false;
  }
}

/*                   void setErrorFlag()                  */
/* This method sets the state of the error flag to true   */
/* or false.                                              */
void servoIO::setErrorFlag() {
  if(isMovementCompleted() == true) 
    error_flag = false;
  else error_flag = true;
  return;
}

/*
 * void setReverse(bool reverseMovement)
 * Decides whether the servo is reversed or not
 */
void servoIO::setReverse(bool reverseMovement){
  if(reverseMovement){
    not_reverse = -1;
  }
  else{
    not_reverse = 1;
  }
  return;
}

/*
 * int notReverse();
 * This method returns 1 if the servo moves as intended
 * and -1 if the servo moves in reverse
 */
int servoIO::notReverse(){
  return not_reverse;
}

/*
 * operator=(servoIO other)
 * This operator overload creates a way to equate one servoIO to another
 * This is also the function called when passing a servoIO
 */
servoIO servoIO::operator = (servoIO other){
  this->servo_number = other.servo_number;
  this->servo_position = other.servo_position;
  this->not_reverse = other.notReverse();
}


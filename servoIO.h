#include "Arduino.h"

#ifndef servoIO_h
#define servoIO_h 

class servoIO {
public:
  double value;                     // Input value provided by artificial neural network. Range is [0,1].
  int servo_number;                 // Corresponds to the pin number of the servo.
  int servo_position;               // This is the current position of the servo.

  bool error_flag;                  // This is the error flag that indicates whether the movement of the
                                    // servo has be completed. Returns 0 if movment is completed, 1 otherwise.

  servoIO();                        // This is the default constructor that initializes servo_pos on startup.
  servoIO(int);                     // This is the constructor that assigns the servo_number to the object 
                                    // and initializes the servo_pos on startup. 
  
  void setServoNumber(int);         // This method takes an integer and assigns the value to the variable
                                    // servo_number.
  void setInputValue(double);       // This method takes a double and assigns the value to the variable 
                                    // value.
  void setServoPosition(int);       // This method takes an integer and assigns the value to the variable 
                                    // servo_position.
  int convertInput();               // This method convertsthe variable value to an integer
                                    // servo_position from [500,2500].
  void updateServoPosition();       // This method saves the servo position after is has been converted.
  void writeToServo();              // This method writes the movement command to the SSC-32 servo controller.  
  bool isMovementCompleted();       // This method obtains the query movement status of the servo and
                                    // checks if the movement has been completed or if it is still in
                                    // progress. Return true if movement is completed, false otherwise.
  void setErrorFlag();              // This method sets the state of the error flag to true or false.     
};

#endif
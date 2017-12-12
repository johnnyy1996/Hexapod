/*
 * Author: Eric Li
 * This class is made to emulate the alternating tripod without the need
 * to constantly check back which servos is part of which tripod.
 */
#include "servoIO.h"

#ifndef DEFAULT_POSITION
#define DEFAULT_POSITION 1500
#endif

#ifndef TRIPOD_H
#define TRIPOD_H

class tripod{
  private:
  servoIO horizontalHip[3];
  servoIO verticalHip[3]; 
  servoIO knee[3];
  
  public:
  tripod();
  tripod(servoIO HH1, servoIO HH2, servoIO HH3,servoIO VH1, servoIO VH2, servoIO VH3, servoIO KN1, servoIO KN2, servoIO KN3);
  void lift();
  void forward();
  void down();
  void pushFoward();
  void diagonalR();
  void diagonalL();
};

#endif

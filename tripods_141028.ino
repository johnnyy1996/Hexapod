/****************************************************************************
Author: Amrik Singh
This program lets BotBoarduino send commands to lynxMotion SSC-32 board
to make hexapod robot move forward, which is an eight step(stage) process and
each step take 1 second to complete.
****************************************************************************/
void setup() {
  Serial.begin(115200); // begin communication using 115.2K baud rate
  while(!Serial){
    ;// wait while connecting
  }
}
/*************************************************************************
tripodA: right front leg(RFL), right rear leg(RRL) and left middle leg(LML)
tripodB: left front leg(LFL), left rear leg(LRL) and right middle leg(RML)
**************************************************************************/
void triPodA_pickUp(){
//pick up tripodA
  Serial.println( "#1P1700" //RRL
                  "#9P1700" //RFL
                  "#21P1300" //LML
                  "T1000"); //in 1000ms(1 sec)
    delay(2000); //2 seconds delay
}

void triPodA_forward(){
// bring tripodA to the front
  Serial.println( "#0P1700" //RRL
                  "#8P1650" //RFL
                  "#20P1300" //LML
                  "T1000");
   delay(2000);
}

void triPodA_onGround(){
// tripodA makes contact with ground
   Serial.println( "#1P1500" //RRL
                   "#9P1500" //RFL
                   "#21P1500" //LML
                   "T1000");
    delay(2000);
}

void triPodA_push(){
// brings back tripodA to the neutral position, while pushing on the ground
// tripodA moves the robot forward
  Serial.println( "#0P1500" //RRL
                  "#8P1500" //RFL
                  "#20P1500" //LML
                  "T1000");
    delay(2000);
}

void triPodB_pickUp(){
// pick up triPodB
  Serial.println( "#5P1700" //RML
                  "#17P1300" //LRL
                  "#25P1300" //LFL
                  "T1000");
    delay(2000);
}

void triPodB_forward(){
// bring tripodB to the front
  Serial.println( "#16P1300" //LRL
                  "#24P1350" //LFL
                  "#4P1700" //RML
                  "T1000");
    delay(2000);
}

void triPodB_onGround(){
// tripodB makes contact with ground
   Serial.println( "#17P1500" //LRL
                   "#25P1500" //LFL
                   "#5P1500" //RML
                   "T1000");
    delay(2000);
}

void triPodB_push(){
// bring back tripodV to the neutral position, while pushing on the ground
// tripodB moves the robot forward
  Serial.println( "#16P1500" //LRL
                  "#24P1500" //LFL
                  "#4P1500" //RML
                  "T1000");
//delay(2000);
}

void loop() {
/************************************************************************************************
repeat the sequence to make hexapod walk forward
in which it picks up tripodA, bring to the front, brings tripodA on ground to hold the weight
and pick up tripodB, bring to the front, and "tripodA" push robot forward
and next tripodB makes contact with ground, also push robot forward
*************************************************************************************************/
  triPodA_pickUp();
  triPodA_forward();
  triPodA_onGround();
  triPodB_pickUp();
  triPodB_forward();
  triPodA_push();
  triPodB_onGround();
  triPodB_push();
}

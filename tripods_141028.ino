/* Amrik Singh*/
void setup() {
  Serial.begin(115200); // begin communication
  while(!Serial){ // wait while connecting
    ;
  }
}
void triPodAF(){
  //pick up right front and rear leg
  // and pick left middle leg
  // being it to front
  Serial.println("#1P1700#0P1700#9P1700#8P1700#20P1300#21P1300T500"); // in 500ms second
  delay(2000);
}
void triPodAG(){// tripodA on ground
 Serial.println("#1P1500#9P1500#21P1500T500");
 delay(2000);
}
void triPodAP(){ //tripodA push legs back // come to neutral position
  Serial.println("#0P1500#8P1500#20P1500T500");
  delay(2000);
}
void triPodBF(){
// tripodB picks up left front and rear leg with right middle legt
 Serial.println("#17P1300#16P1300#25P1300#24P1300#5P1700#4P1700T500");
 delay(2000);
}
void triPodBG(){// tripodB on the ground
 Serial.println("#17P1500#25P1500#5P1500T500"); 
 delay(2000);
}
void triPodBP(){// tripodB pushes // come to neutral position
 Serial.println("#16P1500#24P1500#4P1500T500"); 
 //delay(2000);
}
void loop() {
  triPodAF();//A forward
  triPodAG();//A ground
  triPodBF();//B forward
  triPodAP();//A push
  triPodBG();//B ground
  triPodBP();//B push
}

#include <ZumoShield.h>

ZumoMotors motors;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  motors.setLeftSpeed(200);
  motors.setRightSpeed(190);
  delay(5000);
  motors.setLeftSpeed(0);
  motors.setRightSpeed(0);
  while(true){
    
  }

}

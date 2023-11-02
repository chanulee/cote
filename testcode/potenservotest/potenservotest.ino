#include "PCA9685.h"
#include <Wire.h>

ServoDriver servo;
const int POTEN_PIN = A0;

const int X_PIN = A1;
const int Y_PIN = A2;

int xValue;
int yValue; 
int xAngle = 90;
int yAngle = 90;

void setup() {
    // join I2C bus (I2Cdev library doesn't do this automatically)
    Wire.begin();
    Serial.begin(9600);
    servo.init(0x7f);
    // uncomment this line if you need to use a special servo
    // servo.setServoPulseRange(600,2400,180);
}

void loop() {
    // Drive 8 servos in turns
    int potentioMeter = analogRead(POTEN_PIN);
    // Serial.print("poten:");
    // Serial.println(potentioMeter);
    int servoAngle = map(potentioMeter, 0,650,0,180);
    // Serial.print("angle:");
    // Serial.println(servoAngle);
    
  xValue = analogRead(X_PIN) ;  
  yValue = analogRead(Y_PIN) ; 

  // //back-forth
  // xAngle = map(xValue,150,1000,70,150);
  // //height
  // yAngle = map(yValue,150,1000,20,90);
  
  if(150 < xValue < 525){
    if(70 < xAngle - xValue/100){
      xAngle = xAngle - xValue/100;
      servo.setAngle(2, xAngle);
      int pastxAngle = xAngle;
    }
  } else if(625 < xValue < 1000) {
      if(xAngle + xValue/100 < 150){
      xAngle = xAngle + xValue/100;
      servo.setAngle(2, xAngle);
      int pastxAngle = xAngle;
    }
  }


  if(150 < yValue < 525){
    if(20 < yAngle - yValue/100){
      yAngle = yAngle - yValue/100;
      servo.setAngle(2, yAngle);
      int pastyAngle = yAngle;
    }
  } else if(625 < yValue < 1000) {
      if(yAngle + yValue/100 < 90){
      yAngle = yAngle + yValue/100;
      servo.setAngle(2, yAngle);
      int pastyAngle = yAngle;
    }
  }



// Serial.print(xAngle);
// Serial.print(",");
// Serial.println(yAngle);

    servo.setAngle(1, servoAngle);
    delay(100);
    

}
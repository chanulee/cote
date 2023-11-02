#include <Servo.h>

Servo servo;
Servo servoSet1;
Servo servoSet2;
Servo servoSet3;
// twelve servo objects can be created on most boards

unsigned long previousMillis = 0;
const long interval = 250;  // Interval in milliseconds
int i = 45;
bool ascending = true;

void setup() {
  Serial.begin(115200);
  Serial.println("Serial INIT");
}

void loop() {
if (Serial.available()>0) {
    // Serial.println("Serial working");

    /*---read from oF---*/
    int serialAngle = Serial.read() - '0' + 48;

    int angleMap = map(serialAngle, 0,254,0,270); //0 to 135 and 135 to 270

    servoSync(angleMap, 15, 16, 17, 18); //small right

  } 
}

/*--- Simple servo control ---*/
void servoControl(int leftAngle, int leftMotor, int rightMotor){
  if (leftAngle > 135) {
    servo.detach();
    servo.attach(leftMotor);
    servo.writeMicroseconds(map(leftAngle - 89,47,181,1000,2450));
    // Serial.print("L ");
    // Serial.println(map(leftAngle - 89,47,181,1000,2000));
  } else {
    int rightAngle = leftAngle;
    // Serial.println(rightAngle);
    servo.detach();
    servo.attach(rightMotor);
    servo.writeMicroseconds(map(rightAngle,0,135,600,2000));
    // Serial.print("R ");
    // Serial.println(map(rightAngle,0,135,1000,2000));
  }
}

/*--- Move multiple motors together---*/
void servoSync(int leftAngle, int lM1, int rM1, int lM2, int rM2, int lM3, int rM3){
  servoSetDetach();
  if (leftAngle > 135) {
    servoLeftMove(leftAngle, lM1, lM2, lM3);
  } else {
    int rightAngle = leftAngle;
    servoRightMove(rightAngle,rM1, rM2, rM3 )
  }
}

void servoSetDetach() {
    servoSet1.detach();
    servoSet2.detach();
    servoSet3.detach();
}

void servoLeftMove(int leftAngle, int lM1, int lM2, int lM3){
    servoSet1.attach(lM1);
    servoSet2.attach(lM2);
    servoSet3.attach(lM3);

    servoSet1.writeMicroseconds(map(leftAngle - 89,47,181,1000,2450));
    servoSet2.writeMicroseconds(map(leftAngle - 89,47,181,1000,2450));
    servoSet3.writeMicroseconds(map(leftAngle - 89,47,181,1000,2450));
}

void servoRightMove(int rightAngle, int rM1, int rM2, int rM3){
    servoSet1.attach(rM1);
    servoSet2.attach(rM2);
    servoSet3.attach(rM3);

    servoSet1.writeMicroseconds(map(rightAngle,0,135,600,2000));
    servoSet2.writeMicroseconds(map(rightAngle,0,135,600,2000));
    servoSet3.writeMicroseconds(map(rightAngle,0,135,600,2000));
}

// void breathe(int leftMotor, int rightMotor){
void breathe(){
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (ascending) {
      i++;
      if (i >= 135) ascending = false;
    } else {
      i--;
      if (i <= 45) ascending = true;
    }
    // servoControl(i, leftMotor, rightMotor);
    Serial.println(i);
  }

}

// JUST IN CASE //

// void zenBreathe(int leftAngle){
//   // everything in sync
//   servoControl(angleMap, 5, 6);
//   servoControl(angleMap, 5, 6);
//   servoControl(angleMap, 5, 6);
// }


// SETTINGS //
void initialSet(int leftMotor, int rightMotor){
  servo.attach(leftMotor);
  servo.attach(rightMotor);
  servo.write(0);
}

/*
EXPIRED 
*/

// void motorControl180(int leftAngle, int leftMotor, int rightMotor){
//     if (leftAngle > 135) {
//       servo.detach();
//       servo.attach(leftMotor);
//       servo.write(leftAngle - 89);

//     } else {
//       int rightAngle = leftAngle;
//       // Serial.println(rightAngle);
//       servo.detach();
//       servo.attach(rightMotor);
//       servo.write(rightAngle);
//     }
// }
#include <Servo.h>

Servo servo;
// twelve servo objects can be created on most boards


void setup() {
  Serial.begin(115200);
  Serial.println("Serial INIT");
}

void loop() {

if (Serial.available()>0) { //when serial works
    // read from oF
    Serial.println("Serial working");
    
    int serialAngle = Serial.read() - '0' + 48;
    int angleMap = map(leftAngle, 0,254,0,270); //0 to 135 and 135 to 270

    servoControl(angleMap, 5, 6);

  } 

}

void servoControl(int leftAngle, int leftMotor, int rightMotor){
  if (leftAngle > 135) {
    servo.detach();
    servo.attach(leftMotor);
    servo.writeMicroseconds(map(leftAngle - 89,47,181,1000,2000));
    // Serial.print("L ");
    // Serial.println(map(leftAngle - 89,47,181,1000,2000));
  } else {
    int rightAngle = leftAngle;
    // Serial.println(rightAngle);
    servo.detach();
    servo.attach(rightMotor);
    servo.writeMicroseconds(map(rightAngle,0,135,1000,2000));
    // Serial.print("R ");
    // Serial.println(map(rightAngle,0,135,1000,2000));
  }
}

// SETTINGS //
void initialSet(int leftMotor, int rightMotor){
  servo.attach(leftMotor);
  servo.attach(rightMotor);
  servo.write(0);
}

// EXPIRED //
void motorControl180(int leftAngle, int leftMotor, int rightMotor){
    if (leftAngle > 135) {
      servo.detach();
      servo.attach(leftMotor);
      servo.write(leftAngle - 89);

    } else {
      int rightAngle = leftAngle;
      // Serial.println(rightAngle);
      servo.detach();
      servo.attach(rightMotor);
      servo.write(rightAngle);
    }
}
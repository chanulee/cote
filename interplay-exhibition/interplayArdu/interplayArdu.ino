#include <Servo.h>

/*---Servo Declare---*/
// twelve servo objects can be created on most boards
Servo servoSet1;
int lM1 = 15;
int rM1 = 16;
Servo servoSet2;
int lM2 = 17;
int rM2 = 18;
Servo servoSet3;
int lM3 = 19;
int rM3 = 20;

int angle = 0;

/*---State---*/
// enum State {
//   Idle,
//   Ascending,
//   BigBreathe,
//   Descending,
//   Idle2,
//   Ascending2,
//   BigBreathe2,
//   Descending2
// };
// State state = Idle;

/*---State in number---*/
int state = 3;
/*
  3Idle,
  4Ascending,
  5BigBreathe,
  6Descending,
  7Idle2,
  8Ascending2,
  9BigBreathe2,
  10Descending2
*/

/*---Time Management---*/
unsigned long previousMillis = 0;
const long interval = 13;  // Interval in milliseconds
bool inhale = true;

int wekClass = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Serial INIT");
}

void loop() {
if (Serial.available()>0) {
  // Serial.println("Serial working");

  /*---read from oF---*/
  wekClass = Serial.read() - '0' + 48; // 1 or 2
  Serial.println(wekClass);

  switch (state) {
    case 3: //Idle 
      breathe(5, 25);  //5 sec
      if (wekClass == 2) {
        state = 4;
      }
      break;
    case 4: //Ascending 
      if (angle < 105) {
        angle++;
        servoSync(angle);
      } else {
        state = 5;
      }
      break;
    case 5: //BigBreathe
      breathe(105, 130);  // Big breathe range
      if (wekClass == 1) {
        state = 6;
      }
      break;
    case 6: //Descending
      if (angle < 245) {
        angle++;
        servoSync(angle);
      } else {
        state = 7;
      }
      break;
    case 7: //Idle2
      breathe(245, 265); 
      if (wekClass == 2) {
        state = 8;
      }
      break;
    case 8: //Ascending2
        Serial.println(state);
      if (angle > 138) {
        angle--;
        servoSync(angle);
      } else {
        state = 9;
      }
      break;
    case 9: //Big breathe2
      breathe(138, 165);  // Big breathe range
      if (wekClass == 1) {
        state = 10;
      }
      break;
    case 10: //Descending2
      if (angle > 5) {
        angle--;
        servoSync(angle);
      } else {
        state = 3;
      }
      break;

    } //switch
  } //if
  // else {
  //   long interval = 50000;  // Interval in milliseconds
  //   breathe(5, 25); 
  //   state = 3;
  // }
} // loop

void breathe(int minAng, int maxAng) {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (inhale) {
      angle++;
      if (angle >= maxAng) inhale = false;
    } else {
      angle--;
      if (angle <= minAng) inhale = true;
    }
    servoSync(angle);
    // Serial.println(i);
  }
}


/*--- Move multiple motors together---*/
void servoSync(int leftAngle){
  servoSetDetach();
  if (leftAngle > 138) {
    servoLeftMove(leftAngle);
  } else {
    int rightAngle = leftAngle;
    servoRightMove(rightAngle);
  }
}

/*--- Basic Controls ---*/
void servoSetDetach() {
    servoSet1.detach();
    servoSet2.detach();
    servoSet3.detach();
}

void servoLeftMove(int leftAngle){
    servoSet1.attach(lM1);
    servoSet2.attach(lM2);
    servoSet3.attach(lM3);

    servoSet1.writeMicroseconds(map(leftAngle - 89,47,181,1000,2450));
    servoSet2.writeMicroseconds(map(leftAngle - 89,47,181,1000,2450));
    servoSet3.writeMicroseconds(map(leftAngle - 89,38,172,1000,2450)); //247-89
}

void servoRightMove(int rightAngle){
    servoSet1.attach(rM1);
    servoSet2.attach(rM2);
    servoSet3.attach(rM3);

    servoSet1.writeMicroseconds(map(rightAngle,0,135,600,2000));
    servoSet2.writeMicroseconds(map(rightAngle,0,135,600,2000));
    servoSet3.writeMicroseconds(map(rightAngle,0,135,600,2000));
}

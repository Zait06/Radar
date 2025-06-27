#include <Servo.h>

Servo myServo;
const int servoPin = 9;   // pin
int servoAng = 180; // grade
bool toZero = true;

void setup() {
  myServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  myServo.write(servoAng);
  servoAng += toZero ? -20 : 20;
  if (servoAng <= 0) toZero = false;
  else if (servoAng >= 170) toZero = true;
  delay(500);
}

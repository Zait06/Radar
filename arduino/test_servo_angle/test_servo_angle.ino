#include <Servo.h>

Servo myServo;
const int servoPin = 9;   // pin
int servoAng = 0; // grade

void setup() {
  myServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  myServo.write(servoAng);
}

/**
  * @file        radar.ino
  * @author      Zait Hernández
  * @date        2025-06-26
  * @brief       This program emulates a radar.
  * @version     1.0.0
  * @device      Arduino Uno
*/

#include <Servo.h>

const int servoPin = 7;
const int trigPin = 8;
const int echoPin = 9;
const int buzzerPin = 6;

const int startAngle = 60;  // Degrees

enum ServoDirection {
  Clockwise = -1,
  Counterclockwise = 1
};

char buffer[100];
Servo m_servo;

int computeDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  return duration / 58;
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  m_servo.attach(servoPin);
}

void rotateServo(ServoDirection direction) {
  int distance = 0;
  int baseAngle = direction == ServoDirection::Clockwise ? 180 : 0;
  for (int angle = startAngle; angle <= 180 - startAngle; angle++) {
    int servoAngle = baseAngle + (direction * angle);
    
    m_servo.write(servoAngle);
    distance = computeDistance();
    delay(50);

    if (distance <= 10) {
      digitalWrite(buzzerPin, HIGH);
    } else {
      digitalWrite(buzzerPin, LOW);
    }

    sprintf(buffer, "%d,%d\r", servoAngle, distance);
    Serial.write(buffer);
  }
}

void loop() {
  rotateServo(ServoDirection::Counterclockwise);
  rotateServo(ServoDirection::Clockwise);
}
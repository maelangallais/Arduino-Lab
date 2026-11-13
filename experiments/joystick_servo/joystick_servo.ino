/*
Le but de ce script est de faire bouger un servomoteur en fonction du mouvement du joystick. C'est un script très simple.
*/
#include <Servo.h>
Servo monServo;

void setup() {
  monServo.attach(9);
}

void loop() {
  int joystickValue = analogRead(A0);
  int servoAngle = map(joystickValue, 0, 1023, 0, 180);
  monServo.write(servoAngle);
}

/*
  Le but du script est d'automatiser le jeu du Dino.
  On va détecter des obstacles avec la photorésistance et faire sauter le dino immédiatement avec un servomoteur.
*/
#include <Servo.h>

Servo servo;

const byte photocell=A0;

void setup() {
  servo.attach(8);
  servo.write(120);
}

void loop() {
  int luminosity=analogRead(photocell);
  if (luminosity<120) {
    servo.write(135);
    delay(200);
    servo.write(120);
  }
}

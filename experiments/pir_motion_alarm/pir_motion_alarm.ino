/*
Ce script sert à détecter un mouvement grâce au PIR Sensor Module et allumer une led et un active buzzer qui vont créer l'alerte.
*/

const byte PIR=7;
const byte led=8;
const byte alarm=9;

void setup() {
  pinMode(PIR,INPUT);
  pinMode(led,OUTPUT);
  pinMode(alarm,OUTPUT);
  digitalWrite(led,HIGH);
  delay(10000);
  digitalWrite(led,LOW);
}

void loop() {
  bool trigger=digitalRead(PIR);
  if (trigger==HIGH){
    int start=millis();
    while (true){
      if (millis()-start<=500){
        digitalWrite(alarm,HIGH);
        digitalWrite(led,HIGH);
      }
      else if (millis()-start<=1000){
        digitalWrite(alarm,LOW);
        digitalWrite(led,LOW);
      }
      else{
        start=millis();
      }
    } 
  }
}

/*
Le but de ce script est de faire varier les couleurs d'une bande de leds RGB. C'est extrêmement basique et ne requiert aucuns input.
*/
const byte R=12;
const byte G=10;
const byte B=8;

void setup() {
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
  analogWrite(R,255);
  analogWrite(G,255);
  analogWrite(B,255);
}

void loop() {
  for (int i=0;i<255;i++){
    analogWrite(R,0);
    analogWrite(G,0+i);
    analogWrite(B,0+i);
    delay(1*0.05*i);
    }
  for (int i=255;i>0;i--){
    analogWrite(R,0);
    analogWrite(G,0+i);
    analogWrite(B,0+i);
    delay(1*0.05*i);
    }
  for (int i=0;i<255;i++){
    analogWrite(R,0+i);
    analogWrite(G,0);
    analogWrite(B,0+i);
    delay(1*0.05*i);
    }
  for (int i=255;i>0;i--){
    analogWrite(R,0+i);
    analogWrite(G,0);
    analogWrite(B,0+i);
    delay(1*0.05*i);
    }
  for (int i=0;i<255;i++){
    analogWrite(R,0+i);
    analogWrite(G,0+i);
    analogWrite(B,0);
    delay(1*0.05*i);
    }
  for (int i=255;i>0;i--){
    analogWrite(R,0+i);
    analogWrite(G,0+i);
    analogWrite(B,0);
    delay(1*0.05*i);
    }
}

/*
Le but de ce script est de capter si un gros bruit se produit et d'allumer ou d'éteindre le courant d'un bande de leds RGB, par exemple.
L'information ne passe que par la broche DigitalPWM car le module est très peu sensible et la valeur du bruit ne change quasiment pas.
C'est un petit script, mais il a une très grande utilité.
*/
const int digitalSoundPin=8;
const int controlRelayPin=7;
bool digitalsound=LOW;
bool relayState=LOW;

void setup() {
  pinMode(digitalSoundPin, INPUT);
  pinMode(controlRelayPin,OUTPUT);
  digitalWrite(controlRelayPin,relayState);
}

void loop() {
  digitalsound=digitalRead(digitalSoundPin);  
  if (digitalsound==HIGH){
    delay(100);
    if (relayState==LOW){
      digitalWrite(controlRelayPin,HIGH);
      relayState=HIGH;
    }
    else if (relayState==HIGH){
      digitalWrite(controlRelayPin,LOW);
      relayState=LOW;
    }
  }
}

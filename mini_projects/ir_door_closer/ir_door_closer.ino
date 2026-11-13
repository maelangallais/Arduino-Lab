/*
  Ce script utilise l'IRemote receiver et le Stepper Motor pour fermer une porte à distance en rembobinant un fil attacher
  de cette dernière au Stepper Motor de l'autre côté de la porte. Malheureusement, le script fonctionne sans soucis mais il
  est difficile d'attacher quelque chose au Stepper Motor et qu'il tienne nonobstant la résistance du câble et du poids de la porte.
*/

#include <IRremote.h>
#include <Stepper.h>

const byte IRemote=7;
decode_results resultat;
IRrecv irrecv(IRemote);
#define STEPS 32
int Steps;
Stepper stepper(STEPS,8,10,9,11);

void setup() {
  irrecv.enableIRIn();
}

long unsigned int HEXIR[22]={0xFFFFFFFF,
  0xFFA25D,0xFF629D,0xFFE21D,
  0xFF22DD,0xFF02FD,0xFFC23D,
  0xFFE01F,0xFFA857,0xFF906F,
  0xFF6897,0xFF9867,0xFFB04F,
  0xFF30CF,0xFF18E7,0xFF7A85,
  0xFF10EF,0xFF38C7,0xFF5AA5,
  0xFF42BD,0xFF4AB5,0xFF52AD,
};
const char* touche[22]={"Erreur systeme!",
  "Allumer/Eteindre","Volume +","Fonction/Stop",
  "Arriere rapide","Pause","Avance rapide",
  "Bas","Volume -","Haut",
  "0","EQ","ST/REPT",
  "1","2","3",
  "4","5","6",
  "7","8","9",
};

void loop() {
  if (irrecv.decode(&resultat)){
    if (resultat.value==HEXIR[4]){
      stepper.setSpeed(1000);
      Steps=-2048;
      stepper.step(Steps);
    }
    else if (resultat.value==HEXIR[6]){
      stepper.setSpeed(1000);
      Steps=2048;
      stepper.step(Steps);
    }
    irrecv.resume();
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  }
}

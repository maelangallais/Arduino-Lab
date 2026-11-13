/*
  Le but de ce script est de lire un badge RFID grâce au module RFID et d'afficher l'uid de ce badge
  dans le moniteur série. Cela sert à connaître l'uid de son badge, ce qui peut être très utile.
  Il faut brancher les câbles (respectivement de SDA vers 3.3V) sur ces pins : 20, 52, 51, 50, null, GND, "à définir" et 3.3V
*/
#include <SPI.h>
#include <MFRC522.h>

const int pinRST = 53; // pin RST du module RC522
const int pinSDA = 20; // pin SDA du module RC522
MFRC522 rfid(pinSDA, pinRST);
void setup()
{
SPI.begin();
rfid.PCD_Init();
Serial.begin(9600);
}
void loop()
{
if (rfid.PICC_IsNewCardPresent()) // on a dédecté un tag
{
if (rfid.PICC_ReadCardSerial()) // on a lu avec succès son contenu
{
Serial.println("Voici l'UID de ce tag en decimal :");
Serial.print("const byte bonUID[");
Serial.print(rfid.uid.size);
Serial.print("] = {");
for (byte i = 0; i < rfid.uid.size; i++)
{
Serial.print(rfid.uid.uidByte[i]);
if (i < rfid.uid.size - 1)
{
Serial.print(", ");
}
else
Serial.println("};");
}
Serial.println();
delay (2000);
}
}
}

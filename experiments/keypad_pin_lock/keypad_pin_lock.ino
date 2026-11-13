/*
Le but de ce script est de devoir taper un code sur la membrane. Le résultat sera affiché sur l'écran LCD. Le code est enregistré dans la fonction loop().
*/
#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(22, 26, 30, 34, 38, 42);

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);


void setup() {
  lcd.begin(16, 2);  //écran LCD avec 16 colonnes et 2 lignes
  lcd.clear();
  Serial.begin(9600);
}

void loop() {
  char codeSecret[4] = {'1', '2', '3', '4'}; //code secret : 1234
  char codeSaisi[4];  //nombre de chiffre dans le code secret
  char* chiffre[4] = {"1er","2eme","3eme","4eme"};//A afficher
  
  bool codeValide = true; // variable "booléenne" pour enregistrer le code tapé

  for (int i=0;i<4;i++){
    lcd.print("Entrez le ");
    lcd.print(chiffre[i]);
    lcd.setCursor(0,1);
    lcd.print("chiffre : ");
    char key = customKeypad.getKey(); //récupérer la touche appuyée sur le clavier
    while (key == NO_KEY) { //attendre que l'utilisateur appuie sur une touche
      key = customKeypad.getKey();
    }
    codeSaisi[i] = key; //incrémente le code saisi de la valeur demandée
    lcd.print(codeSaisi[i]); //afficher le chiffre saisi
    delay(500); //attendre un court instant pour éviter les saisies multiples
    lcd.clear();
  }


  for (int i=0;i<4;i++){
    if (codeSaisi[i] != codeSecret[i]) {
      codeValide = false; // le code saisi est incorrect
      break; // arrêtez la boucle
    }
  }

  if (codeValide) {
    lcd.print("Code bon !"); // affiche "code bon" sur l'écran LCD
  } else {
    lcd.print("Code errone !"); // affiche "code erroné" sur l'écran LCD
  }
  delay(3000);
  lcd.clear();
}

/*
Ce script est pirement fun. Le fonctionnement est que chaque bouton de la membrane est relié à un carré de 2*2 leds du module Max7219.
*/
#include <LedControl.h>
#include <Keypad.h>

const int max7219_din = 12; // Broche DIN du module MAX7219
const int max7219_cs = 11; // Broche CS du module MAX7219
const int max7219_clk = 10; // Broche CLK du module MAX7219

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

bool state[4][4] = {{false, false, false, false}, // Tableau de l'état de chaque carré
                    {false, false, false, false},
                    {false, false, false, false},
                    {false, false, false, false}};

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

LedControl lc=LedControl(12,10,11,1);

void setup() {
  lc.shutdown(0, false); // Activation du module MAX7219
  lc.setIntensity(0, 8); // Règle l'intensité de l'affichage
  lc.clearDisplay(0); // Efface l'affichage
}

void loop() {
  char customKey = customKeypad.getKey();
  
  if (customKey=='1'){
    state[0][0] = !state[0][0];
    lc.setLed(0, 0, 0, state[0][0]);
    lc.setLed(0, 0, 1, state[0][0]);
    lc.setLed(0, 1, 0, state[0][0]);
    lc.setLed(0, 1, 1, state[0][0]);
  }
  else if (customKey=='2'){
    state[0][1] = !state[0][1];
    lc.setLed(0, 0, 2, state[0][1]);
    lc.setLed(0, 0, 3, state[0][1]);
    lc.setLed(0, 1, 2, state[0][1]);
    lc.setLed(0, 1, 3, state[0][1]);
  }
  else if (customKey=='3'){
    state[0][2] = !state[0][2];
    lc.setLed(0, 0, 4, state[0][2]);
    lc.setLed(0, 0, 5, state[0][2]);
    lc.setLed(0, 1, 4, state[0][2]);
    lc.setLed(0, 1, 5, state[0][2]);
  }
  else if (customKey=='A'){
    state[0][3] = !state[0][3];
    lc.setLed(0, 0, 6, state[0][3]);
    lc.setLed(0, 0, 7, state[0][3]);
    lc.setLed(0, 1, 6, state[0][3]);
    lc.setLed(0, 1, 7, state[0][3]);
  }
  else if (customKey=='4'){
    state[1][0] = !state[1][0];
    lc.setLed(0, 2, 0, state[1][0]);
    lc.setLed(0, 2, 1, state[1][0]);
    lc.setLed(0, 3, 0, state[1][0]);
    lc.setLed(0, 3, 1, state[1][0]);
  }
  else if (customKey=='5'){
    state[1][1] = !state[1][1];
    lc.setLed(0, 2, 2, state[1][1]);
    lc.setLed(0, 2, 3, state[1][1]);
    lc.setLed(0, 3, 2, state[1][1]);
    lc.setLed(0, 3, 3, state[1][1]);
  }
  else if (customKey=='6'){
    state[1][2] = !state[1][2];
    lc.setLed(0, 2, 4, state[1][2]);
    lc.setLed(0, 2, 5, state[1][2]);
    lc.setLed(0, 3, 4, state[1][2]);
    lc.setLed(0, 3, 5, state[1][2]);
  }
  else if (customKey=='B'){
    state[1][3] = !state[1][3];
    lc.setLed(0, 2, 6, state[1][3]);
    lc.setLed(0, 2, 7, state[1][3]);
    lc.setLed(0, 3, 6, state[1][3]);
    lc.setLed(0, 3, 7, state[1][3]);
  }
  else if (customKey=='7'){
    state[2][0] = !state[2][0];
    lc.setLed(0, 4, 0, state[2][0]);
    lc.setLed(0, 4, 1, state[2][0]);
    lc.setLed(0, 5, 0, state[2][0]);
    lc.setLed(0, 5, 1, state[2][0]);
  }
  else if (customKey=='8'){
    state[2][1] = !state[2][1];
    lc.setLed(0, 4, 2, state[2][1]);
    lc.setLed(0, 4, 3, state[2][1]);
    lc.setLed(0, 5, 2, state[2][1]);
    lc.setLed(0, 5, 3, state[2][1]);
  }
  else if (customKey=='9'){
    state[2][2] = !state[2][2];
    lc.setLed(0, 4, 4, state[2][2]);
    lc.setLed(0, 4, 5, state[2][2]);
    lc.setLed(0, 5, 4, state[2][2]);
    lc.setLed(0, 5, 5, state[2][2]);
  }
  else if (customKey=='C'){
    state[2][3] = !state[2][3];
    lc.setLed(0, 4, 6, state[2][3]);
    lc.setLed(0, 4, 7, state[2][3]);
    lc.setLed(0, 5, 6, state[2][3]);
    lc.setLed(0, 5, 7, state[2][3]);
  }
  else if (customKey=='*'){
    state[3][0] = !state[3][0];
    lc.setLed(0, 6, 0, state[3][0]);
    lc.setLed(0, 6, 1, state[3][0]);
    lc.setLed(0, 7, 0, state[3][0]);
    lc.setLed(0, 7, 1, state[3][0]);
  }
  else if (customKey=='0'){
    state[3][1] = !state[3][1];
    lc.setLed(0, 6, 2, state[3][1]);
    lc.setLed(0, 6, 3, state[3][1]);
    lc.setLed(0, 7, 2, state[3][1]);
    lc.setLed(0, 7, 3, state[3][1]);
  }
  else if (customKey=='#'){
    state[3][2] = !state[3][2];
    lc.setLed(0, 6, 4, state[3][2]);
    lc.setLed(0, 6, 5, state[3][2]);
    lc.setLed(0, 7, 4, state[3][2]);
    lc.setLed(0, 7, 5, state[3][2]);
  }
  else if (customKey=='D'){
    state[3][3] = !state[3][3];
    lc.setLed(0, 6, 6, state[3][3]);
    lc.setLed(0, 6, 7, state[3][3]);
    lc.setLed(0, 7, 6, state[3][3]);
    lc.setLed(0, 7, 7, state[3][3]);
  }
  delay(250);
}

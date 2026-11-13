/*
  Control 8 LEDs using a 74HC595 shift register (3 digital pins) via the Serial Monitor.
  Send 1-8 to toggle a specific LED, or 0 to turn all LEDs off.
*/
const int latchPin = 11;  // Latch pin (ST_CP)
const int clockPin = 9;   // Clock pin (SH_CP)
const int dataPin = 12;   // Data pin (DS)

byte ledState = 0;        // Bitmask storing the state of all 8 LEDs

void updateShiftRegister(byte state) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, state);
  digitalWrite(latchPin, HIGH);
}

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  updateShiftRegister(ledState);  // Turn off all LEDs on startup
  Serial.begin(9600);
  Serial.println("Enter a LED number (1-8) to toggle, or 0 to turn all off:");
}

void loop() {
  if (Serial.available() > 0) {
    int ledNumber = Serial.parseInt();

    // Clear trailing newline/carriage return characters from the serial buffer
    while (Serial.available() > 0) {
      Serial.read();
    }

    if (ledNumber >= 1 && ledNumber <= 8) {
      // Toggle the corresponding bit (0-indexed)
      ledState ^= (1 << (ledNumber - 1));
      updateShiftRegister(ledState);

      Serial.print("LED ");
      Serial.print(ledNumber);
      Serial.print(" -> ");
      Serial.println(bitRead(ledState, ledNumber - 1) ? "ON" : "OFF");
    } else if (ledNumber == 0) {
      ledState = 0;
      updateShiftRegister(ledState);
      Serial.println("All LEDs -> OFF");
    } else {
      Serial.println("Invalid input. Enter 1-8 to toggle, or 0 to turn all off.");
    }
  }
}

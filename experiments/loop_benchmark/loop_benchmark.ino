/*
Ce script sert à compter le nombre d'itérations que peut faire la carte Arduino en 1 seconde.
*/
int r = 0;
float t = millis();

void setup() {
  Serial.begin(9600);
}

void loop() {
  while (true) {
    r += 1;
    if (millis() - t > 1000 and millis() - t < 1100) {
      Serial.println(r);
      break;
    }
  }
}

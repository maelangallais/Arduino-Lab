/*
  Ce code utilise les cpateurs Digital Humidity and Temperature et Liquid Crystal Display
  qui permettent de calculer l'humidité et de l'afficher sur l'écran LCD.
*/

#include <dht_nonblocking.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(6,7,9,10,11,12);
#define DHT_type DHT_TYPE_11
const int DHT_pin=4;
DHT_nonblocking dht_sensor(DHT_pin, DHT_type);

void setup(){
  lcd.begin(16,2);
}

void loop(){
  if (dht_sensor.read_nonblocking()==true){
    int humidity=dht_sensor.read_humidity();
    lcd.clear();
    lcd.print("Humidite : ");
    lcd.print(humidity);
    lcd.print(" %");
    delay(1000);
  }
}

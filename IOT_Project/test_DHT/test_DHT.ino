// #include <DHT.h>

// #define DHTPIN 2
// #define DHTTYPE DHT11

// DHT dht(DHTPIN, DHTTYPE);

// void setup() {
//   Serial.begin(9600);
//   dht.begin();
// }

// void loop() {
//   float t = dht.readTemperature();
//   Serial.println(t);
//   delay(2000);
// }

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("HELLO");
}

void loop() {}
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// -------------------- PIN DEFINITIONS --------------------
#define DHTPIN 2
#define DHTTYPE DHT11

#define LDR_PIN A0
#define SOUND_PIN A1
#define MQ135_PIN A2

#define RELAY_PIN 7

// -------------------- OBJECTS --------------------
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Change address if needed

// -------------------- VARIABLES --------------------
float temperature = 0;
float humidity = 0;

int lightValue = 0;
int soundValue = 0;
int airValue = 0;

int attentionScore = 100;

unsigned long previousMillis = 0;
const long interval = 5000; // 5 sec logging

// -------------------- SETUP --------------------
void setup() {
  Serial.begin(9600);

  dht.begin();
  lcd.init();
  lcd.backlight();

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  lcd.setCursor(0, 0);
  lcd.print("Smart Classroom");
  lcd.setCursor(0, 1);
  lcd.print("System Start");
  delay(2000);
  lcd.clear();
}

// -------------------- LOOP --------------------
void loop() {

  // -------- READ SENSORS --------
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  lightValue = analogRead(LDR_PIN);
  soundValue = analogRead(SOUND_PIN);
  airValue = analogRead(MQ135_PIN);

  // -------- CALCULATE ATTENTION SCORE --------
  attentionScore = 100;

  // CO2 / Air Quality
  if (airValue > 400) {
    attentionScore -= 30;
  }

  // Noise
  if (soundValue > 500) {
    attentionScore -= 25;
  }

  // Light
  if (lightValue < 300) {
    attentionScore -= 20;
  }

  // Temperature comfort
  if (temperature > 30 || temperature < 20) {
    attentionScore -= 10;
  } else {
    attentionScore += 5;
  }

  // Clamp score
  if (attentionScore > 100) attentionScore = 100;
  if (attentionScore < 0) attentionScore = 0;

  // -------- SMART RECOMMENDATION ENGINE --------
  String suggestion = "All Good";

  if (airValue > 400) {
    suggestion = "Open Windows";
  } 
  else if (soundValue > 500) {
    suggestion = "Reduce Noise";
  } 
  else if (lightValue < 300) {
    suggestion = "Turn On Lights";
  }

  // -------- AUTO CONTROL (RELAY) --------
  if (airValue > 400 || lightValue < 300) {
    digitalWrite(RELAY_PIN, HIGH);  // Turn ON
  } else {
    digitalWrite(RELAY_PIN, LOW);   // Turn OFF
  }

  // -------- LCD DISPLAY --------
  lcd.setCursor(0, 0);
  lcd.print("Score:");
  lcd.print(attentionScore);
  lcd.print("   ");

  lcd.setCursor(0, 1);
  lcd.print(suggestion);
  lcd.print("   ");

  // -------- SERIAL ANALYTICS --------
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    Serial.println("------ Classroom Data ------");
    Serial.print("Temp: "); Serial.print(temperature); Serial.println(" C");
    Serial.print("Humidity: "); Serial.print(humidity); Serial.println(" %");
    Serial.print("Light: "); Serial.println(lightValue);
    Serial.print("Noise: "); Serial.println(soundValue);
    Serial.print("Air Quality: "); Serial.println(airValue);
    Serial.print("Attention Score: "); Serial.println(attentionScore);
    Serial.print("Suggestion: "); Serial.println(suggestion);
    Serial.println("-----------------------------");
  }

  delay(1000);
}
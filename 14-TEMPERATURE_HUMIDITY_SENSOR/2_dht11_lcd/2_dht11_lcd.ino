// Program to control the temperature and humitdity sensor
// Ciruit Diagram: Placed in same folder

#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Analog pin 4 - SDA
// Analog pin 5 - SCL
// 5V - Vcc
// GND - GND
// set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// configuration for temperature and humidity sensor
#define SET_TIME 500
#define DHT_TYPE DHT11
#define DHT_PIN 2
DHT dht(DHT_PIN, DHT_TYPE);
float humidity;
float temperature_c;

void setup() {
  // initialize the sensor
  dht.begin();

  // initialize the LCD
  lcd.begin();

  // turn on the blacklight
  lcd.backlight();
  delay(SET_TIME);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Humid. = 00.00 %");
  lcd.setCursor(0, 1);
  lcd.print("Temp.  = 00.00");
  lcd.print((char)223);  // for degree symbol
  lcd.print("C");
}

void loop() {
  // read the values
  humidity = dht.readHumidity();
  temperature_c = dht.readTemperature();

  lcd.setCursor(9, 0);
  lcd.print(humidity);
  lcd.setCursor(9, 1);
  lcd.print(temperature_c);
  delay(1000);
}

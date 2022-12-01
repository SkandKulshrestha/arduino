// Program to control the temperature and humitdity sensor
// Ciruit Diagram: Placed in same folder

#include "DHT.h"

// configuration for temperature and humidity sensor
#define SET_TIME 500
#define DHT_TYPE DHT11
#define DHT_PIN 2
DHT dht(DHT_PIN, DHT_TYPE);
float humidity;
float temperature_c;
float temperature_f;

void setup() {
  // setup serial communication
  Serial.begin(115200);

  // setup dht module
  dht.begin();
  delay(SET_TIME);
}

void loop() {
  // read the values
  humidity = dht.readHumidity();
  temperature_c = dht.readTemperature();
  temperature_f = dht.readTemperature(true);

  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.print(", Temperature = ");
  Serial.print(temperature_c);
  Serial.print("ºC = ");
  Serial.print(temperature_f);
  Serial.println("ºF");
  delay(1000);
}

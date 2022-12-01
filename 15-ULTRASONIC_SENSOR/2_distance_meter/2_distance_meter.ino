// Program to control the ultrasonic sensor
// Ciruit Diagram: Placed in same folder

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Analog pin 4 - SDA
// Analog pin 5 - SCL
// 5V - Vcc
// GND - GND
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define SET_TIME 500

// speed of sound in m/s
#define SPEED_OF_SOUND 343

// multiplier to convert meter to inch
#define METER_TO_INCH 39.3701

// configuration for ultrasonic sensor
#define TRIG_PIN 2
#define ECHO_PIN 3
float distance;
#define DELAY_TIME 500

float measure_distance(int echo_pin)
{
  int ping_travel_time;

  // get the value from echo pin
  ping_travel_time = pulseIn(echo_pin, HIGH);

  // calculate distance
  return (SPEED_OF_SOUND * (float)ping_travel_time) / 1000000.0;
}

void setup() {
  // setup serial communication
  Serial.begin(115200);

  // setup pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Initialize the LCD
  lcd.begin();

  // turn on the blacklight
  lcd.backlight();
  delay(SET_TIME);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance = ");
}

void loop() {
  // set trig pin to LOW - HIGH - LOW
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure distance
  distance = measure_distance(ECHO_PIN);

  // display on lcd
  lcd.setCursor(11, 0);
  lcd.print(distance);
  lcd.print("m");
  delay(DELAY_TIME);
}

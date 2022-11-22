// Program to control led by potentiometer
// LED: direction matters. long leg (anode) goes to positive.
// Ciruit Diagram: placed in same folder.

// analog pin for measuring value
#define VOLTAGE A3

// analog pin for led
#define LED_PIN 9

int calculate_voltage(void)
{
  // input analog pin values from 0 to 1023
  // output analog pin values from 0 to 255
  int voltage = (255.0 * analogRead(VOLTAGE)) / 1023.0;
  return voltage;
}

void setup() {
  // set VOLTAGE pin as input and LED pin as output
  pinMode(VOLTAGE, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // calculate and print voltage
  analogWrite(LED_PIN, calculate_voltage());

  delay(1000);
}

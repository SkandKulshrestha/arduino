// Program to control the brightness of led using analog pin / pulse width modulation(PWM)
// Ciruit Diagram: placed in same folder.

// led connection
#define LED 9

// high, mid and low possible values
// One can control the brightness by setting the value on analog pin from 0 (low) to 255 (high)
#define HIGH_VOLTAGE 255
#define MID_VOLTAGE 127
#define LOW_VOLTAGE 0

void setup() {
  // set LED PIN as output
  pinMode(LED, OUTPUT);
}

void loop() {
  // turn on the led with brightness level max
  analogWrite(LED, HIGH_VOLTAGE);
  delay(1000);

  // turn on the led with brightness level mid
  analogWrite(LED, MID_VOLTAGE);
  delay(1000);

  // turn off the led
  analogWrite(LED, LOW_VOLTAGE);
  delay(1000);

  // turn on the led with brightness level mid
  analogWrite(LED, MID_VOLTAGE);
  delay(1000);
}

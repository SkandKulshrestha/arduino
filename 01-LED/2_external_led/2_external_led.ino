// Program to control the LED externally connected to PIN 12
// LED: direction matters. long leg (anode) goes to positive.
// Ciruit Diagram: placed in same folder.

// defines the configuration for led
#define LED 12

void setup() {
  // set LED PIN to act as output
  pinMode(LED, OUTPUT);
}

void loop() {
  // turn on the led
  digitalWrite(LED, HIGH);
  delay(1000); // delay of 1000ms = 1s

  // turn off the led
  digitalWrite(LED, LOW);
  delay(1000);
}

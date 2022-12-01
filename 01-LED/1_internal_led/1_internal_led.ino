// Program to control the LED internally connected to LED_BUILTIN(connected to PIN 13)
// Circuit Diagram: No external circuit

void setup() {
  // set the builtin led as output
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // turn on the led
  digitalWrite(LED_BUILTIN, HIGH);
  // delay of 1000ms = 1s
  delay(1000);

  // turn off the led
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

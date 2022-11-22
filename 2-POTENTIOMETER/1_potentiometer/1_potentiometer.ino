// Program to calculate the voltage value controlled by potentiometer using analog pin
// Ciruit Diagram: placed in same folder.

// analog pin for measuring value
#define VOLTAGE A3

void calculate_voltage(void)
{
  // input analog pin values from 0 to 1023
  float voltage = (5.0 / 1023.0) * analogRead(VOLTAGE);
  Serial.println(voltage);
}

void setup() {
  // set VOLTAGE pin as input
  pinMode(VOLTAGE, INPUT);

  // set Serial port
  Serial.begin(115200);
}

void loop() {
  // calculate and print voltage
  calculate_voltage();

  delay(1000);
}

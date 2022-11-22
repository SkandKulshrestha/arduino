// Program to control and display the voltage
// Ciruit Diagram: placed in same folder.

// led connection
#define LED 9
#define DELAY_TIME_WRITE 1000
#define DELAY_TIME_READ 1000

// high, mid and low possible values
#define HIGH_VOLTAGE 255
#define MID_VOLTAGE 127
#define LOW_VOLTAGE 0

// analog pin for measuring voltage
#define VOLTAGE A1

void calculate_voltage(int read_pin)
{
  // read the value on analog pin
  int read_value = analogRead(read_pin);

  float voltage = (5.0 / 1023.0) * read_value;
  Serial.print(" read = ");
  Serial.print(read_value);
  Serial.print(", voltage = ");
  Serial.println(voltage);
}

void setup() {
  // set LED pin as output
  pinMode(LED, OUTPUT);

  // set VOLTAGE pin as input
  pinMode(VOLTAGE, INPUT);

  // start Serial port
  Serial.begin(9600);
}

void loop() {
  // turn on led with high level
  analogWrite(LED, HIGH_VOLTAGE);
  delay(DELAY_TIME_WRITE);

  Serial.print('H');

  // calculate and print the voltage
  calculate_voltage(VOLTAGE);
  delay(DELAY_TIME_READ);

  // perform same steps with led on with mid level
  analogWrite(LED, MID_VOLTAGE);
  delay(DELAY_TIME_WRITE);
  Serial.print('M');
  calculate_voltage(VOLTAGE);
  delay(DELAY_TIME_READ);

  // perform same steps with led off
  analogWrite(LED, LOW_VOLTAGE);
  delay(DELAY_TIME_WRITE);
  Serial.print('L');
  calculate_voltage(VOLTAGE);
  delay(DELAY_TIME_READ);

  // perform same steps again with led on with mid level
  analogWrite(LED, MID_VOLTAGE);
  delay(DELAY_TIME_WRITE);
  Serial.print('M');
  calculate_voltage(VOLTAGE);
  delay(DELAY_TIME_READ);
}

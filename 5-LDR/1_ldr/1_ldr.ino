// Program to control photoresistor
// Ciruit Diagram: Placed in same folder

// configuration pin for photoresistor
#define PHOTORESISTOR A0
int value;

void setup() {
  // put your setup code here, to run once:
  pinMode(PHOTORESISTOR, INPUT);

  // setup Serial port
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the voltage value
  value = analogRead(PHOTORESISTOR);
  Serial.println(value);
  delay(100);
}

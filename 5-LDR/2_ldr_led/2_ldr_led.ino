// Program to control rgb led with photoresistor
// Ciruit Diagram: Placed in same folder

// configuration pin for red, green
#define LED_RED 11
#define LED_GREEN 10

// configuration pin for photoresistor
#define PHOTORESISTOR A0
#define THRESHOLD 1000
int value;

void setup() {
  // put your setup code here, to run once:
  // set input and output
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(PHOTORESISTOR, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the voltage value
  value = analogRead(PHOTORESISTOR);

  if (value > THRESHOLD)
  {
    // glow red when high value detected
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, LOW);
  }
  else
  {
    // glow green when low value detected
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, HIGH);
  }
  delay(100);
}

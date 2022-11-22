// Program to control Pushbutton using pull down resistor
// Ciruit Diagram: Placed in same folder

// configuration pin for button
#define PUSH_BUTTON 2
int value;

#define DELAY_TIME 200

void setup() {
  // put your setup code here, to run once:
  pinMode(PUSH_BUTTON, INPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = digitalRead(PUSH_BUTTON);

  // button up: value will be LOW
  // button down: value will be HIGH
  Serial.println(value);

  delay(DELAY_TIME);
}

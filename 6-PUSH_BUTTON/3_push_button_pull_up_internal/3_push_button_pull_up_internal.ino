// Program to control Pushbutton using pull up resistor internal
// It is a quick trick. Ideally, must go with resitor.
// Ciruit Diagram: Placed in same folder

// configuration pin for button
#define PUSH_BUTTON 2
int value;

#define DELAY_TIME 200

void setup() {
  // put your setup code here, to run once:
  pinMode(PUSH_BUTTON, INPUT_PULLUP);

  // Prior to Arduino 1.0.1
  // pinMode(PUSH_BUTTON, INPUT);           // set pin to input
  // digitalWrite(PUSH_BUTTON, HIGH);       // turn on pullup resistors

  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = digitalRead(PUSH_BUTTON);

  // button up: value will be HIGH
  // button down: value will be LOW
  Serial.println(value);

  delay(DELAY_TIME);
}

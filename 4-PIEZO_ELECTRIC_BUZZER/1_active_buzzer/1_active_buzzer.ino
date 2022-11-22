// Program to control active buzzer
// Ciruit Diagram: Placed in same folder

// configuration pin for buzzer
#define BUZZER 8
#define BUZZER_ON_TIME 1000
#define BUZZER_OFF_TIME 1000

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // turn on the buzzer
  digitalWrite(BUZZER, HIGH);
  delay(BUZZER_ON_TIME);

  // turn off the buzzer
  digitalWrite(BUZZER, LOW);
  delay(BUZZER_OFF_TIME);
}

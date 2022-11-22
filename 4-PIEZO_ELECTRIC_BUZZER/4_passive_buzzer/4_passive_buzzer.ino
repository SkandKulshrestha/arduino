// Program to control passive buzzer
// Ciruit Diagram: Placed in same folder

// configuration pin for buzzer
#define BUZZER 8

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER, OUTPUT);
  tone(BUZZER, 1000, 2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(BUZZER, 440); // A4
  delay(1000);

  tone(BUZZER, 494); // B4
  delay(1000);

  tone(BUZZER, 523); // C4
  delay(1000);

  tone(BUZZER, 587); // D4
  delay(1000);

  tone(BUZZER, 659); // E4
  delay(1000);

  tone(BUZZER, 698); // F4
  delay(1000);

  tone(BUZZER, 784); // G4
  delay(1000);

  noTone(BUZZER);
  delay(1000);
}

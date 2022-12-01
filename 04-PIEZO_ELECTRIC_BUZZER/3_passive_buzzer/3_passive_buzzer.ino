// Program to control passive buzzer
// Ciruit Diagram: Placed in same folder

// configuration pin for buzzer
#define BUZZER 9

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // do this 255 times
  for(int voltage = 0; voltage < 255; voltage++) {
    // raise the voltage sent out of the pin by 1
    analogWrite(BUZZER, voltage);
    delay(10);
  }

  for(int voltage = 255; voltage > 0; voltage--) {
    // lower the voltage sent out of the pin by 1
    analogWrite(BUZZER, voltage);
    delay(10);
  }
}

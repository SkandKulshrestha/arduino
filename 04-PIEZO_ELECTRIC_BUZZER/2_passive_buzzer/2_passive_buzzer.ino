// Program to control passive buzzer using potentiometer
// Ciruit Diagram: Placed in same folder

// configuration pin for buzzer
#define BUZZER 8
int time_buzz;

// analog pin for measuring value
#define POTENTIOMETER A3
int value;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER, OUTPUT);
  pinMode(POTENTIOMETER, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(POTENTIOMETER);

  // at value 0, time_buzz be 60
  // at value 1023, time_buzz be 10,000
  // => slope = (10000 - 60) / (1023 - 0) = 9940 / 1023
  time_buzz = (9940.0 / 1023.0) * value + 60;

  // set buzzer high and low for calculated time period
  digitalWrite(BUZZER, HIGH);
  delayMicroseconds(time_buzz);
  digitalWrite(BUZZER, LOW);
  delayMicroseconds(time_buzz);
}

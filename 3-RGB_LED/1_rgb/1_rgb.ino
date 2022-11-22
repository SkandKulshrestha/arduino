// Program to control the RGB LED
// Ciruit Diagram: placed in same folder.

// configuration pin for Red, Green, and Blue
#define RED 11
#define GREEN 6
#define BLUE 5

void setup() {
  // set RED, GREEN, BLUE pins as output
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  // turn on the red
  analogWrite(BLUE, 0);
  analogWrite(RED, 255);
  delay(500);

  // turn on the green
  analogWrite(RED, 0);
  analogWrite(GREEN, 255);
  delay(500);

  // turn on the blue
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 255);
  delay(500);
}

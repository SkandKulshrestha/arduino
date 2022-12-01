// Program to control the joystick
// Ciruit Diagram: Unable to draw
// Connect GND to GND, +5V to 5V, VRx to A0, VRy to A1, SW to 2

// configuration for joystick
// x position, y position, and switch
#define JOYSTICK_X A0
#define JOYSTICK_Y A1
#define JOYSTICK_S 2

int value_x;
int value_y;
int value_s;

void setup() {
  // put your setup code here, to run once:
  pinMode(JOYSTICK_X, INPUT);
  pinMode(JOYSTICK_Y, INPUT);
  pinMode(JOYSTICK_S, INPUT);
  digitalWrite(JOYSTICK_S, HIGH);

  // setup serial communication
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  value_x = analogRead(JOYSTICK_X);
  value_y = analogRead(JOYSTICK_Y);
  value_s = digitalRead(JOYSTICK_S);
  delay(500);

  Serial.print("X = ");
  Serial.print(value_x);
  Serial.print(", Y = ");
  Serial.print(value_y);
  Serial.print(", Switch State = ");
  Serial.println(value_s);
}

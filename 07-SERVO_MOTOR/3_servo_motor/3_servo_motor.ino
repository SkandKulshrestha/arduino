// Program to control the servo motor
// For Servo motor SG90, PWM = Orange, Vcc = Red, Ground = Brown
// Ciruit Diagram: Placed in same folder

#include <Servo.h>

// configuration for servo motor
#define SERVO_PIN 11
int servo_position = 0;
Servo servo_object;

#define DELAY_TIME 1000

void setup() {
  Serial.begin(115200);

  // attach pin to servo object
  servo_object.attach(SERVO_PIN);
  servo_object.write(servo_position);
}

void loop() {
  // set servo position
  Serial.println("What angle for the servo?");
  while (Serial.available() == 0) ;
  servo_position = Serial.parseInt();

  Serial.print("You have entered ");
  Serial.println(servo_position);

  servo_object.write(servo_position);
  delay(DELAY_TIME);
}

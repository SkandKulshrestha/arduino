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
  // attach pin to servo object
  servo_object.attach(SERVO_PIN);
}

void loop() {
  // set servo position
  servo_position = 0;
  servo_object.write(servo_position);
  delay(DELAY_TIME);

  servo_position = 90;
  servo_object.write(servo_position);
  delay(DELAY_TIME);

  servo_position = 180;
  servo_object.write(servo_position);
  delay(DELAY_TIME);
}

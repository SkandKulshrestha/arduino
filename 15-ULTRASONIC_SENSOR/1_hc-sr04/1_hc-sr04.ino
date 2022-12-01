// Program to control the ultrasonic sensor
// Ciruit Diagram: Placed in same folder

// configuration for ultrasonic sensor
#define TRIG_PIN 2
#define ECHO_PIN 3
int ping_travel_time;

void setup() {
  // setup serial communication
  Serial.begin(115200);

  // setup pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // set trig pin to LOW - HIGH - LOW
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // get the value from echo pin
  ping_travel_time = pulseIn(ECHO_PIN, HIGH);
  Serial.println(ping_travel_time);
  delay(25);
}

// Program to control Pushbutton as Toggle Switch
// Ciruit Diagram: Placed in same folder

int state = 0;

// configuration pin for button
#define PUSH_BUTTON 2
int value_button_old = 1;
int value_button_new;

#define DELAY_TIME 100

void setup() {
  // put your setup code here, to run once:
  pinMode(PUSH_BUTTON, INPUT);

  Serial.begin(115200);
  Serial.print("State is ");
  Serial.println(state);
}

void loop() {
  // put your main code here, to run repeatedly:
  value_button_new = digitalRead(PUSH_BUTTON);

  // check for state change
  if (value_button_new == 1 && value_button_old == 0)
  {
    // revert the state
    state ^= 1;
    Serial.print("State is ");
    Serial.println(state);
  }

  // store current value
  value_button_old = value_button_new;

  delay(DELAY_TIME);
}

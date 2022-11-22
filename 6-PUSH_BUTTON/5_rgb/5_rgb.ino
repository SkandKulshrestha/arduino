// Program to control the RGB LED with Pushbutton as Toggle Switch
// Ciruit Diagram: Placed in same folder

// configuration pin for RGB led
#define LED_RED 11
#define LED_GREEN 10
#define LED_BLUE 9
int functionality = 6;
int state_led = 0;

// configuration pin for button
#define PUSH_BUTTON 2
int value_button_old = 1;
int value_button_new;

// no led on
void function0(int delay_time)
{
  analogWrite(LED_BLUE, 0);
  analogWrite(LED_GREEN, 0);
  analogWrite(LED_RED, 0);
  delay(delay_time);
}

// red led blinking
void function1(int delay_time)
{
  analogWrite(LED_BLUE, 0);
  analogWrite(LED_GREEN, 0);
  analogWrite(LED_RED, 0);
  delay(delay_time);
  analogWrite(LED_RED, 255);
  delay(delay_time);
}

// green led blinking
void function2(int delay_time)
{
  analogWrite(LED_BLUE, 0);
  analogWrite(LED_RED, 0);
  analogWrite(LED_GREEN, 0);
  delay(delay_time);
  analogWrite(LED_GREEN, 255);
  delay(delay_time);
}

// blue led blinking
void function3(int delay_time)
{
  analogWrite(LED_RED, 0);
  analogWrite(LED_GREEN, 0);
  analogWrite(LED_BLUE, 0);
  delay(delay_time);
  analogWrite(LED_BLUE, 255);
  delay(delay_time);
}

// red, green, blue pattern
void function4(int delay_time)
{
  // turn on the red
  analogWrite(LED_GREEN, 0);
  analogWrite(LED_BLUE, 0);
  analogWrite(LED_RED, 255);
  delay(delay_time);

  // turn on the green
  analogWrite(LED_RED, 0);
  analogWrite(LED_GREEN, 255);
  delay(delay_time);

  // turn on the blue
  analogWrite(LED_GREEN, 0);
  analogWrite(LED_BLUE, 255);
  delay(delay_time);
}

void function5(void)
{
  ;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(PUSH_BUTTON, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value_button_new = digitalRead(PUSH_BUTTON);

  // update the state if switch is toggled
  if (value_button_new == 1 && value_button_old == 0)
  {
    state_led = (state_led + 1) % functionality;
  }
  value_button_old = value_button_new;

  switch(state_led)
  {
    case 0: function0(100); break;
    case 1: function1(100); break;
    case 2: function2(100); break;
    case 3: function3(100); break;
    case 4: function4(100); break;
    case 5: function4(1000); break;
    default: function0(100); break;
  }
}

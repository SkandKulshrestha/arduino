// Program to control lcd using i2c module

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Analog pin 4 - SDA
// Analog pin 5 - SCL
// 5V - Vcc
// GND - GND

uint8_t battery0[8]  = {0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f};
uint8_t battery1[8]  = {0x0e, 0x1b, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f};
uint8_t battery2[8]  = {0x0e, 0x1b, 0x11, 0x11, 0x11, 0x11, 0x1f, 0x1f};
uint8_t battery3[8]  = {0x0e, 0x1b, 0x11, 0x11, 0x11, 0x1f, 0x1f, 0x1f};
uint8_t battery4[8]  = {0x0e, 0x1b, 0x11, 0x11, 0x1f, 0x1f, 0x1f, 0x1f};
uint8_t battery5[8]  = {0x0e, 0x1b, 0x11, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f};
uint8_t battery6[8]  = {0x0e, 0x1b, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f};
uint8_t battery7[8]  = {0x0e, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f};

// set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

uint8_t counter;

void setup()
{
  // initialize the LCD
  lcd.begin();

  // turn on the blacklight
  lcd.backlight();

  // create the symbol
  lcd.createChar(0, battery0);
  lcd.createChar(1, battery1);
  lcd.createChar(2, battery2);
  lcd.createChar(3, battery3);
  lcd.createChar(4, battery4);
  lcd.createChar(5, battery5);
  lcd.createChar(6, battery6);
  lcd.createChar(7, battery7);
  lcd.home();

  display_battery_symbols();
  delay(5000);

  lcd.clear();
  lcd.print("Battery");
  counter = 0;
}

// display battery symbols
void display_battery_symbols(void) {
  lcd.clear();
  lcd.print("Battery");
  lcd.setCursor(0, 1);

  for (int j = 0; j < 8; j++) {
    lcd.write(j);
  }
}

void loop()
{
  if (counter)
  {
    lcd.setCursor(15, 0);
    lcd.write(counter);
    delay(500);
  }

  counter = (counter + 1) % 8;
}

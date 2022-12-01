// Program to control lcd using i2c module

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Analog pin 4 - SDA
// Analog pin 5 - SCL
// 5V - Vcc
// GND - GND

// 8 symbols can be changed
uint8_t symbol0[8]  = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01};
uint8_t symbol1[8]  = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x01};
uint8_t symbol2[8]  = {0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x01};
uint8_t symbol3[8]  = {0x00, 0x00, 0x00, 0x00, 0x07, 0x03, 0x03, 0x01};
uint8_t symbol4[8]  = {0x00, 0x00, 0x00, 0x07, 0x07, 0x03, 0x03, 0x01};
uint8_t symbol5[8]  = {0x00, 0x00, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x01};
uint8_t symbol6[8]  = {0x00, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x01};
uint8_t symbol7[8]  = {0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x01};

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
  lcd.createChar(0, symbol0);
  lcd.createChar(1, symbol1);
  lcd.createChar(2, symbol2);
  lcd.createChar(3, symbol3);
  lcd.createChar(4, symbol4);
  lcd.createChar(5, symbol5);
  lcd.createChar(6, symbol6);
  lcd.createChar(7, symbol7);
  lcd.home();

  display_cell_symbols();
  delay(5000);

  lcd.clear();
  lcd.print("Cell Signal");
  counter = 0;
}

// display cell symbols
void display_cell_symbols(void) {
  lcd.clear();
  lcd.print("Cell Signal");
  lcd.setCursor(0, 1);

  for (int j = 0; j < 8; j++) {
    lcd.write(j);
  }
}

void loop()
{
  lcd.setCursor(15, 0);
  lcd.write(counter);
  delay(500);
  counter = (counter + 1) % 8;
}

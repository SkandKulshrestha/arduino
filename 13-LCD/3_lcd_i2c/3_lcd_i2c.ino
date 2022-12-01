// Program to control lcd using i2c module

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Analog pin 4 - SDA
// Analog pin 5 - SCL
// 5V - Vcc
// GND - GND

// set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  // initialize the LCD
  lcd.begin();

  // turn on the blacklight
  lcd.backlight();
}

void loop()
{
  // clear the screen
  lcd.clear();
  lcd.print("Hello, World!");
  delay(5000);

  lcd.clear();
  lcd.print("My name is Skand");

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  String str = "I am ...";
  for (int i = 0; i < str.length(); i++)
  {
    lcd.print(str.charAt(i));
    delay(500);
  }
  delay(5000);

  lcd.clear();
  lcd.print("How are you?");
  delay(5000);
}

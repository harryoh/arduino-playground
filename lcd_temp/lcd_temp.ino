#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int tempPin = 0;
int lightPin = 1;

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  int tempReading = analogRead(tempPin);
  float tempVolts = tempReading / 1024.0 * 5000;
  float tempC = tempVolts / 10;
  float tempF = tempC * 9.0 / 5.0 + 32.0;
  lcd.setCursor(0, 0);
  lcd.print("Temp ");
  lcd.setCursor(5, 0);
  lcd.print(tempC);
  lcd.setCursor(10cd, 0);
  lcd.print("C");
  
  int lightValue = analogRead(lightPin);
  lcd.setCursor(0, 1);
  lcd.print("Light ");
  lcd.setCursor(6, 1);
  lcd.print(lightValue);
  delay(500);
}

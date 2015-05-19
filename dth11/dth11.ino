#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT11.h>

int pin = 2;
DHT11 dht11(pin); 
LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
   Serial.begin(9600);
   lcd.init();
   lcd.backlight();
}
 
void loop()
{
  int err;
  float temp, humi;
  if((err=dht11.read(humi, temp))==0)
  {
    Serial.print("temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    Serial.println();
    
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.setCursor(6, 0);
    lcd.print(temp);
    
    lcd.setCursor(0, 1);
    lcd.print("Humi: ");
    lcd.setCursor(6, 1);
    lcd.print(humi);
  }
  else
  {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();    
  }
  delay(DHT11_RETRY_DELAY); //delay for reread
}



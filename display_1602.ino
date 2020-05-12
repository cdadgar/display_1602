#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define SDA 0
#define SCL 2

// set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27,16,2);

/*
 * the 1602 needs to b fitted with a I2C backpack module
 * so that we only need 2 data lines to connect the display to the microcontroller
 * 
 * the 1602 normaly runs off of 5V.  some have been modified to use 3.3V
 * (since the esp8266 only used 3.3V)
 * if VCC is 5V, SDA and SCL can still be 3.3V levels
 * to do the conversion, add C1 and C2 and U3, and move J1 to J3
 */

/*
 * on a wemos d1 r1:
 * defaults without setting wire sda, scl
 * D1 (5) - SCL
 * D2 (4) - SDA
 * setting SDA=0 and SCL=2
 * D4 (1) - SCL
 * D3 (0) - SDA 
 */
void setup()
{
  Serial.begin(115200);
  Serial.print(F("\n\n"));
  Serial.println(F("esp8266 1602 test"));
  Serial.println(F("compiled:"));
  Serial.print( __DATE__);
  Serial.print(F(","));
  Serial.println( __TIME__);

  Wire.begin(SDA,SCL);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello, world!");
  lcd.setCursor(0,1);
  lcd.print("A line of text");
}


void loop()
{
}

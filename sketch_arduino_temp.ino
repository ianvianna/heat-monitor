#include <LiquidCrystal_I2C.h>

#define tempSensor A0
float temp = 0.0, lastTemp = 0.0;
LiquidCrystal_I2C lcd(0x27,16,2);
byte grays [] = { B01110, B01010, B01110, B00000, B00000, B00000, B00000, B00000 };
void setup() {

  lcd.init();
  lcd.createChar(0, grays);
  lcd.backlight();
  Serial.begin(115200);
}

void loop() {
  lcd.home();
  temp = (analogRead(tempSensor)*(5.0/1023))/0.01;
  if(temp != lastTemp) {
    lcd.clear();
    lastTemp = temp;
    lcd.print("Temp.: ");
    lcd.print(temp);
    lcd.write(0);
    lcd.print("C");
    Serial.println(temp);
  }
  delay(1500);
}

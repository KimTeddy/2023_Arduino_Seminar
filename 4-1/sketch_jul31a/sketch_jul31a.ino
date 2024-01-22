#include <Wire.h>  //LCD
#include <LiquidCrystal_I2C.h> //LCD
LiquidCrystal_I2C lcd(0x27,16,2);

byte customChar1[] = {
  B01110,
  B01010,
  B01110,
  B00000,
  B11111,
  B00100,
  B00100,
  B00000
};
byte customChar2[] = {
  B01110,
  B00010,
  B01110,
  B01000,
  B01110,
  B00000,
  B00000,
  B00000
};
byte customChar3[] = {
  B10000,
  B11111,
  B00100,
  B11111,
  B00000,
  B11111,
  B01010,
  B11111
};
byte customChar4[] = {
  B00010,
  B00001,
  B01001,
  B10101,
  B10101,
  B01001,
  B00001,
  B00001
};
void setup() {
  
  lcd.init(); //LCD시작
  lcd.backlight();
  lcd.createChar(0, customChar1);
  lcd.createChar(1, customChar2);
  lcd.createChar(2, customChar3);
  lcd.createChar(3, customChar4);
}

void loop() { 
  int sensor = analogRead(A0);

  int water = map(sensor, 300, 560, 0, 100);
  if(water<0) water = 0;
  if(water>100) water = 100;

  lcd.home();
  lcd.write(0);//무
  lcd.write(2);//높
  lcd.write(3);//이
  lcd.setCursor(0,1);
  lcd.write(1);//ㄹ
  
  lcd.setCursor(3,0);
  lcd.print(":");
  lcd.print(water);
  lcd.print(" ");
}
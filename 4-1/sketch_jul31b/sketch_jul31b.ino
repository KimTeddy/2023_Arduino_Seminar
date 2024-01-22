#include <SoftwareSerial.h>
#include <Wire.h>  //LCD
#include <LiquidCrystal_I2C.h> //LCD

LiquidCrystal_I2C lcd(0x27,16,2);
SoftwareSerial bluetooth(8, 9);  

int x=0, y=0;

void setup()
{
  Serial.begin(9600);
  bluetooth.begin(9600);
  lcd.init(); //LCD시작
  lcd.backlight();
}

void loop()
{
  if (bluetooth.available())
  {
    byte data = bluetooth.read();
    Serial.write(data);
    switch(data){
      case 'a': x--; 
      if(x<0) x=0;
      break;

      case 'd': x++; 
      if(x>15) x=15;
      break;

      case 'w': y--;
      if(y<0) y=0;
      break;

      case 's': y++; 
      if(y>1) y=1;
      break;
  }
  lcd.clear();
  lcd.setCursor(x,y);
  lcd.print("O");
  }



  if (Serial.available())
  {
    bluetooth.write(Serial.read());
  }
}
#include <SPI.h>
#include <MFRC522.h>

//RFID관련
#define SS_PIN 10
#define RST_PIN 9


//윤석
#include <LiquidCrystal.h>
LiquidCrystal lcd(14, 15, 16, 17, 18, 19);
//진수
//#include <Wire.h>  //LCD
//#include <LiquidCrystal_I2C.h> //LCD
//LiquidCrystal_I2C lcd(0x27,16,2);



MFRC522 rfid(SS_PIN, RST_PIN);

byte mycard[][4] = {
  {212,109,162,42}, //1번
  {77,148,160,61}  //2번
};

String text[] = {
  "Card #1",
  "Card #2"
};

void setup() { 
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

	// 16개의 셀과 2줄을 사용하도록 설정합니다.
	lcd.begin(16,2);
	// LCD를 초기화 합니다.
	lcd.clear();

  //lcd.init(); //LCD시작
  //lcd.backlight(); //LCD백라이트 켜기


  //첫번째줄 데이터 제목
  lcd.setCursor(0,0); //LCD 1번째 줄에
  lcd.print("RFID + LCD"); //제목을 출력
  lcd.setCursor(0,1); //LCD 2번째 줄에
  lcd.print("Card please~"); //이걸 출력
}
 
void loop() {
  if ( ! rfid.PICC_IsNewCardPresent())    return;
  if ( ! rfid.PICC_ReadCardSerial())    return;

  for (byte i = 0; i < 4; i++) {
    Serial.print(rfid.uid.uidByte[i]);
    Serial.print(",");
  }
  Serial.println();

  for(int i = 0;i<2;i++){
    bool is_match = true;
    for(int j = 0;j<4;j++){
      if(mycard[i][j] != rfid.uid.uidByte[j]){
        is_match = false;
        break;
      }
    }

    if(is_match){
      String line = text[i];
      while(line.length()<16) line+= " ";
      lcd.setCursor(0,1); //LCD 2번째 줄에
      lcd.print(line); //이걸 출력
    }
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
byte data[]={
0x81^0xFF,  //0b01111110
0xF2^0xFF,
0x49^0xFF,
0x60^0xFF,
0x33^0xFF,
0x24^0xFF,
0x05^0xFF,
0xF0^0xFF,
0x01^0xFF,
0x20^0xFF
};
/*byte data[]={
0B10000001,  
0B11110010,
0B01001001,
0B01100000,
0B00110011,
0B00100100,
0B00000101,
0B11110000,
0B00000001,
0B00100000
};*/
int latchPin = 11; //ST_CP Pin
int clockPin = 12; //SH_CP Pin
int dataPin = 9; //DS Pin

void setup(){
pinMode(latchPin, OUTPUT);
pinMode(clockPin, OUTPUT);
pinMode(dataPin, OUTPUT);
}
void loop(){
 for(int i=0;i<10;i++){
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, data[i]);
    digitalWrite(latchPin, HIGH);       
    delay(1000);
  }  
}
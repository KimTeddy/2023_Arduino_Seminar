#include <IRremote.h>

IRrecv irrecv(2);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results)) {
     Serial.print("results.decode_type : "); //리모콘 타입
     Serial.println(results.decode_type);
      
     Serial.print("results.bits : "); //키값길이
     Serial.println(results.bits);
      
     Serial.print("results.value : "); //키값
     Serial.println(results.value);
      
     Serial.print("results.value, HEX : "); //키값을 16진수로변환
     Serial.println(results.value, HEX);
     
    switch (results.value) {
      case 0xFF00BF00: digitalWrite(13, HIGH); break;
      case 0xFE01BF00: digitalWrite(13, LOW); break;
      case 0xFD02BF00: break;
    }

    irrecv.resume();
    delay(100);
  }
}

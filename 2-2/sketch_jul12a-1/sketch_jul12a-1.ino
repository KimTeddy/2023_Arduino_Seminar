int prev = 0, now = 0;

void setup() {
  pinMode(2, INPUT);//PIR
  pinMode(3, OUTPUT);//RELAY

}

void loop() {
  prev = now;
  now = digitalRead(2);
  if(now == HIGH && prev ==LOW) {
    digitalWrite(3, HIGH);
    delay(500);
  }
  else
    digitalWrite(3, LOW);
}

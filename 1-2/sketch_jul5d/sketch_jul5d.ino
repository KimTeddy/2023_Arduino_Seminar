void setup() {
  Serial.begin(9600);
}

void loop() {
  int x = analogRead(A0);
  int y = analogRead(A1);
  Serial.print(x);
  Serial.print("\t");
  Serial.println(y);

  tone(9, 440+map(y,0,1023,-100,100));
  delay(x/1023.0*500);
}

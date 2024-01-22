void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop() {
  int button = digitalRead(2);
  if(button == 1) digitalWrite(13, HIGH);
  else digitalWrite(13, LOW);

  segment(1);
  segment(2);
  segment(3);
}


void segment(char num){

}
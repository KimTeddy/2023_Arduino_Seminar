

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  int sound = analogRead(A0);
  Serial.println(sound);

  if(sound>600)
    digitalWrite(13,HIGH);
  else
    digitalWrite(13,LOW);
  
}

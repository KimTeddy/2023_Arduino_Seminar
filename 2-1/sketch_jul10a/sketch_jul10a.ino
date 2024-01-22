const int R=9,G=10,B=11;
const int c1=2,c2=3,c3=4,c4=5;

//R1이 A0
//C1이 2


void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);

  pinMode(c1, INPUT_PULLUP);
  pinMode(c2, INPUT_PULLUP);
  pinMode(c3, INPUT_PULLUP);
  pinMode(c4, INPUT_PULLUP);
}

void loop() {
  digitalWrite(A0,HIGH);digitalWrite(A1,LOW);digitalWrite(A2,LOW);digitalWrite(A3,LOW);
  if(digitalRead(c1)==0) analogWrite(R, 0);
  if(digitalRead(c2)==0) analogWrite(R, 60);
  if(digitalRead(c3)==0) analogWrite(R, 150);
  if(digitalRead(c4)==0) analogWrite(R, 255);
  delay(30);

  digitalWrite(A0,LOW);digitalWrite(A1,HIGH);digitalWrite(A2,LOW);digitalWrite(A3,LOW);
  //delay(30);
  if(digitalRead(c1)==0) analogWrite(G, 0);
  if(digitalRead(c2)==0) analogWrite(G, 60);
  if(digitalRead(c3)==0) analogWrite(G, 150);
  if(digitalRead(c4)==0) analogWrite(G, 255);
  delay(30);
  
  digitalWrite(A0,LOW);digitalWrite(A1,LOW);digitalWrite(A2,HIGH);digitalWrite(A3,LOW);
  //delay(30);
  if(digitalRead(c1)==0) analogWrite(B, 0);
  if(digitalRead(c2)==0) analogWrite(B, 60);
  if(digitalRead(c3)==0) analogWrite(B, 150);
  if(digitalRead(c4)==0) analogWrite(B, 255);
  delay(30);
}


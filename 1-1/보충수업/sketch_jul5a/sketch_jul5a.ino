
int a=2, b=3, 

void asdf(char);

void setup() {
}

void loop() {
  if(digitalRead(12)>0)
  {
    asdf(9);
    asdf(8);
    asdf(7);
    asdf(6);
    asdf(5);
        ...
    asdf(0);

    digitalWrite(buzzer, HIGH);delay(30);
    digitalWrite(buzzer, LOW);delay(30);
    digitalWrite(buzzer, HIGH);delay(30);
    digitalWrite(buzzer, LOW);delay(500);
  }
}

void asdf(char num){
  switch(num){
    case 0: digitalWrite(a, HIGH);digitalWrite(b, HIGH);
            digitalWrite(c, HIGH);digitalWrite(d, HIGH);
            digitalWrite(e, HIGH);digitalWrite(f, HIGH); digitalWrite(g, LOW);
    break;
    case 1: digitalWrite(a, LOW);digitalWrite(b, HIGH);
            digitalWrite(c, HIGH);digitalWrite(d, LOW);
            digitalWrite(e, LOW);digitalWrite(f, LOW); digitalWrite(g, LOW);
    break;
    case 2:
  }
}
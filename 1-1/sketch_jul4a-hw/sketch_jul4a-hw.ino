#define mic 12

const int a = 2;

int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;

void segment(char num);

void setup() {
  for(int i=2; i<=8; i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  if( digitalRead(mic) > 0 )
  {
    for(int i=9; i>=0; i--)
    {
      segment(i);
      if(i==0)break;
      delay(300);
    }
    for(int i=200; i<800;i++){
      tone(9, i); delay(5);
    }
    for(int i=800; i>=200;i--){
      tone(9, i); delay(5);
    }
    noTone(9);
    segment(-1); 
  }
}

void segment(char num){
  digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, LOW);
  digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, LOW);
  switch(num){
    case 0: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH);
            digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); 
            break;
    case 1: digitalWrite(b, HIGH); digitalWrite(c, HIGH);
            break;
    case 2: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(g, HIGH);
            digitalWrite(d, HIGH); digitalWrite(e, HIGH);
            break;
    case 3: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH);
            digitalWrite(d, HIGH); digitalWrite(g, HIGH);
            break;
    case 4: digitalWrite(b, HIGH); digitalWrite(c, HIGH);
            digitalWrite(f, HIGH); digitalWrite(g, HIGH);
            break;
    case 5: digitalWrite(a, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH);
            digitalWrite(f, HIGH); digitalWrite(g, HIGH);
            break;
    case 6: digitalWrite(a, HIGH); digitalWrite(g, HIGH); digitalWrite(c, HIGH);
            digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); 
            break;
    case 7: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH);
            digitalWrite(f, HIGH);
            break;
    case 8: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH);
            digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); 
            digitalWrite(g, HIGH); 
            break;
    case 9: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH);
            digitalWrite(d, HIGH); digitalWrite(g, HIGH); digitalWrite(f, HIGH); 
            break;
  }
}
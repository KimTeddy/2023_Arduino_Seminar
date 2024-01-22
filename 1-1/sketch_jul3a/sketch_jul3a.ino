int led[8] = {2,3,4,5,6,7,8,9};

void setup() {
  for(int i=0; i<8; i++){
    pinMode(led[i],OUTPUT);
  }
}

void loop() {
  for(int i=0; i<8; i++){
    digitalWrite(led[i],HIGH);
    if(i>0){
      digitalWrite(led[i-1],LOW);
    }
    delay(500);
  }
  for(int i=7; i>=0; i--){
    digitalWrite(led[i],HIGH);
    if(i<7){
      digitalWrite(led[i+1],LOW);
    }
    delay(500);
  }
}

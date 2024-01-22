#include <math.h>
#include <Servo.h>

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  myservo.attach(9);
}

void loop() {
  int x = analogRead(A1)-507;
  int y = analogRead(A2)-502;
  float ata = atan2(x,y) + 1.57;
  //if(a>60) digitalWrite(13, HIGH);
  //Serial.println(a);
  Serial.print(x);
  Serial.print("\t");
  Serial.print(y);
  Serial.print("\t");
  Serial.println(ata);
  //int direction = 180 - map(ata, 0, 3.14, 0, 180);
  int direction = map(ata*100, 0, 314, 180, 0);
  if(x>10||x<-10 && y>10||y<-10)
    myservo.write(direction);
}

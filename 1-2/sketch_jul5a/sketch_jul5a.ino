const int reg = A0;
const int led = 3;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  int v_reg = analogRead(reg);
  int pwm = map(v_reg, 0, 1023, 255, 0);
  analogWrite(led, pwm);
}

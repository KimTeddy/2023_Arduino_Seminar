#include <Stepper.h>

#define button 3

const int stepsPerRevolution = 2048;
const int steps_15degree = stepsPerRevolution / 4;

bool isDoorOpen = 0;

Stepper myStepper(stepsPerRevolution, 11, 9, 10, 8);
void setup() {
  pinMode(button, INPUT_PULLUP);
  // set the speed at 60 rpm:
  myStepper.setSpeed(14);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(button) == 0)
  {
    if(isDoorOpen > 0)
    {
      Serial.println("1");

      myStepper.step(steps_15degree * 3);
      isDoorOpen = 0;
    }
    else
    {
      myStepper.step(-steps_15degree * 3);
      isDoorOpen = 1;
    }
  }
}


/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 */

#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int sec1 = stepsPerRevolution/60;
// for your motor
int prev = 0, now = 0;
int prev2 = 0, now2 = 0;

bool led_state = 0;
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 11, 9, 10, 8);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(14);
  // initialize the serial port:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  now = millis();
  //now2 = millis();

  if(now - prev >= 1000){
  myStepper.step(sec1);
  prev = now;
  }

  if(now - prev2 >= 500){
    led_state = !led_state;
    digitalWrite(13, led_state);
    prev2 = now;
  }
    Serial.println(now);
}


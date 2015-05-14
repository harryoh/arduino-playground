#include <Stepper.h>

#define PIN1 8
#define PIN2 9
#define PIN3 10
#define PIN4 11
#define DELAYTIME 80

const int stepsPerRevolution = 768;
Stepper motor(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  pinMode(PIN1, OUTPUT);
  pinMode(PIN2, OUTPUT);
  pinMode(PIN3, OUTPUT);
  pinMode(PIN4, OUTPUT);
  
  while (!Serial);
  
  Serial.begin(9600);
  motor.setSpeed(200);
}

void loop() {
  if (Serial.available()) {
    int steps = Serial.parseInt();
    motor.step(steps);
  }
}


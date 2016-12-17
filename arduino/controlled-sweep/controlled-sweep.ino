/*
 * This Arduino sketch sweeps a servo at a variable, customizable speed.
 */

#include <Servo.h>

const unsigned int pinServoOutput = 9;

Servo s;

// This function bounds the given variable within the given minimum and
// maximum variables (inclusive).
void BoundMinMax(unsigned int& var,
                 const unsigned int min,
                 const unsigned int max) {
  if(var < min) {
    var = min;
  }
  else if(var > max) {
    var = max;
  }
}

// This method sweeps the arm of a Servo at a specified speed.
//
// If the servo is not already attached, the method will have no effect.
// The minimum position is 30 degrees, and the maximum position is 150 degrees.
// Any position outside of these values will be reduced to within the range.
// The speed is capped at 10 (degrees of rotation per 15 microseconds)
//
// Required libraries:
//   Servo.h
void ControlledSweep(
    Servo& s,
    const unsigned int positionCurrent,
    const unsigned int positionDesired,
    const unsigned int speed
  ) {
  const unsigned int MIN_POSITION = 30;
  const unsigned int MAX_POSITION = 150;
  const unsigned int MAX_SPEED = 10;

  unsigned int finalPositionCurrent = positionCurrent;
  unsigned int finalPositionDesired = positionDesired;
  unsigned int finalSpeed = speed;

  BoundMinMax(finalPositionCurrent, MIN_POSITION, MAX_POSITION);
  BoundMinMax(finalPositionDesired, MIN_POSITION, MAX_POSITION);
  BoundMinMax(finalSpeed, 0, MAX_SPEED);

  if(!s.attached()) {
    return;
  }
  else if(finalSpeed == 0) {
    return;
  }

  if(finalPositionCurrent < finalPositionDesired) {
    for(unsigned int p = finalPositionCurrent;
        p < finalPositionDesired;
        p += finalSpeed) {
      s.write(p);
      delay(15);
    }
  }
  else {
    for(unsigned int p = finalPositionCurrent;
        p > finalPositionDesired;
        p -= finalSpeed) {
      s.write(p);
      delay(15);
    }
  }

  return;
}

void setup() {
  s.attach(pinServoOutput);
}

void loop() {
  ControlledSweep(s, 0, 180, 2);
  ControlledSweep(s, 180, 0, 8);
}

/*
 * This Arduino sketch sets PWM analog output for a digital-only output pin
 * using the value from analog input 0.
 *
 */

const size_t pinInput = A0;
const size_t pinOutput = 12;  // Digital (analog-simulated) output pin

const float PERIOD_OF_MILLISECONDS = 8.33;  // 120Hz
const size_t ANALOG_INPUT_MAX = 1023;

void setup() {
  pinMode(pinOutput, OUTPUT);
}

void loop() {
  float percentTimeOn = (float)(analogRead(pinInput)) / ANALOG_INPUT_MAX;

  digitalWrite(pinOutput, HIGH);
  delay(percentTimeOn * PERIOD_OF_MILLISECONDS);
  digitalWrite(pinOutput, LOW);
  delay((1-percentTimeOn) * PERIOD_OF_MILLISECONDS);
}

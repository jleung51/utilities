/*
 * This Arduino sketch demonstrates different possible behaviours which
 * connected LEDs can be programmed or connected to exhibit.
 *
 */

const size_t PIN_LED_ON = 13;  // Always on
const size_t PIN_LED_VARIABLE = 12;  // Loops from low to high to low
const size_t PIN_LED_MANUAL = 11;  // Controlled through potentiometer

const float PERIOD_OF_MILLISECONDS = 8.33;  // 120Hz
const float LED_VARIABLE_STEP = 0.01;  // Increase/decrease between each loop

float percentTimeOn = 0.0;
boolean increasing = true;

void setup() {
  pinMode(PIN_LED_ON, OUTPUT);
  digitalWrite(PIN_LED_ON, HIGH);

  pinMode(PIN_LED_VARIABLE, OUTPUT);

  pinMode(PIN_LED_MANUAL, OUTPUT);
  digitalWrite(PIN_LED_MANUAL, HIGH);
}

void loop() {
  // Increase/decrease brightness of the variable LED
  if(percentTimeOn <= 0.0) {
    increasing = true;
  }
  else if(percentTimeOn >= 1.0) {
    increasing = false;
  }
  float step = increasing ? LED_VARIABLE_STEP : -LED_VARIABLE_STEP;
  percentTimeOn += step;

  // Digital imitation of analog LED brightness
  digitalWrite(PIN_LED_VARIABLE, HIGH);
  delay(percentTimeOn * PERIOD_OF_MILLISECONDS);
  digitalWrite(PIN_LED_VARIABLE, LOW);
  delay((1-percentTimeOn) * PERIOD_OF_MILLISECONDS);
}

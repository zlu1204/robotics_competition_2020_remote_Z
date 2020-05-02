#include <Wire.h>
#include <ZumoShield.h>

ZumoReflectanceSensorArray linesensors(QTR_NO_EMITTER_PIN);
ZumoMotors motors;

void setup() {
  Serial.begin(9600);
}

unsigned int sensor_vals[6];
int BASE_SPEED = 150;
double PROPORTION_GAIN = 0.125;
double DERIVATIVE_GAIN = 0.1;
int last_error = 0;

void loop() {
  linesensors.read(sensor_vals);
  Serial.print(sensor_vals[0]);
  Serial.print(" ");
  Serial.print(sensor_vals[1]);
  Serial.print(" ");
  Serial.print(sensor_vals[2]);
  Serial.print(" ");
  Serial.print(sensor_vals[3]);
  Serial.print(" ");
  Serial.print(sensor_vals[4]);
  Serial.print(" ");
  Serial.println(sensor_vals[5]);
  delay(50);

  int line_position = linesensors.readLine(sensor_vals);
  int error = line_position - 2500;
  int error_change = error - last_error;
  int left_speed = BASE_SPEED + PROPORTION_GAIN * error + DERIVATIVE_GAIN * error_change;
  int right_speed = BASE_SPEED + -PROPORTION_GAIN * error + -DERIVATIVE_GAIN * error_change;
  last_error = error;
  motors.setSpeeds(left_speed, right_speed);
}

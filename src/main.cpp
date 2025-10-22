#include <Arduino.h>
#include "uMQ.h"
#include "Config.h"
#include "Motor.h"

uMQ radio;

void setup()
{
  Serial.begin(115200);

  radio.init(9, 10);
}

void loop()
{
  driveMotor(50, 50);
  delay(1000);
  driveMotor(0, 0);
  delay(1000);
}

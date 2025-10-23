#include <Arduino.h>
#include "uMQ.h"
#include "Config.h"
#include "Motor.h"
#include "Gyro.h"
#include "LineSens.h"

uMQ radio;


void setup()
{
  Serial.begin(115200);

  gyro_init();
  motor_init();
  radio.init(9, 10);
  init_Line_Sens();
} 

void loop()
{
  static uint32_t timer = micros();
  while (micros() - timer < Ts_us)
    ;
  timer = micros();
  gyro_tick();
  TurnToGYRO(20, 90, 0);
  Serial.print("ax: ");
  Serial.print((int)(ax * 90));
  Serial.print(" ay: ");
  Serial.print((int)(ay * 90));
  Serial.print(" az: ");
  Serial.println((int)(az * 90));
}
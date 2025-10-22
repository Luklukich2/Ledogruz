#pragma once

#include "Config.h"
#include <Arduino.h>

void driveMotor(int speedM1, int speedM2)
{
    speedM1 = constrain(speedM1, -100, 100);
    speedM2 = constrain(speedM2, -100, 100);

    float speedM1p = speedM1/100 * 255;
    float speedM2p = speedM2/100 * 255;

    analogWrite(MotPWMA, speedM1p);
    analogWrite(MotPWMB, speedM1p);

    if (speedM1 < 0)
    {
        digitalWrite(MotLogA1, LOW);
        digitalWrite(MotLogA2, HIGH);
    }
    else
    {
        digitalWrite(MotLogA1, HIGH);
        digitalWrite(MotLogA2, LOW);
    }

    if (speedM2 < 0)
    {
        digitalWrite(MotLogB1, LOW);
        digitalWrite(MotLogB2, HIGH);
    }
    else
    {
        digitalWrite(MotLogB1, HIGH);
        digitalWrite(MotLogB2, LOW);
    }
}
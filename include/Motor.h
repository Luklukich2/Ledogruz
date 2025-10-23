#pragma once

#include "GY521.h"
#include "Gyro.h"
#include "Config.h"
#include <Arduino.h>

void motor_init()
{
    pinMode(MotPWMA, OUTPUT);
    pinMode(MotPWMB, OUTPUT);
    pinMode(MotLogA1, OUTPUT);
    pinMode(MotLogA2, OUTPUT);
    pinMode(MotLogB1, OUTPUT);
    pinMode(MotLogB2, OUTPUT);
    Serial.println("Motor Init");
}

void driveMotor(int speedM1, int speedM2)
{
    speedM1 = constrain(speedM1, -100, 100);
    speedM2 = constrain(speedM2, -100, 100);

    float speedM1p = (speedM1 / 100.0) * 255.0;
    float speedM2p = (speedM2 / 100.0) * 255.0;

    analogWrite(MotPWMA, speedM1p);
    analogWrite(MotPWMB, speedM2p);

    if (speedM1p < 0)
    {
        digitalWrite(MotLogA1, LOW);
        digitalWrite(MotLogA2, HIGH);
    }
    else
    {
        digitalWrite(MotLogA1, HIGH);
        digitalWrite(MotLogA2, LOW);
    }

    if (speedM2p < 0)
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

void driveGYRO(int speedM, int time, int grad)
{
//     sensor.read();
    
//   float x = sensor.getAngleX();

//   if(grad - accuracy < x < grad + accuracy){
//     if (grad > 0 - accuracy){
//         driveMotor(speedM, -speedM);
//         delay(100);
//     }
//     else{
//         driveMotor(-speedM, speedM);
//         delay(100);
//     }
//   } 
}

void TurnToGYRO(int speedM, int grad, float accuracy)
{
  sensor.read();

  float x = sensor.getAngleX();
  float err = abs((abs(x) - grad) / 10.0);

  if(grad - accuracy > x > grad + accuracy){
    if (grad > 0 - accuracy){
        driveMotor(speedM, -speedM * err);
        delay(100);
    }
    else{
        driveMotor(-speedM * err, speedM);
        delay(100);
    }
  } 
}
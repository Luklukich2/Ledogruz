#pragma once

#include <Arduino.h>
#include <Gy521.h>

GY521 sensor(0x68);

bool normalize;
float ax;
float ay;
float az;
float gx;
float gy;
float gz;
float t;

void gyro_init()
{
    while (sensor.wakeup() == false)
    {
        // Serial.print(millis());
        // Serial.println("\tCould not connect to GY521: please check the GY521 address (0x68/0x69)");
        delay(1000);
    }
    sensor.setAccelSensitivity(2);
    sensor.setGyroSensitivity(1);
    Serial.println("Gyro Init");
}

void gyro_tick()
{
    sensor.read();
    ax = sensor.getAccelX();
    ay = sensor.getAccelY();
    az = sensor.getAccelZ();
    gx = sensor.getGyroX();
    gy = sensor.getGyroY();
    gz = sensor.getGyroZ();
    t = sensor.getTemperature();
}
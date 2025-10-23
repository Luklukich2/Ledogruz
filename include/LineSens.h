#pragma once

#include <Arduino.h>
#include "Config.h"

void init_Line_Sens(){
    pinMode(sensLine1, INPUT);
    pinMode(sensLine2, INPUT);
    pinMode(sensLine3, INPUT);
    pinMode(sensLine4, INPUT);
    pinMode(sensLine5, INPUT);
    Serial.println("Line Sens Init");
}


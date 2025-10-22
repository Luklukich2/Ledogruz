#include <Arduino.h>
#include "uMQ.h"

uMQ radio;

void setup()
{
  Serial.begin(115200);

  radio.init(9, 10);
}

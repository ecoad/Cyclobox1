#include "Arduino.h"
#include "GPSModule.h"
#include "SoftwareSerial.h"

GPSModule gpsModule;

void setup()
{
    Serial.begin(115200);

    Serial.println("Waiting for GPS lock...");
    Serial.println(""); 
}

void loop()
{
    gpsModule.read();
}

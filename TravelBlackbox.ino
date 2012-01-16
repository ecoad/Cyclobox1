#include "Arduino.h"
#include "GPSModule.h"
#include "SoftwareSerial.h"

GPSModule gpsModule;

void setup()
{
    Serial.begin(4800);

    Serial.println("Waiting for GPS lock...");
    Serial.println(""); 
    gpsModule.init();
}

void loop()
{
    gpsModule.read();
}

#include "Arduino.h"
#include "GPSModule.h"
#include "SoftwareSerial.h"

GPSModule gps;

void setup()
{
    Serial.begin(4800);

    Serial.println("Waiting for GPS lock...");
    Serial.println(""); 
    gps.init();
}

void loop()
{
    gps.read();

    //location = gps.getLocation
    
    //disk.appendToFile(location);

    //image = camera.captureImage();

    //disk.copyImage(image);

    //sleep();

}

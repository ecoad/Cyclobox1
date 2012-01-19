#include "Arduino.h"
#include "GPSModule.h"
#include "DiskModule.h"
#include "SoftwareSerial.h"
#include "SD.h"

GPSModule gps;
DiskModule disk;

void setup()
{
    Serial.begin(4800);

    Serial.println("Waiting for GPS lock...");
    Serial.println(""); 
    gps.init();
    disk.init();
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

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "GPSModule.h"

#define GPSBAUD 4800
#define GPS_RXPIN 6
#define GPS_TXPIN 7

int g = -1;
//int i;
//char messageline[80];
//bool recording = false;
SoftwareSerial gps_serial(GPS_RXPIN, GPS_TXPIN);

GPSModule::GPSModule(){}

void GPSModule::init()
{
    gps_serial.begin(GPSBAUD);   
}

void GPSModule::read()
{
   
  g = gps_serial.read();
    if (g != -1) {
      Serial.write(g); 
    }


}

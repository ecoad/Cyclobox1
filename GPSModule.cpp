#include "Arduino.h"
#include "SoftwareSerial.h"
#include "GPSModule.h"

#define GPSBAUD 4800
#define GPS_RXPIN 2
#define GPS_TXPIN 3

int i;
char messageline[80];
bool recording = false;
SoftwareSerial gps_serial(GPS_RXPIN, GPS_TXPIN);

GPSModule::GPSModule()
{
    
}

void GPSModule::read()
{
  int g;
  char speedKnots[5];

  while(gps_serial.available())
  {
    g = gps_serial.read();
    Serial.write(g); 
    if (g == 36) {
      i = 0;
      recording = true;
    }
    
    if (g == 13 & i<80) {
      recording = false;
      messageline[i+1] = 0;
      if ((messageline[5] == 67) && (messageline[18] == 65)) { //check message is GPRMC (5 == c) a and message is active (18 == A) 
        speedKnots[0] = messageline[45];
        speedKnots[1] = messageline[46];
        speedKnots[2] = messageline[47];
        speedKnots[3] = messageline[48];
        speedKnots[4] = 0;
        //showSpeed(atof(speedKnots) * 1.1508);
      }
    }
    
    if (recording) {
      messageline[i++] = g; 
    }
  }
}
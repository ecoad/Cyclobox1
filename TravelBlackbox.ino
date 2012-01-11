#include "SoftwareSerial.h"
#include "GPS.h"

#define RXPIN 2
#define TXPIN 3

#define GPSBAUD 4800

SoftwareSerial gps_serial(RXPIN, TXPIN);

int i;
char messageline[80];
boolean recording = false;

void setup()
{
  Serial.begin(115200);
  gps_serial.begin(GPSBAUD);
  
  Serial.println("Waiting for GPS lock...");
  Serial.println(""); 
}

void loop()
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
        showSpeed(atof(speedKnots) * 1.1508);
      }
    }
    
    if (recording) {
      messageline[i++] = g; 
    }

  }
}

void showSpeed(double speedMph) {
  Serial.print(speedMph);
  Serial.println("MPH");
}

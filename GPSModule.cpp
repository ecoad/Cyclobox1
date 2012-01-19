#include "Arduino.h"
#include "SoftwareSerial.h"
#include "GPSModule.h"

#define GPSBAUD 4800
#define GPS_RXPIN 6
#define GPS_TXPIN 7

int byteGPS = -1;
char line[300] = "";
char commandGpr[7] = "$GPRMC";
int commandGprCount = 0;
int index = 0;
char lat[10] = "";
char latDirection;
char lon[10] = "";
char lonDirection;


SoftwareSerial gps_serial(GPS_RXPIN, GPS_TXPIN);

GPSModule::GPSModule(){}

void GPSModule::init()
{
    gps_serial.begin(GPSBAUD);
    
    //pinMode(0, INPUT);
   //pinMode(1, OUTPUT);

    for (int i=0;i<100;i++) {
        line[i]=' ';
    }
}

void GPSModule::read()
{
   byteGPS=gps_serial.read();         // Read a byte of the serial port
   
    if (byteGPS == -1) {

    } else {

        line[index] = byteGPS;
        index++;

        if (byteGPS==13){
          Serial.println(line);
          commandGprCount = 0;
          if ((line[6] == 'C') && (line[19] == 'A')) { //$GPRMC and A(ctive) signal

              index = 0;
              //Lat
              for (int i=21;i < 30;i++){
                  lat[index] = line[i];
                  index++;
              }
              //lat[9] = 13;

              latDirection = line[31];

              Serial.print(lat);
              Serial.println(latDirection);

              index = 0;
              
              //lon
              for (int i=33;i < 43;i++){
                  lon[index] = line[i];
                  index++;
              }
              //lon[9] = 13;

              lonDirection = line[44];

              Serial.print(lon);
              Serial.println(lonDirection);
              Serial.println("...");
          }

          index = 0;
        }
    }
   
    /*
    byteGPS = gps_serial.read();
    //Serial.println(byteGPS);

    if (byteGPS == -1) { // See if the port is empty yet
        delay(100); 
        Serial.println('.');   
    } else {
        Serial.println('+');   
        linea[conta]=byteGPS;        // If there is serial port data, it is put in the buffer
        conta++;                      
        //gps_serial.write(byteGPS); 
        if (byteGPS==13){            // If the received byte is = to 13, end of transmission
            //digitalWrite(ledPin, LOW);
            
            cont=0;
            bien=0;

            for (int i=1; i<7 ;i++){ // Verifies if the received command starts with $GPR
                if (linea[i]==comandoGPR[i-1]){
                   bien++;
                }
            }

            if(bien == 6){ // If yes, continue and process the data
                for (int i=0;i<300;i++){
                    if (linea[i]==','){    // check for the position of the  "," separator
                        indices[cont]=i;
                        cont++;
                    }
                    if (linea[i]=='*'){    // ... and the "*"
                        indices[12]=i;
                        cont++;
                    }
                }
                Serial.println("");      // ... and write to the serial port
                Serial.println("");
                Serial.println("---------------");
                for (int i=0;i<12;i++){
                    switch(i) {
                        case 0 :Serial.print("Time in UTC (HhMmSs): ");break;
                        case 1 :Serial.print("Status (A=OK,V=KO): ");break;
                        case 2 :Serial.print("Latitude: ");break;
                        case 3 :Serial.print("Direction (N/S): ");break;
                        case 4 :Serial.print("Longitude: ");break;
                        case 5 :Serial.print("Direction (E/W): ");break;
                        case 6 :Serial.print("Velocity in knots: ");break;
                        case 7 :Serial.print("Heading in degrees: ");break;
                        case 8 :Serial.print("Date UTC (DdMmAa): ");break;
                        case 9 :Serial.print("Magnetic degrees: ");break;
                        case 10 :Serial.print("(E/W): ");break;
                        case 11 :Serial.print("Mode: ");break;
                        case 12 :Serial.print("Checksum: ");break;
                    }

                    for (int j=indices[i];j<(indices[i+1]-1);j++){
                        Serial.print(linea[j+1]); 
                    }
                    Serial.println("");
                }
                Serial.println("---------------");
            }
            conta=0;                    // Reset the buffer
            for (int i=0;i<300;i++){    //  
                linea[i]=' ';             
            }                 
        }
    }
    */
}

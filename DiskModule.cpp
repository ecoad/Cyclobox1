#include "Arduino.h"
#include "DiskModule.h"
#include "SD.h"
#define CHIP_SELECT 10

DiskModule::DiskModule(){}

void DiskModule::init()
{
    if (!SD.begin(CHIP_SELECT)) {
        Serial.println("SD card failed or not present");
        return;
    }

    char filename[13];
    strcpy(filename, "TEST01.TXT");

    if (!SD.exists(filename)) {
        int32_t time = millis();

        Serial.println("Create new file");
        File testFile = SD.open(filename, FILE_WRITE);

        Serial.println("Writing to file");
        //testFile.write(filename);

        testFile.close();
        time = millis() - time;
        Serial.println("Done!");
        Serial.print("Took "); Serial.print(time); Serial.println(" ms");
    } else {
        Serial.println("File already exists");
    }

}



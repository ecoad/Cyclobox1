#ifndef GPSModule_h
#define GPSModule_h

#include "Arduino.h"

class GPSModule
{
  public:
    GPSModule();
    void init();
    void read();
  private:
    int i;
    char messageline[80];
    bool recording;
};

#endif

#ifndef WifiConnection_h
#define WifiConnection_h

#include "Arduino.h"

class WifiConnection
{
  public:
  WifiConnection(char* ssid, char* password);
  void wifiConnect();
  private:
  char* _wifissid; 
  char* _wifipassword; 
};

#endif

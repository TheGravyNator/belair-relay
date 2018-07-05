#ifndef WifiServer_h
#define WifiServer_h

#include "Arduino.h"
#include "JSONParser.h"
#include "Relay.h"
#include <ESP8266WebServer.h>

class WifiServer
{
  public:
  WifiServer(int serverport, JSONParser jsonparser, Relay* relay);
  void startServer();
  void runServer();
  private:
  ESP8266WebServer _espserver;
  JSONParser _jsonparser;
  Relay* _relay;
};

#endif

#ifndef JSONParser_h
#define JSONParser_h

#include "Arduino.h"
#include <ArduinoJson.h>

class JSONParser
{
  public: 
  int parseJSON(String json_string); 
};

#endif

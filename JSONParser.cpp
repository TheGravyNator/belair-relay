#include "Arduino.h"
#include "JSONParser.h"
#include <ArduinoJson.h>

int JSONParser::parseJSON(String json_string)
{
  StaticJsonBuffer<200> newBuffer;
  JsonObject& newjson = newBuffer.parseObject(json_string);
  return newjson["delay"];
}

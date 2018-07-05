#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "Constants.h"
#include "Secret.h"
#include "Relay.h"
#include "JSONParser.h"
#include "WifiConnection.h"
#include "WifiServer.h"

Relay relay(RELAY_PIN);
JSONParser jsonparser;
WifiConnection connection(WIFI_SSID, WIFI_PASS);
WifiServer server(SERVER_PORT, jsonparser, &relay);

void setup() 
{
  Serial.begin(BAUD_RATE);
  connection.wifiConnect();
  relay.init();
  server.startServer();
}

void loop() 
{ 
  if(WiFi.status() != WL_CONNECTED)
  {
    connection.wifiConnect();
  }
  server.runServer();
}

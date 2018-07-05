#include "Arduino.h"
#include "WifiServer.h"
#include "JSONParser.h"
#include "Relay.h"

WifiServer::WifiServer(int serverport, JSONParser jsonparser, Relay* relay)
{
  ESP8266WebServer server(serverport); 
  _espserver = server;
  _jsonparser = jsonparser;
  _relay = relay;
}

void WifiServer::startServer()
{
  _espserver.on("/", HTTP_POST, [this]()
  {
    if(_espserver.arg("plain") == false)
    {
      _espserver.send(200, "text/plain", "Body not received");
    }
    else
    {
      _espserver.send(200, "text/plain", "Body received"); 
      Serial.println("Request received");
      int delay_amount = _jsonparser.parseJSON(_espserver.arg("plain"));
      Serial.println("The requested delay is " + (String)delay_amount);
      _relay->trigger(delay_amount);
    }
  });
  _espserver.begin();  
}

void WifiServer::runServer()
{
  _espserver.handleClient();
}


#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#include <arduino-timer.h>
#include <ArduinoLog.h>

#include "arduino_secrets.h"
#include "configuration.hpp"
#include "html.h"

///////enter your sensitive data in the Secret tab/arduino_secrets.h
char hostname[] = _HOSTNAME;
char ssid[] = _SSID;     // your network SSID (name)
char pass[] = _PASSWORD; // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;        // your network key Index number (needed only for WEP)

ESP8266WebServer webServer(80);

auto timer = timer_create_default();

// Forward declarations
void handleRoot();
void handlePowerOn();
void handleLongPress();

void printWifiStatus()
{
  // print the SSID of the network you're attached to:
  Log.traceln(F("SSID: %s" CR), WiFi.SSID());

  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Log.traceln(F("IP Address: %s" CR), ip.toString().c_str());

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Log.traceln("signal strength (RSSI): %l dBm" CR, rssi);
}

/******************************************
 * SETUP
 ******************************************/
void setup()
{
  Serial.begin(9600);

  pinMode(POWER_PIN, OUTPUT);

  // Initialize with log level and log output.
  Log.begin(LOG_LEVEL_ERROR, &Serial);

  Log.infoln("Connecting to WIFI...");

  // Some ESP8266 modules broadcast their own network, this turns that off
  WiFi.mode(WIFI_STA);
  WiFi.hostname(hostname);

  // attempt to connect to the Wifi network defined in arduino_secrets.h
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Log.traceln(".");
  }

  Log.infoln("Connected to wifi");
  printWifiStatus();

  // Webserver
  webServer.on("/", handleRoot);
  webServer.on("/poweron", HTTP_GET, handlePowerOn);
  webServer.on("/longpress", HTTP_GET, handleLongPress);

  webServer.begin();
}

void handleRoot() {
  String s = HTML_INDEX;
  webServer.send(200, "text/html", s);
}

void handlePowerOn() {
  Log.traceln("handlePowerOn");

  digitalWrite(POWER_PIN, HIGH);
  delay(500);
  digitalWrite(POWER_PIN, LOW);

  webServer.send(200, "text/plain", "ok");           
}

void handleLongPress() {
  Log.traceln("handleLongPress");

  digitalWrite(POWER_PIN, HIGH);
  delay(5000);
  digitalWrite(POWER_PIN, LOW);

  webServer.send(200, "text/plain", "ok");           
}


/******************************************
 * SETUP
 ******************************************/
void loop()
{
  webServer.handleClient();
  timer.tick();
}
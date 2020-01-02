#include "index.h"

/*
   Hello world web server
   circuits4you.com
*/
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`

// Initialize the OLED display using Wire library
SSD1306Wire  display(0x3c, D4, D5);


//SSID and Password to your ESP Access Point
const char* ssid = "Military games timer";
const char* password = "strikeball";

ESP8266WebServer server(80); //Server on port 80

//==============================================================
//     This rutine is exicuted when you open its IP in browser
//==============================================================
/*void handleRoot() {
  String s = MAIN_page; //Read HTML contents
  server.send(200, "text/html", s); //Send web page
  }*/
void printScores(void) {
  display.clear();
  display.drawString(0, 0, "Yellow: " + random(1,99) );
  display.drawString(0, 16, "Blue: " + random(1,99) );
  display.drawString(0, 32, "Green: " + random(1,99) );
}

void handleRoot() {
  server.send(200, "text/plain", "Scores hardcoded for current moment");
}
//===============================================================
//                  SETUP
//===============================================================
void setup(void) {
  //Serial.begin(9600);
  //Serial.println("");
  WiFi.mode(WIFI_AP);           //Only Access point
  WiFi.softAP(ssid, password);  //Start HOTspot removing password will disable security

  IPAddress myIP = WiFi.softAPIP(); //Get IP address
  //Serial.print("HotSpt IP:");
  //Serial.println(myIP);

  server.on("/", handleRoot);      //Which routine to handle at root location

  server.begin();                  //Start server
  //Serial.println("HTTP server started");
  display.init();

}
//===============================================================
//                     LOOP
//===============================================================
void loop(void) {
  server.handleClient();          //Handle client requests
  printScores();
  display.display();
}

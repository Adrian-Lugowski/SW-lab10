#include <ESP8266WiFi.h>

const char* ssid = "nazwa_sieci";
const char* password = "haslo_sieci";
const char* host = "192.168.4.1"; // IP Access Pointa prowadzącego

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Połączono z WiFi");

  WiFiClient client;
  if (client.connect(host, 80)) {
    client.println("Hello Kowalski,Nowak,Wiśniewski");
    Serial.println("Wysłano komunikat");
  }
}

void loop() {}

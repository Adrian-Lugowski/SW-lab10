#include <ESP8266WiFi.h>

WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  WiFi.softAP("MojaSiec", "12345678"); // Nazwa i hasło AP
  IPAddress IP = WiFi.softAPIP();
  Serial.print("IP AP: ");
  Serial.println(IP);

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String request = client.readStringUntil('\r');
    Serial.println("Odebrano: " + request);

    client.println("Bye");
    client.flush();
  }
}

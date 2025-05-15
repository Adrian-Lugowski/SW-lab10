#include <ESP8266WiFi.h>

const char* ssid = "MojaSiec";
const char* password = "12345678";

WiFiServer server(80);
const int ledPin = D1;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  Serial.print("Access Point IP: ");
  Serial.println(WiFi.softAPIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;

  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  if (request.indexOf("GET /on") != -1) {
    digitalWrite(ledPin, HIGH);
  }
  if (request.indexOf("GET /off") != -1) {
    digitalWrite(ledPin, LOW);
  }

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println();
  client.println("<html><body>");
  client.println("<h1>Sterowanie dioda</h1>");
  client.println("<a href=\"/on\"><button>Włącz</button></a>");
  client.println("<a href=\"/off\"><button>Wyłącz</button></a>");
  client.println("</body></html>");
}

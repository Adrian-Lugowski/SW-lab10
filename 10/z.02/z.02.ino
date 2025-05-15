#include <ESP8266WiFi.h> int status = WL_IDLE_STATUS; 
 const char* ssid = "SWnetwork";  // your network SSID (name) const char* pass = "secretPass1"; 
 
WiFiClient client; const char* host = "192.168.1.11";  //server netowrk address 
 
void setup() { 
  Serial.begin(9600); 
  //connecting to WIFI here 
  Serial.println("Connecting to WiFi"); 
  //Init ESP8266 Wifi   WiFi.begin(ssid, pass);   while (WiFi.status() != WL_CONNECTED) {     delay(500); 
    Serial.print("."); 
  } 
  Serial.print(" connected to Wifi! IP address : "); 
  Serial.println(WiFi.localIP());  // Print the IP address 
  Serial.println("Connecting to the server"); 
  //if connection is a success, send a message to the server 
  if (client.connect(host, 80))  //server address and port 
  { 
    // we are connected to the host.     Serial.println("Sending Hello...");     client.print("Hello!\n"); 
  } else { 
    // connection failure 
    Serial.println("Connection failure"); 
  } 
  Serial.println("Listening for server response"); 
}  void loop() {    while (client.connected()) {     if (client.available()) { 
      String line = client.readStringUntil('\n'); 
      Serial.println(line); 
    } 
  } 
}

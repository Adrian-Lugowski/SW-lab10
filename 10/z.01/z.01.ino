#include <ESP8266WiFi.h> 
 const char* ssid = "SWnetwork";  // your network SSID (name) const char* pass = "secretPass1"; 
 
IPAddress local_IP(192, 168, 1, 11); IPAddress gateway(192, 168, 1, 11); 
IPAddress netmask(255, 255, 255, 0); 
WiFiServer server(80); 
 int clientsConnected; 
 
void setup() { 
  Serial.begin(9600); 
  Serial.println("Configuring access point..."); 
 
  Serial.print("Setting soft-AP configuration ... "); 
  Serial.println(WiFi.softAPConfig(local_IP, gateway, netmask) ? "Ready" : 
"Failed!"); 
 
  Serial.print("Setting soft-AP ... "); 
  Serial.println(WiFi.softAP(ssid, pass) ? "Ready" : "Failed!");  
  Serial.print("Soft-AP IP address = "); 
  Serial.println(WiFi.softAPIP()); 
 
  server.begin(); 
  Serial.println("Waiting for clients..."); 
}  void loop() {   if (clientsConnected != WiFi.softAPgetStationNum()) {     clientsConnected = WiFi.softAPgetStationNum(); 
    Serial.printf("New client connected to soft-AP = %d\n", 
WiFi.softAPgetStationNum()); 
  } 
  WiFiClient client = server.available();   if (client) { 
    Serial.println("\n[Client available]");     while (client.connected()) { 
      // read line by line what the client is requesting       if (client.available()) { 
        String line = client.readStringUntil('\n');         Serial.print(line);         client.print("Hi!\n");         client.flush();         delay(1);  //give client some time to get the data         client.stop(); 
      } 
    } 
    Serial.println("[Client disonnected]"); 
  } 
}

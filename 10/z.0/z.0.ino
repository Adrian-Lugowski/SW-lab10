#include <ESP8266WiFi.h> 
 int status = WL_IDLE_STATUS; 
 const char* ssid = " SWnetwork";  // your network SSID (name) const char* pass = "secretPass1"; 
 
void setup() { 
  Serial.begin(9600); 
  WiFi.begin(ssid, pass);  //connecting to wifi 
  Serial.print("Connecting to ");   Serial.print(ssid);   delay(500); 
   while (WiFi.status() != WL_CONNECTED)  //waiting for connection to be established   { 
    delay(500); 
    Serial.print("."); 
  } 
 
  Serial.println(); 
  Serial.println("Conneted!");   Serial.print("SSID: "); 
  Serial.println(WiFi.SSID()); 
  IPAddress ip = WiFi.localIP();  //assigned ip address to our device 
  Serial.print("IP Address: "); 
  Serial.println(ip); 
}  
void loop() {}

#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>

ESP8266WebServer server;

char* SSID_User="Nokia";
char* SSID_Pass="balanaguyashwanth1";

void setup()
{
  Serial.begin(115200);
  WiFi.begin(SSID_User,SSID_Pass);

  Serial.println("connecting");

  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print("..");
  }
   Serial.println("Conneted");
   
  Serial.println(WiFi.localIP());
  
  server.on("/",[](){server.send(200,"text/plain","HelloWorld");});
  server.begin();
 }

void loop()
{
  server.handleClient();
   Serial.println(WiFi.localIP());
}

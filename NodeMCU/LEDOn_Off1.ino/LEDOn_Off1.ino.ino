
#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>
#include<ArduinoJson.h>

char* SSID_Name="Nokia";
char* SSID_Pass="balanaguyashwanth1";

ESP8266WebServer server(80);
char temp[400];
void toggle()
{
  snprintf(temp,400,
"<html>\
  <head>\
    </head>\ 
        <body>\
            <a href=\"/1\"><button>  ledon  </button></a>\
            <a href=\"/0\"> <button> ledoff  </button></a>\
        </body>\
</html>");
  server.send(200,"text/HTML",temp);
}

void ledon()
{
  pinMode(D7,OUTPUT);
  digitalWrite(D7,HIGH);
  delay(1000);
  server.send(200,"text/HTML",temp);
}

void ledoff()
{
  pinMode(D7,OUTPUT);
  digitalWrite(D7,LOW);
  delay(1000);
  server.send(200,"text/HTML",temp);
}


void setup(void) {
  Serial.begin(115200);
  //WiFi.mode(WIFI_STA);
  WiFi.begin(SSID_Name,SSID_Pass);
  server.begin();
 while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println(".");
  }
  Serial.println("Connected");
  Serial.println("SSID");
  Serial.println(WiFi.localIP());
 
  server.on("/",toggle);
  server.on("/1",ledon);
  server.on("/0",ledoff); 
  
}

void loop(void) {
 server.handleClient();
// String data=server.arg("plain");
// StaticJsonDocument<200> doc;
// DeserializationError error = deserializeJson(doc,data);
// long jdata=doc[data];
// long msg=jdata["message"];
// server.send(204,"");
}

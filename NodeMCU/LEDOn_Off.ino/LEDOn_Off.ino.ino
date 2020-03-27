#include <ESP8266WiFi.h> 
#include <ESP8266WebServer.h> 

const char* ssid = "Nokia";
const char* password = "balanaguyashwanth1";

ESP8266WebServer server(80);
char temp[400];
void handleRoot() 
{
  snprintf(temp, 400,
"<html>\
  <head>\
  </head>\
    <body>\
      <a href=\"/1\"><button>  ledon  </button></a>\
      <a href=\"/0\"> <button> ledoff  </button></a>\
    </body>\
</html>");



  server.send(200, "text/html", temp);
}


void ledOn() 
{
  pinMode(16, OUTPUT);
  digitalWrite(16, HIGH);
  delay(1000);
  server.send(200, "text/html", temp);
}

void ledOff() 
{
  pinMode(16, OUTPUT);
  digitalWrite(16, LOW);
  delay(1000);
  server.send(200, "text/html", temp);
}


void setup(void)
{

  Serial.begin(115200);
  Serial.println("Connecting to network");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);   // Connect to WiFi network

  while (WiFi.status() != WL_CONNECTED)
  {   
    // Wait for connection
    delay(500);
    Serial.println(".");
  }

  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/0", ledOff);
  server.on("/1", ledOn);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void)
{
  server.handleClient();
}

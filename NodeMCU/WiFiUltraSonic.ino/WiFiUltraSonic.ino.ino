#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>

ESP8266WebServer server;

char* SSID_User="Nokia";
char* SSID_Pass="balanaguyashwanth1";

String distance1,web;
int distance;

void toggle()
{
  web="<h3>"+distance1+"</h3>";
  server.send(200,"text/HTML",web);
}

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
  
  server.on("/t",toggle);
  server.begin();
 }   

void loop()
{
  int trig=D6;
  int echo=D7;
  pinMode(trig,OUTPUT); //trig
  pinMode(echo,INPUT); //echo
  Serial.begin(9600);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(20);
  digitalWrite(trig,LOW);
  
   int duration = pulseIn(echo,HIGH);
  distance= duration*0.034/2;
  distance1=(String)distance;
  Serial.println(distance);
  //delay(100);
  server.handleClient();
}

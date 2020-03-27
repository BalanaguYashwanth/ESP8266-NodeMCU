#  include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>


//const char*  index_html[] PROGMEM={"<?xml version='1.0'?>\n"" <data>+ data +</data>"};

char index_html[400];
String data,web;
ESP8266WebServer server(80);

char* SSID_Name="Nokia";
char* SSID_Pass="balanaguyashwanth1";

void home2()
{
  snprintf(index_html,400, 
  "<?xml version='1.0'?>\n"
  "<data>+\" data \"+</data>");
  server.send(200,"text/XML",index_html);
}

void home1()
{
  pinMode(D7,INPUT); //ECHO
  pinMode(D6,OUTPUT); //TRIG
  
 int trig=D6;
 int echo=D7;
  digitalWrite(trig,LOW);
  delay(2000);
  digitalWrite(trig,HIGH);
  delay(2000);
  digitalWrite(trig,LOW);
  
int  duration = pulseIn(echo,HIGH);
int  distance = (duration/2)/39.1;
  if(distance>0 && distance<10)
  {
    Serial.println("ON");
    //delay(1000);
   }
  Serial.print(" Distance:");
  Serial.println(distance);

  data=distance;
  data =(String)data;
  data=(String)data;
  server.send(200,"text/HTML",data);
} 

void setup(void) {
  Serial.begin(115200);
  WiFi.begin(SSID_Name,SSID_Pass);


  if(WiFi.status()!= WL_CONNECTED)
  {
    Serial.println(".");
    Serial.begin(500);
  }
  Serial.println(SSID_Name);
  Serial.println("connected to");
  Serial.println(WiFi.localIP());
  server.on("/",home1);
  server.on("/home2",home2);
  server.begin();
}

void loop(void) {

  server.handleClient();
}

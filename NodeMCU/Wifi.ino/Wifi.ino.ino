#include<ESP8266WiFi.h>

char* SSID_Name="Redmi1";
char* SSID_Pass="yashu12345";

void setup()
{
  Serial.begin(115200);
  WiFi.begin(SSID_Name,SSID_Pass);
  Serial.print("conecting");

  while( WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }

  Serial.print("connected");
  Serial.println( WiFi.localIP());

}
void loop()
{
  Serial.println( WiFi.localIP());

  
}

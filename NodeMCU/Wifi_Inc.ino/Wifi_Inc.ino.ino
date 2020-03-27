#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>

ESP8266WebServer server;

char* SSID_User="Nokia";
char* SSID_Pass="balanaguyashwanth1";

String data,data1,xml,web;
int inc=0;

char index_html;

const char js_html[] PROGMEM={"<html>\n"
    "<head>\n"
      "<script type=\"text/javascript\">\n"
          "\n"
             "\n"
                "    function change()\n"
                        "    {\n"
                                 "        var xmlhttp=new XMLHttpRequest();\n"
                                                        "\n"
                                                          "        \n"
                                                                 "          xmlhttp.onreadystatechange=function()\n"
                                                                                                 "        {\n"
                                                                                                        "           xmlResponse=xmlhttp.responseXML;\n"
                                                                                                                        " element= xmlResponse.getElementsByTagName(\"data\")[0].firstChild.nodeValue;\n"
                                                                                                  "              document.getElementById(\"result\").innerHTML=element;\n"
                                                                                                "        }\n"
                                                                                                  "\n"
                                                                                        "        xmlhttp.open('PUT','xml',true);\n"
                                                                            "        xmlhttp.send(null);\n"
                                        "        document.getElementsByTagName(\"p\").innerHTML = \"processing....\";\n"
                                                      "\n"
                                                      "\n"
                                                "    }\n"
                                            "</script>\n"
                                                  "\n"
                                                "</head>\n"
                                                "\n"
                                        "<body onload=\"change()\">\n"
                                        "\n"
                                       "\n"
                        "<p id='result'> results </p>\n"
                    "<button onclick=\"change()\"> submit </button>\n"
                   "\n"
         "</body>\n"
 "</html>\n"""};

void togglex()
{
  
  xml="<?xml version='1.0'?>";
  xml+="<data>";
  xml+= data ;
  xml+="</data>";
  
   server.send(200,"text/xml",xml);
}

void togglejs()
{
    
  server.send_P(200,"text/HTML",js_html);
  
}


void toggle()
{
  web="<p id='p1'>"+ data +"</p>";
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
  
  //server.on("/",[](){server.send(200,"text/plain","HelloWorld");});
  server.on("/web",toggle);
  server.on("/xml",togglex);
  server.on("/js",togglejs);
  server.begin();
}

void loop()
{
  server.handleClient();
  inc=inc+1;
  data=(String)inc;
   Serial.println(WiFi.localIP());
}



char data;
void setup() {
  pinMode(D8,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  
  while(Serial.available())
  {
    delay(18);
    int data=Serial.read();
  }
     if(data==LOW)
     {
      digitalWrite(D8,LOW);
      Serial.print("LED OFF");
      //delay(1000);       
     }
     if(data==HIGH)
     {
      digitalWrite(D8,HIGH);
      Serial.print("LED HIGH");
      //delay(2000);       
     }
 //     data=""; 
  }
  

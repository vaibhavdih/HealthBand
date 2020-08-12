#include<SoftwareSerial.h>
#include <ESP8266WiFi.h>  
#include <WiFiClient.h>  
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>



SoftwareSerial nodemcu(D2,D3);


void setup(){
  Serial.begin(115200);                                  //Serial connection
  WiFi.begin("vaibhav", "12345678");   //WiFi connection
 
  while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion
 
    delay(500);
    Serial.println("Waiting for connection");
  
  
  
}
nodemcu.begin(57600);
}
void loop(){
 while(nodemcu.available()>0){
  
  int bpm = nodemcu.parseInt();
  float temp = nodemcu.parseFloat();
  Serial.print("BPM = ");
  Serial.print(bpm);
  Serial.print("   temperature =");
  Serial.println(temp);
   if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
 
   String postData,ADCtemp,ADCbpm;
   ADCbpm = String(bpm);
   ADCtemp = String(temp);
   HTTPClient http;    //Declare object of class HTTPClient
   postData = "heartbeat=" + ADCbpm + "&temperature=" + ADCtemp ;
   http.begin("http://192.168.43.12:8000/health/data/");      //Specify request destination
   http.addHeader("Content-Type", "application/x-www-form-urlencoded");  //Specify content-type header
 
   int httpCode = http.POST(postData);   //Send the request
   String payload = http.getString();                  //Get the response payload

   Serial.println(httpCode);   //Print HTTP return code
   Serial.println(payload);    //Print request response payload
 
   http.end();  //Close connection
 
 }
 delay(30);
  }
  }

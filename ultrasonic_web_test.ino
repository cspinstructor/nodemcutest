

// see the corresponing node.js project:
// nodemcutest
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

//const char* ssid     = "integer9711";
//const char* password = "xxx";
const char* ssid     = "LINK2";
const char* password = "xxx";

const int triggerPin = D3;      // pin connected to Trig Pin in the ultrasonic distance sensor
const int echoPin = D4;      

//WiFiClient wifiClient;
 
void setup() 
{
    Serial.begin(9600);
    pinMode(triggerPin,OUTPUT);        // Trigger is an output pin
    pinMode(echoPin,INPUT);
       
}
 
void loop() 
{      
  if(WiFi.status() != WL_CONNECTED ){
    Serial.println("Wifi not connected...");
    WiFi.begin(ssid, password); 
  } 
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  } 

  Serial.print("Connected to: "); Serial.println(WiFi.SSID());
  Serial.print("Your IP: "); Serial.println(WiFi.localIP());

  int value = getSensorDistance();
  
  HTTPClient http;
  //http.begin("http://192.168.1.100/index.html");
  //http.begin("blynk-cloud.com", 80, "/d71ef867ed0f4a4b821d1f6d42b2abf9/get/V5");
  String datatosend = "/?sensor=" + String(value);
  Serial.print("Sensor value: "); Serial.println(datatosend);
  http.begin("192.168.1.101", 3000, datatosend);
  int httpCode = http.GET();
  
  if(httpCode > 0){
    Serial.printf("GET code: %d\n", httpCode);
    if(httpCode == HTTP_CODE_OK){
      String response = http.getString();
      Serial.println(response);
    }
  } else {
    Serial.printf("GET failed: error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();
  delay(10000);
}

int getSensorDistance()
{
  long duration;
/*--- trigger ping burst and wait for echo from measured object----------------------*/ 
  digitalWrite(triggerPin, LOW);                   
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);          // Trigger pin to HIGH
  delayMicroseconds(10);                   // 10us high 
  digitalWrite(triggerPin, LOW);           // Trigger pin to LOW
  duration = pulseIn(echoPin,HIGH); 
  return (duration/2) / 29.386;            // return distance in cm
}

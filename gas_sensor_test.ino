// MQ135.h downloaded from: https://github.com/GeorgK/MQ135
// Code: https://github.com/MurrayBoz/NodeMCU-MQ135

#include <MQ135.h>

float airTemperature, airHumidity, ppm, ppmbalanced, rzero;

MQ135 gasSensor = MQ135(A0);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  rzero = gasSensor.getRZero(); //this to get the rzero value, uncomment this to get ppm value
  Serial.print("RZero=");
  Serial.println(rzero); // this to display the rzero value continuously, uncomment this to get ppm value
   
//  ppm = gasSensor.getPPM(); // this to get ppm value, uncomment this to get rzero value
//  Serial.print("PPM=");
//  Serial.println(ppm); // this to display the ppm value continuously, uncomment this to get rzero value
  
//  ppmbalanced = gasSensor.getCorrectedPPM(airTemperature, airHumidity); // this to get ppm value, uncomment this to get rzero value
//  Serial.print("PPM Corrected=");
//  Serial.println(ppmbalanced); // this to display the ppm value continuously, uncomment this to get rzero value
  delay(500);
}

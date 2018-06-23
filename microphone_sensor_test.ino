// calibration: adjst screw until close to 1024 then test
// until it can detect a certain treshold.

const int analogPin = A0;
//const int sensorPin = D2;

int value = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(sensorPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(analogPin);
  //int value = digitalRead(sensorPin);
  if(value == 1024) {
    Serial.println("Sound detected");
  }
  
  delay(100);
}

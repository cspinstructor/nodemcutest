

/*--------ultrasonic sensor------------------*/
const int triggerPin = D3;      // pin connected to Trig Pin in the ultrasonic distance sensor
const int echoPin = D4;         // pin connected to Echo Pin in the ultrasonic distance sensor
boolean newThreshold=true;     // boolean flag to indicate if it is a new threshold event 
byte thresholdDistance=15; 

void setup() 
{
/*----open serial communications ---------*/ 
  Serial.begin(9600);
/*----setting each digital pin mode-------*/
  pinMode(triggerPin,OUTPUT);        // Trigger is an output pin
  pinMode(echoPin,INPUT);            // Echo is an input pin
  Serial.println("System is ready...");
}
/******************************************/
void loop() 
{
/*------check every sensor in endless loop---------*/  
 
  Serial.println(getSensorDistance());
  delay(500);      // delay between the sensors reading 
  
}

/******************************************/
// Ultrasonic Sensor Functions 
/******************************************/
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




const int inputPin = D2;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(inputPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long value = pulseIn(inputPin, HIGH);
  Serial.print("value: "); Serial.println(value);
  if (value > 100) {
    Serial.println("vibration detected");
  }
 
  delay(100);
}

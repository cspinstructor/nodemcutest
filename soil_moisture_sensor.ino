double analogValue = 0.0;

void setup() {
 Serial.begin(9600);

}

void loop() {
  analogValue = analogRead(A0);
  Serial.println(analogValue);
  delay(500);
}

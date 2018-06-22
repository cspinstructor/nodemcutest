int led = D6;
int sensor = D7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long state = digitalRead(sensor);
  if(state == HIGH) {
    digitalWrite(led, HIGH);
    Serial.println("Motion detected!");
    delay(200);
  } else {
    digitalWrite (led, LOW);
    Serial.println("Motion absent");
    delay(200);
  }
}

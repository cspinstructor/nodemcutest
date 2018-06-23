// Based on:  
// http://www.instructables.com/id/Interfacing-Servo-Motor-With-NodeMCU/
// If your servo has Orange - Red - Brown wires, then connect it as follows:
// Orange wire connects to Digital pin D2.
// Brown wire connects to GND pin
// Red wire connects to 3V3 pin

#include <Servo.h>

Servo servo;

void setup() {
 
  servo.attach(D2);
  servo.write(0);
  delay(2000);

}

void loop() {
  servo.write(90);
  delay(1000);
  servo.write(0);
  delay(1000);
}

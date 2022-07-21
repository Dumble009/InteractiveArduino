#include <Servo.h>
Servo myservo;
const int pin = 9;
int val;
String incomingByte;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(pin);
}
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    incomingByte = Serial.readStringUntil('\n');
    val = incomingByte.toInt();
  }
  myservo.write(val);
  delay(15);
}

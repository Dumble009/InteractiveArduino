#include <Servo.h>
Servo myservo;
const int pin = 9;
int val;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(pin);
  pinMode(13, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    delay(20);
    val = 0;
    while(Serial.available() > 0){
      char c = Serial.read();
      if(c == '\n'){
        break;
      }
      val *= 10;
      val += c - '0';
    }
      Serial.println(val);
  digitalWrite(13, HIGH);
  delay(val * 1000);
  }else{
    
  digitalWrite(13, LOW);
  }
  //myservo.write(val);
  //delay(15);
}

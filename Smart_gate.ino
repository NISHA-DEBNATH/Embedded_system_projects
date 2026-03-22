#include <Servo.h>

Servo gate;

int trigPin = 9;
int echoPin = 10;
long duration;
int distance;

void setup() {
  gate.attach(6);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  gate.write(0); 
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance < 20) {   
    gate.write(90);     
    delay(5000);        
    gate.write(0);    
  }

  delay(500);
}
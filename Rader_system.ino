#include <Servo.h>
Servo myServo;

int trigPin = 9;
int echoPin = 10;
int buzzer = 8;

int greenLED = 4;
int redLED = 5;

long duration;
int distance;

// Function to get distance
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  return distance;
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  myServo.attach(6);

  Serial.begin(9600);
}

void loop() {

  // LEFT → RIGHT
  for (int pos = 0; pos <= 180; pos++) {
    myServo.write(pos);
    delay(20);

    int d = getDistance();
    Serial.println(d);

    if (d > 2 && d < 20) {   // Object detected

      // Green blink first
      digitalWrite(greenLED, HIGH);
      delay(100);
      digitalWrite(greenLED, LOW);
      delay(100);

      // Red ON + Buzzer ON
      digitalWrite(redLED, HIGH);
      digitalWrite(buzzer, HIGH);

    } else {   // No object

      digitalWrite(buzzer, LOW);
      digitalWrite(redLED, LOW);

      // Green steady ON
      digitalWrite(greenLED, HIGH);
    }
  }

  // RIGHT → LEFT
  for (int pos = 180; pos >= 0; pos--) {
    myServo.write(pos);
    delay(20);

    int d = getDistance();
    Serial.println(d);

    if (d > 2 && d < 20) {

      digitalWrite(greenLED, HIGH);
      delay(100);
      digitalWrite(greenLED, LOW);
      delay(100);

      digitalWrite(redLED, HIGH);
      digitalWrite(buzzer, HIGH);

    } else {
      digitalWrite(buzzer, LOW);
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, HIGH);
    }
  }
}
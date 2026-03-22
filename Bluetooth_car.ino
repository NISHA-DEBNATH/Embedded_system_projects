#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// Motor A
#define IN1 26
#define IN2 27
#define ENA 25

// Motor B
#define IN3 14
#define IN4 12
#define ENB 33

char command;

void setup() {

  Serial.begin(115200);
  SerialBT.begin("ESP32_CAR");   // Bluetooth name

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {

  if (SerialBT.available()) {

    command = SerialBT.read();

    if (command == 'F') {
      forward();
    }

    else if (command == 'B') {
      backward();
    }

    else if (command == 'L') {
      left();
    }

    else if (command == 'R') {
      right();
    }

    else if (command == 'S') {
      stopRobot();
    }
  }
}
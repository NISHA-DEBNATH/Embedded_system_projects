int pirPin = 2;
int buzzer = 8;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(buzzer, OUTPUT);

  delay(30000); 
}

void loop() {
  int motion = digitalRead(pirPin);

  if (motion == HIGH) {
    digitalWrite(buzzer, HIGH);
    delay(3000);
    digitalWrite(buzzer, LOW);

    delay(2000); 
  }
}
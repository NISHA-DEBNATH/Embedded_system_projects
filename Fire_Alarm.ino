#define FLAME_PIN A0     // Flame sensor analog pin
#define BUZZER 8         // Buzzer pin

int threshold = 400;     // Adjust this value (lower = more sensitive)

void setup() {
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(FLAME_PIN);

  Serial.print("Flame Sensor Value: ");
  Serial.println(sensorValue);

  // Fire detected condition
  if (sensorValue < threshold) {
    digitalWrite(BUZZER, HIGH);  // Buzzer ON
  } else {
    digitalWrite(BUZZER, LOW);   // Buzzer OFF
  }

  delay(200);
}
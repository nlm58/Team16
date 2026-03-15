#include <Arduino.h>
int relayPin = 1;


void setup() {
  pinMode(relayPin, OUTPUT);
}

void loop() {
  digitalWrite(relayPin, HIGH);
  delay(30000);
  digitalWrite(relayPin, LOW);
  delay(5000);
}

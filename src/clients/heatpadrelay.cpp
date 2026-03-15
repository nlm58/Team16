#include <Arduino.h>
int relayPin = 1;
// Initialize Pin on ESP32

void setup() {
  pinMode(relayPin, OUTPUT);
  // Set Pin as output
}

void loop() {
  digitalWrite(relayPin, HIGH);
  delay(30000);
  digitalWrite(relayPin, LOW);
  delay(5000);
  //Write high to pin for 30s and low for 5s
}

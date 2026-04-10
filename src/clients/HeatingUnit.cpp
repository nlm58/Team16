#include <Arduino.h>
#include "DHT_Async.h"
// Select sensor type
#define DHT_SENSOR_TYPE DHT_TYPE_11

// Pins used for Prototype 2
int DHT_SENSOR_PIN = 13;
int heatPin = 1;
int fanPin = 2;
// Create sensor object
DHT_Async tempSensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);
/*
 Initialize serial communication and sensor
*/
void setup() {
    pinMode(heatPin, OUTPUT);
    pinMode(fanPin, OUTPUT);
    Serial.begin(9600);
}
/*
 Main program loop, Reads temperature and determines system response
*/
void loop() {
    float temp, hum;

    tempSensor.measure(&temp, &hum);

    Serial.println("Temp: " + String(temp));

    digitalWrite(fanPin, HIGH);


    // Heat Sensor
    if (temp > 27.0) {
        Serial.println("Heat OFF");
        digitalWrite(heatPin, LOW);
        delay(30000);
    } else {
        Serial.println("Heat ON");
        digitalWrite(heatPin, HIGH);
        delay(30000);
    }

    Serial.println("--------------------");

    delay(1000);
}
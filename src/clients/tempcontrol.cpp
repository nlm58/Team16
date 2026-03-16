#include <Arduino.h>
#include "DHT_Async.h"

// Select sensor type
#define DHT_SENSOR_TYPE DHT_TYPE_11

// Pin used for Prototype 2
static const int DHT_SENSOR_PIN = 13;

// Create sensor object
DHT_Async tempSensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);
/*
 Initialize serial communication and sensor
*/
void setup() {
    Serial.begin(9600);
}
/*
 Main program loop, Reads temperature and determines system response
*/
void loop() {
    float temp, hum;

    tempSensor.measure(&temp, &hum);

    Serial.println("Temp: " + String(temp));
    Serial.println("Humidity: " + String(hum));

    // Prototype 2 control logic
    if (temp > 27.0) {
        Serial.println("Fan ON");
    } else {
        Serial.println("Fan OFF");
    }

    Serial.println("--------------------");

    delay(1000);
}
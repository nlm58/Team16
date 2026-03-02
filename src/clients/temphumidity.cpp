#include <Arduino.h>
#include "DHT_Async.h"

/* Uncomment according to your sensortype. */
#define DHT_SENSOR_TYPE DHT_TYPE_11
// #define DHT_SENSOR_TYPE DHT_TYPE_21
// #define DHT_SENSOR_TYPE DHT_TYPE_22

static const int DHT_SENSOR_PIN = 27;
DHT_Async tempSensor = DHT_Async(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

/*
 * Initialize the serial port.
 */
void setup()
{
  Serial.begin(9600);
}

/*
 * Main program loop.
 */
void loop()
{
  float temp, hum;

  tempSensor.measure(&temp, &hum);

  Serial.println("Temp: " + String(temp));
  Serial.println("Humidity: " + String(hum));
  delay(100);
}
#include <Arduino.h>
#include "DHT_Async.h"

/* Uncomment according to your sensortype. */
#define DHT_SENSOR_TYPE DHT_TYPE_11
// #define DHT_SENSOR_TYPE DHT_TYPE_21
// #define DHT_SENSOR_TYPE DHT_TYPE_22

static const int DHT_SENSOR_PIN = 27;
static const int FAN_PIN = 36; // A4 = 36
static const int DHT_BASIN_PIN = 13;

DHT_Async tempSensor = DHT_Async(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

DHT_Async basinTempSensor = DHT_Async(DHT_BASIN_PIN, DHT_SENSOR_TYPE);

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
    // Temp/hum for box
    float temp, hum;

    tempSensor.measure(&temp, &hum);

    Serial.println("Temp: " + String(temp));
    Serial.println("Humidity: " + String(hum));
    delay(100);

    // Fan control
    if (temp < 20)
    {
        analogWrite(FAN_PIN, HIGH);
    }
    else if (analogRead(FAN_PIN) == HIGH)
    {
        analogWrite(FAN_PIN, LOW);
    }
}
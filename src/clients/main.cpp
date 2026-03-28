#include <Arduino.h>
#include "DHT_Async.h"

/* Uncomment according to your sensortype. */
#define DHT_SENSOR_TYPE DHT_TYPE_11
// #define DHT_SENSOR_TYPE DHT_TYPE_21
// #define DHT_SENSOR_TYPE DHT_TYPE_22

const int MOTOR_B_1A = 34;
const int MOTOR_B_1B = 39;

static const int DHT_SENSOR_PIN = 27;
// A4 = 36
static const int DHT_BASIN_PIN = 13;

DHT_Async tempSensor = DHT_Async(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

DHT_Async basinTempSensor = DHT_Async(DHT_BASIN_PIN, DHT_SENSOR_TYPE);

/*
 * Initialize the serial port.
 */
void setup()
{
    Serial.begin(9600);

    pinMode(MOTOR_B_1A, OUTPUT);
    pinMode(MOTOR_B_1B, OUTPUT);

    digitalWrite(MOTOR_B_1A, 255);
    digitalWrite(MOTOR_B_1B, 0);
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
    if (temp < 30)
    {
        digitalWrite(MOTOR_B_1A, 255);
        digitalWrite(MOTOR_B_1B, 0);
    }
}
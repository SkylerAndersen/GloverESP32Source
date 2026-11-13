#include "sensors.h"
#include "communication.h"

#define BAUDRATE 115200

// For each id in this list, the corresponding pin will
// read the voltage output from the sensor on a finger.
// These pin ids are stored in order of fingers, left to right.
uint32_t pinIDsLeftToRight[5];

// Voltages, once read out, must also be stored
float voltagesLeftToRight[5];

// If the fingers left to right are bent, a value of 1 will be stored. Else, 0
uint32_t sensorData[5];

// logs sensor data
void debug() {
	Serial.print("Sensor data: [");
	Serial.print(sensorData[0]);
	for (std::size_t i{1}; i < 5; ++i) {
		Serial.print(", ");
		Serial.print(sensorData[i]);
	}
	Serial.println("]");
}

// on boot, sets up serial output and calls inits
void setup() {
	Serial.begin(BAUDRATE);
	sensors_init(pinIDsLeftToRight, voltagesLeftToRight, sensorData);
	communication_init();
}

// on loop, calls the main functions, sensors then communication
// runs debug log
void loop() {
	sensors_main(pinIDsLeftToRight, voltagesLeftToRight, sensorData);
	communication_main(sensorData);
	debug();
}

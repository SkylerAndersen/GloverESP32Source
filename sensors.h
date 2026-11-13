#ifndef SENSORS_H
#define SENSORS_H
#include <Arduino.h>

// Note to teamates: Your function headers go here
void sensors_init(uint32_t* pinIDsLeftToRight, float* voltagesLeftToRight,
			uint32_t* sensorData);
void sensors_main(uint32_t* pinIDsLeftToRight, float* voltagesLeftToRight,
			uint32_t* sensorData);

#endif

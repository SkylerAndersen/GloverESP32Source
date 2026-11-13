#include "communication.h"

/*
	Run in setup on esp32 boot.
	Run after sensors init, so data
	should already be initialized.
*/
void communication_init () {

}

/*
	Run in loop and repeated at tick.
	Run after sensors loop, so data
	should already be initialized.
*/
void communication_main (uint32_t* sensorData) {

}

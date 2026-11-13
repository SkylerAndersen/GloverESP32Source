#include "sensors.h"

void sensors_init (uint32_t* pinIDsLeftToRight, float* voltagesLeftToRight,
			uint32_t* sensorData) {
	/*
		The following pins are chosen because they are on
		ADC1, so they have no Wi-Fi interactions. They also
		do not have conflicts with strapping pins or other
		boot associated pins, so passive draw from circuits
		during reset is not as much of an issue. All of
		these have RTC_GPIO, GPIO, TOUCH (unused) and the
		ADC_CH channel. They also do not collide with the
		BUILTIN_LED channel. Information on ESP32-S3-WROOM-1U
		was gathered from:
		(https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32s3/esp-dev-kits-en-master-esp32s3.pdf)
		Mostly pages 10 and 11, and also from:
		(https://documentation.espressif.com/esp32-s3_datasheet_en.pdf)
		page 32, and pages 20-22.
		Information about our third party manufacturer's led pin
		was aquired from direct testing of the board. RBG_BUILTIN
		maps to 97, which is virtual. Pin count is 49, so the physical
		pin that has a datastream sent out over is 97-49 = pin 48.
	*/
	pinIDsLeftToRight[0] = 2;
	pinIDsLeftToRight[1] = 4;
	pinIDsLeftToRight[2] = 5;
	pinIDsLeftToRight[3] = 6;
	pinIDsLeftToRight[4] = 7;

	// initialize other arrays with default data
	for (std::size_t i{0}; i < 5; ++i) {
		voltagesLeftToRight[i] = 0.0f;
		sensorData[i] = 0;
	}
}

void sensors_main (uint32_t* pinIDsLeftToRight, float* voltagesLeftToRight,
			uint32_t* sensorData) {
	
}

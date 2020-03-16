#include <stdio.h>

#include "ip_connection.h"
#include "tng_do8.h"

#define HOST "localhost"
#define PORT 4223
#define UID "XYZ" // Change XYZ to the UID of your TNG DO8

int main(void) {
	// Create IP connection
	IPConnection ipcon;
	ipcon_create(&ipcon);

	// Create device object
	DO8 do8;
	do8_create(&do8, UID, &ipcon);

	// Connect to brickd
	if(ipcon_connect(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not connect\n");
		return 1;
	}
	// Don't use device before ipcon is connected

	bool value[8] = {true, false, true, false, true, false, true, false};
	do8_set_value(&do8, 0, value);

	printf("Press key to exit\n");
	getchar();
	do8_destroy(&do8);
	ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally
	return 0;
}

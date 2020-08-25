package main

import (
	"fmt"
	"github.com/Tinkerforge/go-api-bindings/ipconnection"
	"github.com/Tinkerforge/go-api-bindings/tng_do8"
)

const ADDR string = "localhost:4223"
const UID string = "XYZ" // Change XYZ to the UID of your TNG DO8.

func main() {
	ipcon := ipconnection.New()
	defer ipcon.Close()
	do8, _ := tng_do8.New(UID, &ipcon) // Create device object.

	ipcon.Connect(ADDR) // Connect to brickd.
	defer ipcon.Disconnect()
	// Don't use device before ipcon is connected.

	do8.SetValues(0, [8]bool{true, false, true, false, true, false, true, false})

	fmt.Print("Press enter to exit.")
	fmt.Scanln()
}

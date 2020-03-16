#!/usr/bin/env python
# -*- coding: utf-8 -*-

HOST = "localhost"
PORT = 4223
UID = "XYZ" # Change XYZ to the UID of your TNG DO8

from tinkerforge.ip_connection import IPConnection
from tinkerforge.tng_do8 import TNGDO8

if __name__ == "__main__":
    ipcon = IPConnection() # Create IP connection
    do8 = TNGDO8(UID, ipcon) # Create device object

    ipcon.connect(HOST, PORT) # Connect to brickd
    # Don't use device before ipcon is connected

    do8.set_value(0, [True, False, True, False, True, False, True, False])

    input("Press key to exit\n") # Use raw_input() in Python 2
    ipcon.disconnect()

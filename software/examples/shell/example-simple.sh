#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your TNG DO8

tinkerforge call do8-tng $uid set-values 0 true,false,true,false,true,false,true,false

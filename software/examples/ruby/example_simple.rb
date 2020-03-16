#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/tng_do8'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = 'XYZ' # Change XYZ to the UID of your TNG DO8

ipcon = IPConnection.new # Create IP connection
do8 = TNGDO8.new UID, ipcon # Create device object

ipcon.connect HOST, PORT # Connect to brickd
# Don't use device before ipcon is connected

do8.set_value 0, [true, false, true, false, true, false, true, false]

puts 'Press key to exit'
$stdin.gets
ipcon.disconnect

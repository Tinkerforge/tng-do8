#!/usr/bin/perl

use strict;
use Tinkerforge::IPConnection;
use Tinkerforge::TNGDO8;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XYZ'; # Change XYZ to the UID of your TNG DO8

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $do8 = Tinkerforge::TNGDO8->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

$do8->set_value(0, [1, 0, 1, 0, 1, 0, 1, 0]);

print "Press key to exit\n";
<STDIN>;
$ipcon->disconnect();

<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/TNGDO8.php');

use Tinkerforge\IPConnection;
use Tinkerforge\TNGDO8;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'XYZ'; // Change XYZ to the UID of your TNG DO8

$ipcon = new IPConnection(); // Create IP connection
$do8 = new TNGDO8(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

$do8->setValue(array(TRUE, FALSE, TRUE, FALSE, TRUE, FALSE, TRUE, FALSE));

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->disconnect();

?>

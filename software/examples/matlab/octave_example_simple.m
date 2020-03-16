function octave_example_simple()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "XYZ"; % Change XYZ to the UID of your TNG DO8

    ipcon = javaObject("com.tinkerforge.IPConnection"); % Create IP connection
    do8 = javaObject("com.tinkerforge.TNGDO8", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    do8.setValue(0, [true false true false true false true false]);

    input("Press key to exit\n", "s");
    ipcon.disconnect();
end

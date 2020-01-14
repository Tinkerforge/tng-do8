function matlab_example_simple()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.TNGDO8;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'XYZ'; % Change XYZ to the UID of your TNG DO8

    ipcon = IPConnection(); % Create IP connection
    do8 = handle(TNGDO8(UID, ipcon), 'CallbackProperties'); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    do8.setValue([true false true false true false true false]);

    input('Press key to exit\n', 's');
    ipcon.disconnect();
end

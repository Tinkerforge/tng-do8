import com.tinkerforge.IPConnection;
import com.tinkerforge.TNGDO8;

public class ExampleSimple {
	private static final String HOST = "localhost";
	private static final int PORT = 4223;

	// Change XYZ to the UID of your TNG DO8
	private static final String UID = "XYZ";

	// Note: To make the example code cleaner we do not handle exceptions. Exceptions
	//       you might normally want to catch are described in the documentation
	public static void main(String args[]) throws Exception {
		IPConnection ipcon = new IPConnection(); // Create IP connection
		TNGDO8 do8 = new TNGDO8(UID, ipcon); // Create device object

		ipcon.connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		do8.setValues(0, new boolean[]{true, false, true, false, true, false, true, false});

		System.out.println("Press key to exit"); System.in.read();
		ipcon.disconnect();
	}
}

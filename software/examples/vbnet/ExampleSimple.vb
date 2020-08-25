Imports System
Imports Tinkerforge

Module ExampleSimple
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "XYZ" ' Change XYZ to the UID of your TNG DO8

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim do8 As New TNGDO8(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        do8.SetValues(0, _
                      new Boolean(){True, False, True, False, True, False, True, False})

        Console.WriteLine("Press key to exit")
        Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module

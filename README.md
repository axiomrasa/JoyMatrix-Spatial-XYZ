 
 ------------------------------------------------------------
           S P A T I A L  X Y Z  M I D I  B R I D G E
 ------------------------------------------------------------
 BUILD BY  : axiomrasa
 VERSION   : 1.0.0
 LICENSE   : MIT

 [ 01 // OVERVIEW ]

 JoyMatrix is a tactile XYZ spatial controller. It bridges 
 physical joystick movements to a 3-axis MIDI data stream, 
 designed for immersive audio mixing and Dolby Atmos panning.

 [ 02 // HARDWARE SPECS ]

 + MCU      : ARDUINO UNO R3
 + INPUT    : 2-AXIS ANALOG JOYSTICK + PUSH SWITCH
 + FEEDBACK : 8x8 LED MATRIX (MAX7219)
 + COMMS    : SERIAL-OVER-USB (115200 BAUD)

 [ 03 // MIDI MAP ]

 + CC 20 : X-AXIS (AZIMUTH / L-R)
 + CC 21 : Y-AXIS (DISTANCE / F-B)
 + CC 22 : Z-AXIS (ELEVATION / HEIGHT) // ACTIVE ON BUTTON HOLD

 [ 04 // WIRING ]

 + JOYSTICK   : VRX -> A0 | VRY -> A1 | SW -> D2
 + LED MATRIX : DIN -> D12 | CS -> D10 | CLK -> D11
 + POWER      : 5V & GND

 [ 05 // DEPLOYMENT ]

 1. Flash 'JoyMatrix.ino' to Arduino via IDE.
 2. Enable macOS 'IAC Driver' (Bus 1) in MIDI Setup.
 3. Install requirements:
    $ pip install pyserial mido python-rtmidi
 4. Run the bridge:
    $ python3 bridge.py

 ------------------------------------------------------------
 EOF // axiomrasa
 ------------------------------------------------------------

import serial
import serial.tools.list_ports
import mido

MIDI_OUT = 'IAC Driver Bus 1'
BAUD = 115200

def get_port():
    ports = serial.tools.list_ports.comports()
    for p in ports:
        if 'usb' in p.device.lower(): return p.device
    return None

def main():
    port = get_port()
    if not port: return print("Arduino not found.")
    
    history = {20: 0, 21: 0, 22: 0}
    try:
        ser = serial.Serial(port, BAUD, timeout=0.01)
        out = mido.open_output(MIDI_OUT)
        print(f"Active: {port}")

        while True:
            if ser.in_waiting >= 3:
                data = ser.read(3)
                if data[0] >= 128:
                    msg = mido.Message.from_bytes(data)
                    if abs(msg.value - history.get(msg.control, 0)) >= 1:
                        out.send(msg)
                        history[msg.control] = msg.value
                        print(f"CC{msg.control}: {msg.value}")
                else: ser.reset_input_buffer()
    except: print("Error or Disconnect.")

if __name__ == "__main__":
    main()
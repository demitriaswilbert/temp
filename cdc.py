import serial
import time
import threading
import sys

import serial.tools.list_ports


def read_thread_f(port: serial.Serial, stop_event: threading.Event):
    while not stop_event.is_set():
        text = port.read_all()
        if text:
            text = text.decode('utf-8')
            print(text)
        time.sleep(0.1)


def serial_ports():
    ports = serial.tools.list_ports.comports()
    for port, desc, hwid in sorted(ports):
            print("{}: {} [{}]".format(port, desc, hwid))

def send_string_to_serial(string: str):

    cur_time = time.time()
    # transfer block size
    block_size = 128
    string_len = len(string)

    for i in range(0, len(string), block_size):

        # log sent size every second
        if round(time.time()) > round(cur_time):
            cur_time += 1
            print(i)

        # send block
        start, end = i, i + block_size
        end = end if end < string_len else string_len
        ser.write(string[start : end])

if __name__ == '__main__':
    # Open the serial port
    serial_ports()
    ser = 0
    while True:
        try:
            ser_port = input("which serial port?: ")
            ser = serial.Serial(ser_port, 9600)  # replace 'COM1' with your actual serial port
            break
        except Exception as e:
            print(e)

    while True:
        # open read thread
        stop_event = threading.Event()
        read_thread = threading.Thread(target=read_thread_f, args=(ser, stop_event), daemon=True)
        read_thread.start()
        time.sleep(0.1)
        input_filepath = ""
        while True:
            input_filepath = input("Press Enter to continue / enter a file path...\n")
            if input_filepath.startswith("_CDC "):
                time.sleep(0.2)
                send_string_to_serial(b'\010' + input_filepath[5:].encode('utf-8') + b'\033')
            elif input_filepath != '': break

        stop_event.set()
        read_thread.join()

        filename = "file1.txt"
        if len(sys.argv) == 2:
            filename = sys.argv[1]
        elif input_filepath == "quit": 
            break
        elif len(input_filepath):
            filename = input_filepath

        # send clear code
        clearcode = b'\010'
        ser.write(clearcode)

        time.sleep(0.1)  # Adjust the sleep duration as needed
        print(ser.read_all())

        try:
            with open(filename, "rb") as f:
                # read file
                a = f.read()

                # file size
                print(f'Sending {len(a)} bytes')
                
                # start timer
                start_time = time.time()
                
                # send string to serial port
                send_string_to_serial(a)

                # print time elapsed & average data rate
                start_time = time.time() - start_time
                print()
                print(f"Took {start_time} s, average: {len(a)/start_time/1000 if start_time > 0 else len(a)} kB/s")

            time.sleep(0.1)
            # wait until serial in clears
            while ser.read_all():
                time.sleep(0.1)

            # send Esc key to save
            do_save = input("Save (Y/N): ").lower()
            clearcode = b'\033KB save\033' if do_save == 'y' else b'\033'

            time.sleep(0.3)
            ser.write(clearcode)
        except Exception as e:
            print(e)
    # Close the serial port
    ser.close()

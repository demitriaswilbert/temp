import serial
import time
import threading

# Open the serial port
ser = serial.Serial('COM16', 9600)  # replace 'COM1' with your actual serial port

# def read_thread():
#     while 1:
#         print(ser.read().decode('utf-8'), end='')

# def write_thread():
#     while 1:
#         a = input().encode('utf-8')
#         ser.write(a)


# # Create two threads
# thread1 = threading.Thread(target=read_thread)
# thread2 = threading.Thread(target=write_thread)

# # Start the threads
# thread1.start()
# thread2.start()

# thread1.join()
# thread2.join()
time.sleep(2)

clearcode = b'\010'
ser.write(clearcode)

time.sleep(0.1)  # Adjust the sleep duration as needed
print(ser.read_all())

with open("file1.txt", "rb") as f:
    a = f.read().decode("utf-8")
    print(f'Sending {len(a)} bytes')
    start_time = time.time()
    cur_time = start_time
    for i in range(len(a)):
        if round(time.time()) > round(cur_time):
            cur_time += 1
            print(i)
        ser.write(a[i].encode('utf-8'))
    start_time = time.time() - start_time
    print()
    print(f"Took {start_time} s")

clearcode = b'\033'
ser.write(clearcode)

time.sleep(0.1)  # Adjust the sleep duration as needed
print(ser.read_all())


# Close the serial port
ser.close()

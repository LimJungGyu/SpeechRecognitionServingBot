import serial
import time

py_serial = serial.Serial(
    port='/dev/ttyACM1',
    baudrate=9600
)
while True:
    commend = input('table number:')
    
    py_serial.write(commend.encode())
    
    time.sleep(0.1)
    a = 1
    while a==1:
        if py_serial.readable():
            response = py_serial.readline()
            text = response[:len(response)-1].decode()
            text = text.strip()
            print(text)
            if  text=="arrived table":
                print("order")
            elif text=="home":
                a=2


import serial
import time
import speech_recognition as sr
import pyaudio
import wave
import pygame
import time
import socket

def botvoice(botvoice):
    pygame.mixer.init()
    bang = pygame.mixer.Sound(botvoice)

    bang.play()
    time.sleep(2.8)


def orderbot(RECORD_SECONDS,ANSWERTYPE):
    CHUNK = 1024
    FORMAT = pyaudio.paInt16
    CHANNELS = 2
    RATE = 44100
    WAVE_OUTPUT_FILENAME = ANSWERTYPE+".wav"

    p = pyaudio.PyAudio()

    stream = p.open(format=FORMAT,
                    channels=CHANNELS,
                    rate=RATE,
                    input=True,
                    frames_per_buffer=CHUNK)

    print("* recording")

    frames = []

    for i in range(0, int(RATE / CHUNK * RECORD_SECONDS)):
        data = stream.read(CHUNK)
        frames.append(data)

    print("* done recording")

    stream.stop_stream()
    stream.close()
    p.terminate()

    wf = wave.open(WAVE_OUTPUT_FILENAME, 'wb')
    wf.setnchannels(CHANNELS)
    wf.setsampwidth(p.get_sample_size(FORMAT))
    wf.setframerate(RATE)
    wf.writeframes(b''.join(frames))
    wf.close()

    try:
        r = sr.Recognizer()
        korean_audio = sr.AudioFile(ANSWERTYPE+".wav")
        with korean_audio as source:
            audio = r.record(source)
        CustomerSay=r.recognize_google(audio_data=audio,language='ko-KR')
        print(CustomerSay)
        return CustomerSay
    except:
        print("no sound")
        return " "

py_serial = serial.Serial(
    port='/dev/ttyACM0',
    baudrate=9600
)
host = '192.168.0.16'
port = 9997 
server_sock = socket.socket(socket.AF_INET , socket.SOCK_STREAM)
server_sock.setsockopt(socket.SOL_SOCKET , socket.SO_REUSEADDR , 1)
server_sock.bind((host , port))
server_sock.listen()
print("waiting...")
while True:
    client_sock , addr = server_sock.accept()
    if client_sock:
        print('Connection Complete!!!' , addr)
        in_data = client_sock.recv(1024).decode("utf-8")
        print('rcv : ' , in_data)
        b=1
    while b==1:
        commend = in_data
        
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
                    botvoice("hi.wav")
                    time.sleep(1)
                    yesno=orderbot(5,"yesno")
                    time.sleep(1)
                    if  "아니요" in yesno or "괜찮아요" in yesno or "아니" in yesno or "없어요" in yesno or  "없어" in yesno:                             
                        botvoice("bye.wav")
                        time.sleep(1)
                        in_data="no order".encode('utf-8')
                        py_serial.write("e".encode())
                    else:
                        botvoice("orderB.wav")
                        time.sleep(0.5)
                        order=orderbot(10,"order")
                        # print("") 여기에다 안드로이드로 보내는 코드 쓰기
                        in_data=order.encode('utf-8')
                        botvoice("bye.wav")
                        py_serial.write("e".encode())
                        time.sleep(1)
                elif text=="servingend":
                    py_serial.write(commend.encode())
                elif text=="home":
                    a=2
                    b=2

              
    client_sock.sendall(in_data)
    client_sock.close()
server_sock.close()



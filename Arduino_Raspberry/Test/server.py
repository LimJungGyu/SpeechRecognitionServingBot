import socket
import time

host = "192.168.0.7"
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
        data = client_sock.recv(1024).decode("utf-8")
        print('rcv : ' ,data)
        
    client_sock.sendall(data.encode())

client_sock.close()
server_sock.close()
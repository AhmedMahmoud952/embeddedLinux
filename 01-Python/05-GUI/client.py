import socket

host = "" #add your ip
port = 5000
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.connect((host, port))
while True:
    massage = input("enter a massage: ")    
    server.send(massage.encode())
    print(server.recv(1024).decode())




import socket
import threading
import time

host = "192.168.1.4"
port = 5000
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((host, port))
server.listen(5)

def find_clients():
    while True:
        connection_socket, address = server.accept()
        print(f"connected to: {address}")
        threading.Thread(target=recieve_massages,args=(connection_socket,)).start()


def recieve_massages(connection_socket):
    while True:
        massage = connection_socket.recv(1024).decode()
        print(f"massage: {massage}")
        connection_socket.send(("got the massage thank you.").encode())


threading.Thread(target=find_clients).start()

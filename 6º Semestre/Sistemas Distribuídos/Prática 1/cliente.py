from pickletools import long1
import socket
import random

HOST = 'localhost'  

PORT = 5000           

tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

destino = (HOST, PORT)

tcp.connect(destino)

mensagem = []
valof = 0
contaux = 0

while contaux < 101:
   cont = 0
   while cont < 10000:
      mensagem.append(random.randint(0, 1000))
      cont += 1
   contaux += 1
   tcp.send(str(mensagem).encode())
   if(contaux <100):
      valof += int(tcp.recv(4096).decode())
   mensagem = []


print("A soma é: ", valof)

tcp.close()

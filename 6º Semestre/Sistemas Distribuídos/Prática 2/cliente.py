from pickle import TRUE
from pickletools import long1
import socket
import random

HOST = 'localhost'  

PORT = 5000           

tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

destino = (HOST, PORT)

tcp.connect(destino)

msg = ""

while msg != "^x":
   tcp.settimeout(1)
   try:
      ms = tcp.recv(1024).decode()
      print(str(ms))
   except:
      tcp.settimeout(1)
      try:
         msg = input("")
         tcp.send(msg.encode())
      except:
         continue

tcp.close()

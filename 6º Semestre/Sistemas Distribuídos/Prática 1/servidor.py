from concurrent.futures import thread
from pickle import FALSE, TRUE
import socket
import time
import _thread

HOST = 'localhost'     

PORT = 5000 

tempo_total = 0

flags = []

def contTempo(tempo_inicial):
    numThread = 0
    for flag in flags:
        if(flag == 'FALSE'):
            numThread += 1
    if(numThread == len(flags)):
        print(time.time() -  tempo_inicial)


def conectado(con, cliente, tempo_inicial):
    global flags
    print('\nCliente conectado:', cliente)

    cont = 0
    while cont< 100 :

        msg = con.recv(17179869184).decode()

        val = 0

        for num in eval(msg):
            val = val+num
            
        print('A soma é :', val)
        con.send(str(val).encode())
        cont += 1

        
    print('\nFinalizando conexao do cliente', cliente)
    con.close()
    flags.append('FALSE')
    contTempo(tempo_inicial)
    _thread.exit()

tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

orig = (HOST, PORT)

tcp.bind(orig)

tcp.listen(1)

print('\nServidor TCP concorrente iniciado no IP', HOST, 'na porta', PORT)
cont = 0
while True:
    tempo_inicial = time.time()  
    con, cliente = tcp.accept()

    print('\nNova thread iniciada para essa conexão')

    _thread.start_new_thread(conectado, tuple([con, cliente, tempo_inicial]))
    print('passou')
    




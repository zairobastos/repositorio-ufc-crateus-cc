from concurrent.futures import thread
import socket
import _thread

HOST = 'localhost'     

PORT = 5000 


flags = []


def conectado(con, cliente):
    global flags
    flags.append(con)
    print('\nCliente conectado:', cliente)

    laco = True
    while laco == True :

        msg = con.recv(1024).decode()
        print(msg)
        for a in flags:
            a.send(msg.encode())


        
    print('\nFinalizando conexao do cliente', cliente)
    con.close()
    _thread.exit()

tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

orig = (HOST, PORT)

tcp.bind(orig)

tcp.listen(1)

print('\nServidor TCP concorrente iniciado no IP', HOST, 'na porta', PORT)

while True:
    con, cliente = tcp.accept()

    print('\nNova thread iniciada para essa conexão')

    _thread.start_new_thread(conectado, tuple([con, cliente]))
    




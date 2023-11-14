from Class import Tabuleiro
import psutil
import os
import time

tempo_gasto = time.time()
        
inicial = ['1','2','3','4','13','6','8','12','5','9','0','7','14','11','10','15']
final = ['1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','0']

inicialEstado = Tabuleiro(inicial)
aceitacaoEstado = Tabuleiro(final)

def guloso(inicialEstado, aceitacaoEstado, comparador):
    total_nos = 1
    estado = inicialEstado
    cont = 0

    while estado != aceitacaoEstado:

        cont += 1

        filhos = estado.moves()
        estado = filhos.pop()
        for x in filhos:
            total_nos += 1
            if comparador(x, aceitacaoEstado) < comparador(estado, aceitacaoEstado):
                estado = x
        if(cont > 200):
            break

    return estado.backtrack, total_nos

def manhattan(inicialEstado, aceitacaoEstado):
    inicial = inicialEstado.estado
    aceitacao = aceitacaoEstado.estado
    profun = inicialEstado.profundidade
    soma = 0
    for i in range(16):
        if aceitacao[i] == '0':
            continue
        x1, y1 = (int(i / 4), i % 4)
        for j in range(16):
            if aceitacao[i] == inicial[j]:
                x2, y2 = (int(j / 4), j % 4)
                soma += abs(x1 - x2) + abs(y1 - y2)
                break
    return soma + profun

process = psutil.Process(os.getpid())
memoria_sis = process.memory_info().rss
memoria = memoria_sis / 1000000
print('Gasto de memória: ',memoria, ' MB')
comp = manhattan
moves, nodes = guloso(inicialEstado, aceitacaoEstado, comp)
print(nodes, "nos usados.")
if moves:
    print('Tempo gasto: ',time.time() - tempo_gasto, 'S')
    print("Caminho seguido:")
    print(" -> ".join(moves))
else:
    print("Solução não encontrada.")
print(inicialEstado)
print(aceitacaoEstado)

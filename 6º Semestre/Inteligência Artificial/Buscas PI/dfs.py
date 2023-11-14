import os
import time
from tkinter import E
import psutil
from copy import deepcopy

valor_entrada = [1, 2, 3, 4, 5, 6, 8, 12, 13, 9, 0, 7, 14, 11, 10, 15]

tempo_gasto = time.time()

memory_dfs = 0

TAMANHO_MAXIMO = 4
ESTADOFINAL = "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 0"
ESTADOFINAL_EM_LISTA = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "0"]

class Tabuleiro(object):

    # valor_atual = [[]]
    # formato_string = []
    __slots__ = ['formato_string', 'valor_atual']

    def __init__(self, tabuleiro_string):
        self.formato_string = tabuleiro_string
        self.valor_atual = transforma_em_matriz(self.formato_string)

    def get_Tabuleiro(self):
        return self.valor_atual

    def print_Tabuleiro(self):
        for row in self.valor_atual:
            print(row)

def posicao_zero(tabuleiro):
    for r in range(0, TAMANHO_MAXIMO):
        for c in range(0, TAMANHO_MAXIMO):
            if tabuleiro[r][c] == 0:
                return r, c


def transforma_em_matriz(bas):
    tabuleiro_string = list(map(int, bas))
    w, h = TAMANHO_MAXIMO, TAMANHO_MAXIMO
    matrix = [[0 for x in range(w)] for y in range(h)]
    i = 0

    for row in range(0, w):
        for col in range(0, h):
            matrix[row][col] = tabuleiro_string[i]
            i += 1
    return matrix


def transforma_em_string(matrix):
    tmp = []

    for r in range(0, TAMANHO_MAXIMO):
        for c in range(0, TAMANHO_MAXIMO):
            tmp.append(str(matrix[r][c]))
    return tmp

def mover_tabuleiro(direction, node, visitado):

    no_em_lista = node[0]
    parent_board = node[1]
    posicao = node[2]
    linha = posicao[0]
    coluna = posicao[1]
    tabuleiro_atual = deepcopy(parent_board)
    passed = False

    if direction == "CIMA" and linha - 1 >= 0:
        passed = True
        tmp = tabuleiro_atual[linha - 1][coluna]
        tabuleiro_atual[linha - 1][coluna] = tabuleiro_atual[linha][coluna]
        tabuleiro_atual[linha][coluna] = tmp
        no_em_lista = transforma_em_string(tabuleiro_atual)

    elif direction == "BAIXO" and linha + 1 < TAMANHO_MAXIMO:
        passed = True
        tmp = tabuleiro_atual[linha + 1][coluna]
        tabuleiro_atual[linha + 1][coluna] = tabuleiro_atual[linha][coluna]
        tabuleiro_atual[linha][coluna] = tmp
        no_em_lista = transforma_em_string(tabuleiro_atual)

    elif direction == "ESQUERDA" and coluna - 1 >= 0:
        passed = True
        tmp = tabuleiro_atual[linha][coluna - 1]
        tabuleiro_atual[linha][coluna - 1] = tabuleiro_atual[linha][coluna]
        tabuleiro_atual[linha][coluna] = tmp
        no_em_lista = transforma_em_string(tabuleiro_atual)

    elif direction == "DIREITA" and coluna + 1 < TAMANHO_MAXIMO:
        passed = True
        tmp = tabuleiro_atual[linha][coluna + 1]
        tabuleiro_atual[linha][coluna + 1] = tabuleiro_atual[linha][coluna]
        tabuleiro_atual[linha][coluna] = tmp
        no_em_lista = transforma_em_string(tabuleiro_atual)

    del tabuleiro_atual[:]
    del tabuleiro_atual

    # If it passed through one of the if-elif conditions, check to see if the board has been visitado.
    # If it has not passed through one of the if-elif conditions, then return NULL.
    # If it has not been visitado, return the board as string (to use in search), else return NULL
    if passed:
        result = checa_visitados(Tabuleiro(no_em_lista), ' '.join(str(num) for row in parent_board for num in row), visitado)
    else:
        return 'NULL'

    if result:
        return no_em_lista
    else:
        return 'NULL'


def checa_visitados(b, parent, visitado):

    child = ' '.join(str(e) for e in b.formato_string)
    if child not in visitado.keys():
        visitado[child] = parent
        return True
    return False


def recebe_caminho(board, visitado):

    if board == 'NULL':
        return
    else:
        recebe_caminho(visitado[board], visitado)
        b = Tabuleiro(board.split(' '))
        b.print_Tabuleiro()
        print('')


def dfs(tabuleiro):

    visitado = {}
    profundidade = 0

    while True:

        b = Tabuleiro(tabuleiro)
        no_em_lista = b.formato_string
        visitado[' '.join(str(e) for e in no_em_lista)] = 'NULL'

        if dls(tabuleiro, profundidade, visitado):
            recebe_caminho(ESTADOFINAL, visitado)
            print('Solução encontrada')

            process = psutil.Process(os.getpid())
            memory = process.memory_info().rss
            memoria = memory / 1000000

            print('Tempo de execução: ', time.time() - tempo_gasto, "S")
            print('Gasto de memória: ',memoria, ' MB')
            print('Nos visitados:', len(visitado))
            
            return True

        profundidade += 1
        visitado.clear()

    return False


def dls(no_atual, profundidade, visitado):

    b = Tabuleiro(no_atual)

    no_em_lista = b.formato_string

    if no_em_lista == ESTADOFINAL_EM_LISTA:
        return True

    if profundidade <= 0:
        return False

    tabuleiro_atual = transforma_em_matriz(no_em_lista)

    posicao = posicao_zero(tabuleiro_atual)

    resultado_de_cima = mover_tabuleiro("CIMA", [no_em_lista, tabuleiro_atual, posicao], visitado)
    resultado_de_baixo = mover_tabuleiro("BAIXO", [no_em_lista, tabuleiro_atual, posicao], visitado)
    resultado_da_esquerda = mover_tabuleiro("ESQUERDA", [no_em_lista, tabuleiro_atual, posicao], visitado)
    resultado_da_direita = mover_tabuleiro("DIREITA", [no_em_lista, tabuleiro_atual, posicao], visitado)

    if resultado_de_cima != "NULL":
        if dls(resultado_de_cima, profundidade - 1, visitado):
            return True
    if resultado_de_baixo != "NULL":
        if dls(resultado_de_baixo, profundidade - 1, visitado):
            return True
    if resultado_da_esquerda != 'NULL':
        if dls(resultado_da_esquerda, profundidade - 1, visitado):
            return True
    if resultado_da_direita != 'NULL':
        if dls(resultado_da_direita, profundidade - 1, visitado):
            return True

    return False

dfs(valor_entrada)

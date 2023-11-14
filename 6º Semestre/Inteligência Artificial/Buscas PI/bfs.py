from copy import deepcopy
import psutil
import time
import os

tam = 0
valor_entrada = [1, 2, 3, 4, 13, 6, 8, 12, 5, 9, 0, 7, 14, 11, 10, 15]

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


def para_cima(pai, raiz, no_atual, linha, coluna, fila, visitado):
    if linha - 1 >= 0:

        aux = no_atual[linha - 1][coluna]
        no_atual[linha - 1][coluna] = no_atual[linha][coluna]
        no_atual[linha][coluna] = aux
        matrix_conventida = transforma_em_string(no_atual)

        checar_no(Tabuleiro(matrix_conventida),
                 ' '.join(str(num) for row in raiz for num in row),
                 pai, fila, visitado)


def para_baixo(pai, raiz, no_atual, linha, coluna, fila, visitado):
    if linha + 1 < TAMANHO_MAXIMO:
        aux = no_atual[linha + 1][coluna]
        no_atual[linha + 1][coluna] = no_atual[linha][coluna]
        no_atual[linha][coluna] = aux
        matrix_conventida = transforma_em_string(no_atual)

        checar_no(Tabuleiro(matrix_conventida),
                 ' '.join(str(num) for row in raiz for num in row),
                 pai, fila, visitado)


def para_esquerda(pai, raiz, no_atual, linha, coluna, fila, visitado):
    if coluna - 1 >= 0:

        aux = no_atual[linha][coluna - 1]
        no_atual[linha][coluna - 1] = no_atual[linha][coluna]
        no_atual[linha][coluna] = aux
        matrix_conventida = transforma_em_string(no_atual)

        checar_no(Tabuleiro(matrix_conventida),
                 ' '.join(str(num) for row in raiz for num in row),
                 pai, fila, visitado)


def para_direita(pai, raiz, no_atual, linha, coluna, fila, visitado):
    if coluna + 1 < TAMANHO_MAXIMO:

        aux = no_atual[linha][coluna + 1]
        no_atual[linha][coluna + 1] = no_atual[linha][coluna]
        no_atual[linha][coluna] = aux
        matrix_conventida = transforma_em_string(no_atual)

        checar_no(Tabuleiro(matrix_conventida),
                 ' '.join(str(num) for row in raiz for num in row),
                 pai, fila, visitado)


def checar_no(b, parent, ph, fila, visitado):
    """Função que checa se o nó já foi visitado"""
    h = 0
    filho = ' '.join(str(e) for e in b.formato_string)

    if filho not in visitado.keys():
        fila.append((h, b.formato_string))
        visitado[filho] = [h, h + ph, parent]

def recebe_caminho(tabuleiro, visitado):
    if tabuleiro == 'NULL':
        return 
    else:
        recebe_caminho(visitado[tabuleiro][2], visitado)
        b = Tabuleiro(tabuleiro.split(' '))
        b.print_Tabuleiro()
        print('')

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


def bfs(tabuleiro):
    fila = []
    visitado = {}

    b = Tabuleiro(tabuleiro)
    h = 0

    matrix_conventida = b.formato_string
    visitado[' '.join(str(e) for e in matrix_conventida)] = [h, h, 'NULL']

    fila.append((h, matrix_conventida))

    tempo_gasto = time.time()

    while len(fila) != 0:

        node = fila.pop(0)

        if node[1] == ESTADOFINAL_EM_LISTA:

            recebe_caminho(ESTADOFINAL, visitado)

            print('Solução encontrada')

            process = psutil.Process(os.getpid())
            memoria_sis = process.memory_info().rss
            memoria = memoria_sis / 1000000

            print('Tempo de execução: ', time.time() - tempo_gasto, "S")
            print('Gasto de memória: ',memoria, ' MB')
            print('Nos visitados:', len(visitado))

            visitado.clear()
            return True

        # Resultado do no em matrix
        no_atual = transforma_em_matriz(node[1])

        # Coordenadas do zero
        po = posicao_zero(no_atual)
        linha = po[0]
        coluna = po[1]

        para_cima(node[0], no_atual, deepcopy(no_atual), linha, coluna, fila, visitado)
        para_baixo(node[0], no_atual, deepcopy(no_atual), linha, coluna, fila, visitado)
        para_esquerda(node[0], no_atual, deepcopy(no_atual), linha, coluna, fila, visitado)
        para_direita(node[0], no_atual, deepcopy(no_atual), linha, coluna, fila, visitado)

    return False

bfs(valor_entrada)
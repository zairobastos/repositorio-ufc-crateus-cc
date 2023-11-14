import copy


class Tabuleiro:
    def __init__(self, arg, parent=None, depth=0):
        self.estado = arg
        self._findx()
        self.filhos = []
        self.backtrack = parent
        self.profundidade = depth


    def __hash__(self):
        return hash(''.join(self.estado))

    def __copy__(self):
        return Tabuleiro(self.estado)

    def __str__(self):
        text = """┌──┬──┬──┬──┐
│{}│{}│{}│{}│
├──┼──┼──┼──┤
│{}│{}│{}│{}│
├──┼──┼──┼──┤
│{}│{}│{}│{}│
├──┼──┼──┼──┤
│{}│{}│{}│{}│
└──┴──┴──┴──┘""" \
            .format(self.estado[0].rjust(2, '0'), self.estado[1].rjust(2, '0'), self.estado[2].rjust(2, '0'),
                    self.estado[3].rjust(2, '0'),
                    self.estado[4].rjust(2, '0'), self.estado[5].rjust(2, '0'), self.estado[6].rjust(2, '0'),
                    self.estado[7].rjust(2, '0'),
                    self.estado[8].rjust(2, '0'), self.estado[9].rjust(2, '0'), self.estado[10].rjust(2, '0'),
                    self.estado[11].rjust(2, '0'),
                    self.estado[12].rjust(2, '0'), self.estado[13].rjust(2, '0'), self.estado[14].rjust(2, '0'),
                    self.estado[15].rjust(2, '0')).replace("00", "  ")
        return text

    def __repr__(self):
        return str(self.estado)

    def __eq__(self, other):
        return self.estado == other

    def _findx(self):
        i = 0
        while self.estado[i] != '0':
            i += 1
        self.x, self.y = (int(i / 4), i % 4)

    # Definicao dos movimentos
    def _left(self):
        move = copy.deepcopy(self.estado)
        btrack = copy.deepcopy(self.backtrack)
        if btrack is None:
            btrack = ['Esquerda']
        else:
            btrack.append('Esquerda')
        if self.y != 0:
            move[self.x * 4 + self.y] = move[self.x * 4 + self.y - 1]
            move[self.x * 4 + self.y - 1] = '0'
            tleft = Tabuleiro(move, parent=btrack, depth=self.profundidade + 1)
            self.filhos.append(tleft)

    def _right(self):
        move = copy.deepcopy(self.estado)
        btrack = copy.deepcopy(self.backtrack)
        if btrack is None:
            btrack = ['Direita']
        else:
            btrack.append('Direita')
        if self.y != 3:
            move[self.x * 4 + self.y] = move[self.x * 4 + self.y + 1]
            move[self.x * 4 + self.y + 1] = '0'
            tright = Tabuleiro(move, parent=btrack, depth=self.profundidade + 1)
            self.filhos.append(tright)

    def _up(self):
        move = copy.deepcopy(self.estado)
        btrack = copy.deepcopy(self.backtrack)
        if btrack is None:
            btrack = ['Cima']
        else:
            btrack.append('Cima')
        if self.x != 0:
            move[self.x * 4 + self.y] = move[(self.x - 1) * 4 + self.y]
            move[(self.x - 1) * 4 + self.y] = '0'
            tup = Tabuleiro(move, parent=btrack, depth=self.profundidade + 1)
            self.filhos.append(tup)

    def _down(self):
        move = copy.deepcopy(self.estado)
        btrack = copy.deepcopy(self.backtrack)
        if btrack is None:
            btrack = ['Baixo']
        else:
            btrack.append('Baixo')
        if self.x != 3:
            move[self.x * 4 + self.y] = move[(self.x + 1) * 4 + self.y]
            move[(self.x + 1) * 4 + self.y] = '0'
            tdown = Tabuleiro(move, parent=btrack, depth=self.profundidade + 1)
            self.filhos.append(tdown)

    def moves(self):
        if self.profundidade > 1:
            last = self.backtrack[self.profundidade-1]
        else:
            last = "0"
        if last != "Direita":
            self._left()
        if last != "Esquerda":
            self._right()
        if last != "Baixo":
            self._up()
        if last != "Cima":
            self._down()
        return self.filhos
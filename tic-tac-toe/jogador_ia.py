# -*- coding: utf-8 -*-
from random import randint

from jogador import Jogador
from tabuleiro import Tabuleiro

class JogadorIA(Jogador):
    def __init__(self, tabuleiro : Tabuleiro, tipo : int):
        super().__init__(tabuleiro, tipo)
            

    def getJogada(self) -> (int, int):
        matriz = self.matriz
        DESCONHECIDO = Tabuleiro.DESCONHECIDO
        J0 = Tabuleiro.JOGADOR_0
        JX = Tabuleiro.JOGADOR_X

        # R1: Linhas, colunas e diagonais para ganhar ou bloquear
        for l in range(3):
            soma = sum(matriz[l])
            if soma in [2, 8]:
                for c in range(3):
                    if matriz[l][c] == DESCONHECIDO:
                        return (l, c)

        for c in range(3):
            soma = matriz[0][c] + matriz[1][c] + matriz[2][c]
            if soma in [2, 8]:
                for l in range(3):
                    if matriz[l][c] == DESCONHECIDO:
                        return (l, c)

        soma = matriz[0][0] + matriz[1][1] + matriz[2][2]
        if soma in [2, 8]:
            for i in range(3):
                if matriz[i][i] == DESCONHECIDO:
                    return (i, i)

        soma = matriz[0][2] + matriz[1][1] + matriz[2][0]
        if soma in [2, 8]:
            for i in range(3):
                if matriz[i][2 - i] == DESCONHECIDO:
                    return (i, 2 - i)

        # R2: Cria duas sequências possíveis (fork)
        for l in range(3):
            for c in range(3):
                if matriz[l][c] == DESCONHECIDO:
                    matriz[l][c] = J0
                    count = 0

                    if sum(matriz[l]) == 2:
                        count += 1
                    if matriz[0][c] + matriz[1][c] + matriz[2][c] == 2:
                        count += 1
                    if l == c and matriz[0][0] + matriz[1][1] + matriz[2][2] == 2:
                        count += 1
                    if l + c == 2 and matriz[0][2] + matriz[1][1] + matriz[2][0] == 2:
                        count += 1

                    matriz[l][c] = DESCONHECIDO
                    if count >= 2:
                        return (l, c)

        # R3: Centro livre
        if matriz[1][1] == DESCONHECIDO:
            return (1, 1)

        # R4: Canto oposto ao do oponente
        cantos = [(0,0), (0,2), (2,0), (2,2)]
        for x, y in cantos:
            ox, oy = 2 - x, 2 - y
            if matriz[x][y] == JX and matriz[ox][oy] == DESCONHECIDO:
                return (ox, oy)

        # R5: Qualquer canto livre
        for x, y in cantos:
            if matriz[x][y] == DESCONHECIDO:
                return (x, y)

        # R6: Qualquer espaço livre
        for l in range(3):
            for c in range(3):
                if matriz[l][c] == DESCONHECIDO:
                    return (l, c)

        return None
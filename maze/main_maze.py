# -*- coding: utf-8 -*-
import time
from maze import Maze
from collections import deque

# --- Implementação do Algoritmo de Backtracking ---

def solve_maze(maze, stack):
    """
    Implementa o algoritmo de backtracking para resolver o labirinto.
    """
    #Localiza a posição do jogador
    start_pos = maze.get_init_pos_player()

    #Tu insere a tua localização na pilha
    stack.append(start_pos)

    #Adição de um conjunto para rastrear células visitadas, pra evitar arrodeio
    visited = set()
    visited.add(start_pos)

    #Fará isso enquanto a pilha não esvaziar
    while stack:
        #Tempo pra poder ver
        time.sleep(0.05)

        #Usa o pop() pra tirar a última localização da pilha
        current_pos = stack.pop()

        #O jogador vai pra a última localização
        maze.mov_player(current_pos)

        #Se a posição tiver o prêmio, aí:
        if maze.find_prize(current_pos): 
            print("Tesouro encontrado!") #Encontrou o caminho
            maze.solution_found = True   #Para a mensagem de vitória
            return True                  #Retorna True
        
        #Verifica se as casas adjacentes tão liberadas
        (row, col) = current_pos
        neighbors = [(row - 1, col), (row + 1, col), (row, col - 1), (row, col + 1)]

        #Vê se já visitou o vizinho ou nem
        for next_pos in neighbors:
            if next_pos not in visited and maze.is_free(next_pos):
                visited.add(next_pos)
                stack.append(next_pos)

    #Terminou o laço, a pilha esvaziou e não tem prêmio
    print("Caminho não encontrado.")
    return False #Retornar False

# --- Código Principal (já existente, com a chamada da função de solução) ---

# Criação de uma nova pilha
s = deque()

maze_csv_path = "labirinto1.txt"
maze = Maze()
maze.load_from_csv(maze_csv_path)

# Visualização do labirinto
maze.run()

time.sleep(1) 

maze.init_player()

solve_maze(maze, s)

maze.display_thread.join()
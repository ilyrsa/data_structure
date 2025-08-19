# Sobre o Projeto 📚

<p align="center">
  Seja bem-vindo(a)! Este repositório aqui foi criado para guardar os exercícios e implementações da disciplina de Estrutura de Dados. Aqui você encontrará códigos em Python, C++ e C, com diversas estruturas e algoritmos fundamentais para os estudos.
</p>

## 🛠️ Tecnologias Utilizadas

As principais tecnologias e linguagens utilizadas neste projeto foram:

* **Python**
* **C++**
* **C**
* **Makefile** para automação de compilação.

## 📂 Estruturas e Algoritmos Implementados

O repositório está organizado nos seguintes módulos:

### 1. Listas (`/lists`)
Implementações de diferentes tipos de listas.
* **Lista Dinâmica Sequencial:** Variação da lista sequencial com alocação dinâmica de memória.
* **Lista Dinamicamente Encadeada:** Implementação de lista utilizando ponteiros.

### 2. Labirinto (`/maze`)
Um algoritmo em Python que encontra a solução para um labirinto.
* **`maze.py`**: Contém a lógica principal do algoritmo de busca.
* **`main_maze.py`**: Arquivo principal para execução do programa.
* **`labirinto1.txt`**: Arquivo de exemplo com a estrutura do labirinto.

### 3. Algoritmos de Ordenação (`/ordination-sort`)
Implementação e comparação de algoritmos de ordenação em Python.
* **`selection-and-insertion.py`**: Script contendo os algoritmos Selection Sort e Insertion Sort.
* **`instancias-num`**: Pasta com conjuntos de dados para testar os algoritmos.

### 4. Fila Sequencial (`/sequential-queue`)
Implementação de uma Fila (Queue) em C++.
* **`fila.hpp`**: Arquivo de cabeçalho com a definição da estrutura da fila.
* **`main.cpp`**: Exemplo de uso da fila implementada.

### 5. Jogo da Velha (`/tic-tac-toe`)
Uma implementação completa do clássico Jogo da Velha em Python.
* **`main.py`**: Ponto de entrada para iniciar o jogo.
* **`jogo_velha.py`**: Contém as regras e a lógica principal do jogo.
* **`tabuleiro.py`**: Lógica para o tabuleiro do jogo.
* **Outros arquivos**: Módulos para jogador, botões e interface.

## 🚀 Como Executar

Cada projeto possui sua própria forma de execução.

### Projetos em Python (Labirinto, Ordenação, Jogo da Velha)

1.  **Clone o repositório:**
    ```bash
    git clone [https://github.com/ilyrsa/data_structure.git](https://github.com/ilyrsa/data_structure.git)
    ```
2.  **Navegue até a pasta do projeto:**
    ```bash
    cd data_structure/maze 
    # ou a pasta do projeto que deseja executar
    ```
3.  **(Opcional) Crie um ambiente virtual:**
    ```bash
    python -m venv venv
    source venv/bin/activate # No Windows: venv\Scripts\activate
    ```
4.  **Instale as dependências (se houver um `requirements.txt`):**
    ```bash
    pip install -r requirements.txt
    ```
5.  **Execute o arquivo principal:**
    ```bash
    python main.py 
    # ou o nome do arquivo principal do projeto
    ```

### Projetos em C/C++ (Listas, Fila)

1.  **Clone o repositório:**
    ```bash
    git clone [https://github.com/ilyrsa/data_structure.git](https://github.com/ilyrsa/data_structure.git)
    ```
2.  **Navegue até a pasta do projeto:**
    ```bash
    cd data_structure/sequential-queue
    ```
3.  **Compile os arquivos (exemplo com g++):**
    ```bash
    g++ main.cpp -o programa
    ```
4.  **Execute o programa compilado:**
    ```bash
    ./programa
    ```

## 🤝 Autora

* **Larissa Donato** - [ilyrsa](https://github.com/ilyrsa)

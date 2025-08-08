// main.cpp - Arquivo para testar a classe Fila
// Copie e cole APENAS o código abaixo.

#include <iostream>
#include "Fila.hpp" // Inclui a sua classe Fila

// Função para imprimir um separador e facilitar a leitura
void imprimirSeparador()
{
    std::cout << "\n========================================\n"
              << std::endl;
}

int main()
{
    std::cout << "Iniciando os testes da Fila Encadeada..." << std::endl;
    Fila minhaFila;

    // --- TESTE 1: Fila Vazia ---
    imprimirSeparador();
    std::cout << "TESTE 1: A fila recem-criada deve estar vazia." << std::endl;
    std::cout << "A fila esta vazia? " << (minhaFila.estaVazia() ? "Sim (Correto)" : "Nao (Erro)") << std::endl;
    std::cout << "A fila esta cheia? " << (minhaFila.estaCheia() ? "Sim (Erro)" : "Nao (Correto)") << std::endl;

    // --- TESTE 2: Inserir elementos ---
    imprimirSeparador();
    std::cout << "TESTE 2: Inserindo os valores 10, 20, 30." << std::endl;
    minhaFila.inserir(10);
    minhaFila.inserir(20);
    minhaFila.inserir(30);
    std::cout << "Estado atual da fila: ";
    minhaFila.imprimir();
    std::cout << "A fila esta vazia? " << (minhaFila.estaVazia() ? "Sim (Erro)" : "Nao (Correto)") << std::endl;

    // --- TESTE 3: Consultar Início ---
    imprimirSeparador();
    std::cout << "TESTE 3: Consultando o elemento no inicio da fila." << std::endl;
    std::cout << "O elemento no inicio deve ser 10." << std::endl;
    std::cout << "Valor consultado: " << minhaFila.consultarInicio() << std::endl;
    std::cout << "Estado atual da fila (nao deve mudar): ";
    minhaFila.imprimir();

    // --- TESTE 4: Remover um elemento ---
    imprimirSeparador();
    std::cout << "TESTE 4: Removendo um elemento do inicio." << std::endl;
    std::cout << "O elemento removido deve ser 10." << std::endl;
    int valorRemovido = minhaFila.remover();
    std::cout << "Valor removido: " << valorRemovido << std::endl;
    std::cout << "Estado atual da fila: ";
    minhaFila.imprimir();
    std::cout << "O novo inicio da fila deve ser 20." << std::endl;
    std::cout << "Valor consultado: " << minhaFila.consultarInicio() << std::endl;

    // --- TESTE 5: Esvaziar a fila ---
    imprimirSeparador();
    std::cout << "TESTE 5: Removendo os elementos restantes." << std::endl;
    std::cout << "Removido: " << minhaFila.remover() << std::endl;
    std::cout << "Removido: " << minhaFila.remover() << std::endl;
    std::cout << "Estado atual da fila: ";
    minhaFila.imprimir();
    std::cout << "A fila esta vazia agora? " << (minhaFila.estaVazia() ? "Sim (Correto)" : "Nao (Erro)") << std::endl;

    // --- TESTE 6: Testar Erros (remover de fila vazia) ---
    imprimirSeparador();
    std::cout << "TESTE 6: Tentando remover de uma fila vazia (deve dar erro)." << std::endl;
    try
    {
        minhaFila.remover();
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Capturou a excecao esperada: " << e.what() << std::endl;
    }

    std::cout << "\nFim dos testes." << std::endl;

    return 0;
}
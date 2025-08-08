#ifndef FILA_HPP
#define FILA_HPP

#include <iostream>
#include <stdexcept>

// Nó da fila
struct FilaNo
{
    int info;        // O dado armazenado no nó.
    FilaNo *proximo; // Ponteiro para o próximo nó na fila.

    // Construtor do nó
    FilaNo(int val) : info(val), proximo(nullptr) {}
};

// Classe da Fila
class Fila
{
private:
    FilaNo *frente; // Ponteiro para o primeiro elemento da fila
    FilaNo *tras;   // Ponteiro para o último elemento da fila
    int tamanho;    // Variável para armazenar a quantidade atual de elementos na fila.

public:
    // Construtor
    // Inicializa a fila como vazia.
    Fila()
    {
        frente = nullptr;
        tras = nullptr;
        tamanho = 0;
    }

    // Operação: Indicar se a fila está vazia
    // Retorna 'true' se a fila não contém elementos, e 'false' caso contrário.
    bool estaVazia()
    {
        return frente == nullptr;
    }

    // Operação: Remover do início da fila
    // Remove o elemento da frente da fila e retorna seu valor.
    int remover()
    {
        // 1: Lança uma exceção se tentarem remover de uma fila já vazia
        if (estaVazia())
        {
            throw std::runtime_error("Erro: A fila está vazia!");
        }

        // 2: Guarda o valor do nó da frente, que será retornado no final.
        int valorRemovido = frente->info;
        // 3: Cria um ponteiro temporário para o nó da frente, para poder deletá-lo
        FilaNo *temp = frente;

        // 4: Atualiza o ponteiro 'frente' para que aponte para o próximo nó da fila.
        frente = frente->proximo;

        // 5: Caso especial - se, após a remoção, 'frente' se tornou nulo,
        // isso significa que a fila ficou vazia. Portanto, 'tras' também deve ser nulo.
        if (frente == nullptr)
        {
            tras = nullptr;
        }

        // 6: Libera a memória ocupada pelo nó que foi removido.
        delete temp;
        // 7: Decrementa o contador de tamanho da fila.
        tamanho--;

        // Passo 8: Retorna o valor que foi removido.
        return valorRemovido;
    }

    // Destrutor
    // Sua função é liberar toda a memória alocada para os nós, evitando vazamentos de memória.
    ~Fila()
    {
        while (!estaVazia())
        {
            remover();
        }
    }

    // Operação: Indicar se a fila está cheia

    bool estaCheia()
    {
        return false;
    }

    // Operação: Inserir no fim da fila
    void inserir(int valor)
    {
        // 1: Aloca memória para um novo nó com o valor fornecido.
        FilaNo *novoNo = new FilaNo(valor);

        // 2: Verifica se a fila está vazia.
        if (estaVazia())
        {
            // Se estiver vazia, o novo nó é tanto o início quanto o fim da fila.
            frente = novoNo;
            tras = novoNo;
        }
        // 3: Se a fila já contém elementos.
        else
        {
            // O nó que atualmente é o 'tras' passa a apontar para o novo nó.
            tras->proximo = novoNo;
            tras = novoNo;
        }
        // 4: Incrementa o contador de tamanho.
        tamanho++;
    }

    // Operação: Consultar o início da fila
    int consultarInicio()
    {
        // Lança uma exceção se a fila estiver vazia.
        if (estaVazia())
        {
            throw std::runtime_error("Erro: A fila está vazia!");
        }

        // Retorna o dado do nó apontado por 'frente'.
        return frente->info;
    }

    // Método auxiliar para imprimir a fila
    void imprimir()
    {
        // Se a fila estiver vazia, apenas informa.
        if (estaVazia())
        {
            std::cout << "Fila vazia." << std::endl;
            return;
        }

        // Imprime o início da representação visual da fila.
        std::cout << "Fila: [ frente -> ";

        // Cria um ponteiro 'atual' para percorrer a fila sem modificar 'frente'.
        FilaNo *atual = frente;

        // Loop que continua enquanto 'atual' não for nulo
        while (atual != nullptr)
        {
            std::cout << atual->info << " ";

            // Move o ponteiro para o próximo nó.
            atual = atual->proximo;
        }

        // Imprime o final da representação visual.
        std::cout << "<- tras ]" << std::endl;
    }
};

#endif // FILA_HPP
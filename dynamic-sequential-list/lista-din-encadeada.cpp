#include <iostream>
#include <stdexcept>

// Estrutura do nó da lista
struct Node
{
    int data;
    Node *prox;
    Node(int value) : data(value), prox(nullptr) {}
};

class ListaDin
{
private:
    Node *cabess;
    int tam;

public:
    // Construtor da lista
    ListaDin() : cabess(nullptr), tam(0) {}
    // Desconstrutor
    ~ListaDin()
    {
        while (!isEmpty())
        {
            remove(1);
        }
    }

    bool isEmpty() const
    {
        return tam == 0;
    }

    int size() const
    {
        return tam;
    }

    Node *getNode(int position) const
    {
        if (position < 1 || position > tam)
        {
            throw std::out_of_range("Position out of range");
        }
        Node *current = cabess;
        for (int i = 1; i < position; ++i)
        {
            current = current->prox;
        }
        return current;
    }

    int get(int position) const
    {
        return getNode(position)->data;
    }

    void set(int position, int value)
    {
        getNode(position)->data = value;
    }

    void insert(int position, int value)
    {
        if (position < 1 || position > tam + 1)
        {
            throw std::out_of_range("A posicao nao existe nao");
        }
        Node *newNode = new Node(value);
        if (position == 1)
        {
            newNode->prox = cabess;
            cabess = newNode;
        }
        else
        {
            Node *prev = getNode(position - 1);
            newNode->prox = prev->prox;
            prev->prox = newNode;
        }
        tam++;
    }

    int remove(int position)
    {
        if (position < 1 || position > tam)
        {
            throw std::out_of_range("A posicao nao existe.");
        }
        Node *toDelete;
        int removedValue;
        if (position == 1)
        {
            toDelete = cabess;
            cabess = cabess->prox;
        }
        else
        {
            Node *prev = getNode(position - 1);
            toDelete = prev->prox;
            prev->prox = toDelete->prox;
        }
        removedValue = toDelete->data;
        delete toDelete;
        tam--;
        return removedValue;
    }

    void printAll() const
    {
        Node *current = cabess;
        std::cout << "[ ";
        while (current)
        {
            std::cout << current->data;
            if (current->prox)
                std::cout << ", ";
            current = current->prox;
        }
        std::cout << " ]" << std::endl;
    }
};

int main()
{
    ListaDin list;

    std::cout << "\n1. Verificando a lista recem-criada..." << std::endl;
    std::cout << "Lista esta vazia? " << (list.isEmpty() ? "Sim" : "Não") << std::endl; // Operação 2 e 6 do seu menu
    std::cout << "Tamanho da lista: " << list.size() << std::endl;                      // Operação 5
    std::cout << "Imprimindo lista vazia: ";
    list.printAll();

    // Inserção de elementos
    std::cout << "\n2. Inserindo elementos..." << std::endl; // Operação 1 do seu menu
    try
    {
        list.insert(1, 10);
        std::cout << "Inserido valor 10 na posicao 1. Lista atual: ";
        list.printAll();

        list.insert(2, 30);
        std::cout << "Inserido valor 30 na posicao 2. Lista atual: ";
        list.printAll();

        list.insert(2, 20);
        std::cout << "Inserido valor 20 na posicao 2. Lista atual: ";
        list.printAll();
        std::cout << "Tamanho atual: " << list.size() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro inesperado na insercao: " << e.what() << std::endl;
    }

    // Obter e Modificar
    std::cout << "\n3. Obtendo e modificando elementos..." << std::endl;
    try
    {
        std::cout << "Valor na posicao 3: " << list.get(3) << std::endl;       // Operação 3
        std::cout << "Modificando valor na posicao 3 para 99..." << std::endl; // Operação 4
        list.set(3, 99);
        std::cout << "Lista apos modificacao: ";
        list.printAll();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro ao obter/modificar: " << e.what() << std::endl;
    }

    // Remover elementos
    std::cout << "\n4. Removendo elementos..." << std::endl; // Operação 2
    try
    {
        int val = list.remove(1);
        std::cout << "Valor removido da posicao 1: " << val << ". Lista atual: ";
        list.printAll();

        val = list.remove(2);
        std::cout << "Valor removido da posicao 2: " << val << ". Lista atual: ";
        list.printAll();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro na remocao: " << e.what() << std::endl;
    }

    // Mostrando o final
    std::cout << "\n5. Verificacoes finais..." << std::endl;
    std::cout << "Tamanho final da lista: " << list.size() << std::endl;
    std::cout << "Lista esta vazia? " << (list.isEmpty() ? "Sim" : "Nao") << std::endl;
    std::cout << "Conteudo final: ";
    list.printAll();

    return 0;
}
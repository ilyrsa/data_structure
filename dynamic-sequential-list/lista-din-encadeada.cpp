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
    int option, pos, val;

    do
    {
        std::cout << "\n--- MENU ---\n";
        std::cout << "1. Inserir elemento\n";
        std::cout << "2. Remover elemento\n";
        std::cout << "3. Obter elemento\n";
        std::cout << "4. Modificar elemento\n";
        std::cout << "5. Ver tamanho da lista\n";
        std::cout << "6. Verificar se esta vazia\n";
        std::cout << "7. Imprimir todos os elementos\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha alguma coisa: ";
        std::cin >> option;

        try
        {
            switch (option)
            {
            case 1:
                std::cout << "Digite a posicao para inserir: ";
                std::cin >> pos;
                std::cout << "Digite o valor: ";
                std::cin >> val;
                list.insert(pos, val);
                break;
            case 2:
                std::cout << "Digite a posicao para remover: ";
                std::cin >> pos;
                val = list.remove(pos);
                std::cout << "Valor removido: " << val << std::endl;
                break;
            case 3:
                std::cout << "Digite a posicao para obter: ";
                std::cin >> pos;
                val = list.get(pos);
                std::cout << "Valor: " << val << std::endl;
                break;
            case 4:
                std::cout << "Digite a posicao para modificar: ";
                std::cin >> pos;
                std::cout << "Digite o novo valor: ";
                std::cin >> val;
                list.set(pos, val);
                break;
            case 5:
                std::cout << "Tamanho da lista: " << list.size() << std::endl;
                break;
            case 6:
                std::cout << "Lista esta vazia? " << (list.isEmpty() ? "Sim" : "Não") << std::endl;
                break;
            case 7:
                list.printAll();
                break;
            case 0:
                std::cout << "Saindo..." << std::endl;
                break;
            default:
                std::cout << "Isso dae nao existe!" << std::endl;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "Erro: " << e.what() << std::endl;
        }

    } while (option != 0);

    return 0;
}
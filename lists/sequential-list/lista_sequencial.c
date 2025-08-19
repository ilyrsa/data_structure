#include "lista_sequencial.h"
#include <stdio.h>
#include <stdlib.h>

void criarLista(Lista *lista)
{
    lista->ctrl = -1;
}

int listaVazia(Lista *lista)
{
    return (lista->ctrl == -1);
}

int listaCheia(Lista *lista)
{
    return (lista->ctrl == MAX_TAM - 1);
}

int tamanhoLista(Lista *lista)
{
    return lista->ctrl + 1;
}

int obterElemento(Lista *lista, int pos, int *valor)
{
    if (pos < 1 || pos > tamanhoLista(lista))
    {
        printf("Erro: posicao invalida!\n");
        return 0;
    }
    *valor = lista->dado[pos - 1];
    return 1;
}

int inserirElemento(Lista *lista, int pos, int valor)
{
    if (listaCheia(lista) || pos < 1 || pos > tamanhoLista(lista) + 1)
    {
        printf("Erro: lista cheia ou posicao invalida!\n");
        return 0;
    }

    // Deslocar elementos para a direita
    for (int i = tamanhoLista(lista); i >= pos; i--)
    {
        lista->dado[i] = lista->dado[i - 1];
    }

    lista->dado[pos - 1] = valor;
    lista->ctrl++;
    return 1;
}

int modificarElemento(Lista *lista, int pos, int valor)
{
    if (pos < 1 || pos > tamanhoLista(lista))
    {
        printf("Erro: posicao invalida!\n");
        return 0;
    }
    lista->dado[pos - 1] = valor;
    return 1;
}

int removerElemento(Lista *lista, int pos, int *valor)
{
    if (listaVazia(lista) || pos < 1 || pos > tamanhoLista(lista))
    {
        printf("Erro: lista vazia ou posicao invalida!\n");
        return 0;
    }
    *valor = lista->dado[pos - 1];

    // Deslocar elementos para a esquerda
    for (int i = pos - 1; i < tamanhoLista(lista) - 1; i++)
    {
        lista->dado[i] = lista->dado[i + 1];
    }
    lista->ctrl--;
    return 1;
}

void imprimirLista(Lista *lista)
{
    if (listaVazia(lista))
    {
        printf("Lista vazia!\n");
        return;
    }

    printf("Lista [");
    for (int i = 0; i <= lista->ctrl; i++)
    {
        printf("%d", lista->dado[i]);
        if (i < lista->ctrl)
            printf(", ");
    }
    printf("]\n");
}

int main()
{
    Lista minhaLista;
    criarLista(&minhaLista);
    int opcao, pos, valor;

    do
    {
        printf("\n------ MENU ------\n");
        printf("1. Inserir elemento\n");
        printf("2. Modificar elemento\n");
        printf("3. Remover elemento\n");
        printf("4. Obter elemento\n");
        printf("5. Verificar se vazia\n");
        printf("6. Verificar se cheia\n");
        printf("7. Tamanho da lista\n");
        printf("8. Imprimir lista\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Posicao para inserir: ");
            scanf("%d", &pos);
            printf("Valor: ");
            scanf("%d", &valor);
            if (inserirElemento(&minhaLista, pos, valor))
            {
                printf("Elemento inserido com sucesso!\n");
            }
            break;

        case 2:
            printf("Posicao para modificar: ");
            scanf("%d", &pos);
            printf("Novo valor: ");
            scanf("%d", &valor);
            if (modificarElemento(&minhaLista, pos, valor))
            {
                printf("Elemento modificado com sucesso!\n");
            }
            break;

        case 3:
            printf("Posicao para remover: ");
            scanf("%d", &pos);
            if (removerElemento(&minhaLista, pos, &valor))
            {
                printf("Elemento removido: %d\n", valor);
            }
            break;

        case 4:
            printf("Posicao para obter: ");
            scanf("%d", &pos);
            if (obterElemento(&minhaLista, pos, &valor))
            {
                printf("Elemento na posicao %d: %d\n", pos, valor);
            }
            else
            {
                printf("Posicao invalida!\n");
            }
            break;

        case 5:
            if (listaVazia(&minhaLista))
            {
                printf("Lista esta vazia!\n");
            }
            else
            {
                printf("Lista nao esta vazia!\n");
            }
            break;

        case 6:
            if (listaCheia(&minhaLista))
            {
                printf("Lista esta cheia!\n");
            }
            else
            {
                printf("Lista nao esta cheia!\n");
            }
            break;

        case 7:
            printf("Tamanho da lista: %d elementos\n", tamanhoLista(&minhaLista));
            break;

        case 8:
            imprimirLista(&minhaLista);
            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
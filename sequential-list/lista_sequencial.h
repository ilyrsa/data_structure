#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#define MAX_TAM 50

typedef struct
{
    int dado[MAX_TAM];
    int ctrl;
} Lista;

void criarLista(Lista *lista);
int listaVazia(Lista *lista);
int listaCheia(Lista *lista);
int tamanhoLista(Lista *lista);
int obterElemento(Lista *lista, int pos, int *valor);
int inserirElemento(Lista *lista, int pos, int valor);
int modificarElemento(Lista *lista, int pos, int valor);
int removerElemento(Lista *lista, int pos, int *valor);
void imprimirLista(Lista *lista);

#endif
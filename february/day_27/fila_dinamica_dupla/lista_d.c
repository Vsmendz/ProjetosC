#include "lista_d.h"

tipo_lista *alocaNo(int valor)
{
    tipo_lista *novo_no;
    novo_no = (tipo_lista *)malloc(sizeof(tipo_lista));
    novo_no->valor = valor;
    novo_no->prox = NULL;
    novo_no->ant = NULL;
}

void inserirIni(tipo_lista **ls, int valor)
{
    if ((*ls) == NULL)
    {
        (*ls) = alocaNo(valor);
    }
    else
    {
        tipo_lista *aux = alocaNo(valor);
        (*ls)->ant = aux;
        aux->prox = (*ls);
        (*ls) = aux;
    }
}

void inserirFim(tipo_lista **ls, int valor)
{
    if ((*ls) == NULL)
    {
        inserirIni(ls, valor);
    }
    else
    {
        tipo_lista *aux;
        aux = (*ls);
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = alocaNo(valor);
        aux->prox->ant = aux;
    }
}

void inserirId(tipo_lista **ls,int valor,int id){
    int posicao = 0;
    tipo_lista *aux = (*ls),*novo_no;

    if (id == 0)
    {
        inserirIni(ls,valor);
    }else{
        while (id != posicao && aux->prox != NULL )
        {
            aux = aux->prox;
            posicao += 1;
        }
        if (id > posicao)
        {
            printf("[ERROR 404] index not found [%d] not alocatted\n",valor);
            return;
        }
        novo_no = alocaNo(valor);

        novo_no->ant = aux->ant;
        aux->ant->prox = novo_no;
        novo_no->prox = aux;
        aux->ant = novo_no;
    }
}

void imprimir(tipo_lista*ls){
    tipo_lista *aux = ls;

    while (aux != NULL)
    {
        printf("<[%d]>",aux->valor);
        aux = aux->prox;
    }
}

void removerIni(tipo_lista **ls)
{
    if ((*ls) == NULL)
    {
        return; // Fila vazia
    }
    tipo_lista *temp = *ls;
    (*ls) = (*ls)->prox;
    if (*ls != NULL)
    {
        (*ls)->ant = NULL;
    }
    free(temp);
}

void removerFim(tipo_lista **ls)
{
    if ((*ls) == NULL)
    {
        return; // Fila vazia
    }
    tipo_lista *aux = *ls;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    if (aux->ant != NULL)
    {
        aux->ant->prox = NULL;
    }
    else
    {
        *ls = NULL; // Último elemento removido
    }
    free(aux);
}

void removerValor(tipo_lista **ls, int valor)
{
    if ((*ls) == NULL)
    {
        return; // Fila vazia
    }
    tipo_lista *aux = *ls;
    while (aux != NULL && aux->valor != valor)
    {
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        return; // Valor não encontrado
    }
    if (aux->ant != NULL)
    {
        aux->ant->prox = aux->prox;
    }
    else
    {
        *ls = aux->prox; // Removendo o primeiro elemento
    }
    if (aux->prox != NULL)
    {
        aux->prox->ant = aux->ant;
    }
    free(aux);
}

void removerId(tipo_lista **ls, int id)
{
    if ((*ls) == NULL || id < 0)
    {
        return; // Fila vazia ou índice inválido
    }
    tipo_lista *aux = *ls;
    int posicao = 0;
    while (aux != NULL && posicao < id)
    {
        aux = aux->prox;
        posicao++;
    }
    if (aux == NULL)
    {
        return; // Índice fora dos limites
    }
    if (aux->ant != NULL)
    {
        aux->ant->prox = aux->prox;
    }
    else
    {
        *ls = aux->prox; // Removendo o primeiro elemento
    }
    if (aux->prox != NULL)
    {
        aux->prox->ant = aux->ant;
    }
    free(aux);
}


tipo_lista* buscar(tipo_lista *ls, int valor)
{
    tipo_lista *aux = ls;
    while (aux != NULL)
    {
        if (aux->valor == valor)
        {
            return aux; // Retorna o nó encontrado
        }
        aux = aux->prox;
    }
    return NULL; // Valor não encontrado
}

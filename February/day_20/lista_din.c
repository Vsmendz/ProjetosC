#include "lista_din.h"

tipo_lista* aloca_no(int valor,int index){
    //criando variavel novo_no
    tipo_lista *novo_no;
    novo_no = (tipo_lista *) malloc(sizeof(tipo_lista));
    //preenchendo os valores
    novo_no->no=NULL;
    novo_no->index=index;
    novo_no->valor=valor;
    //retornando
    return novo_no;
}

void inserir_first(tipo_lista**ls,int valor){
    int index = 0;
    tipo_lista *aux;
    if ((*ls)==NULL)
    {
        *ls = aloca_no(valor,index);
    }else{
        aux = aloca_no(valor,index);
        aux->no = (*ls);
        (*ls) = aux;
        while (aux->no!= NULL)
        {
            aux = aux->no;
            aux->index = ++index;
        }
    }     
}
void inserir_end(tipo_lista**ls,int valor){
    int index = 0;
    tipo_lista *aux;
    if ((*ls)==NULL)
    {
        *ls = aloca_no(valor,index);
    }else{
        aux = (*ls);
        while (aux->no!=NULL)
        {
            aux = aux->no;
        }
        index = aux->index;
        aux->no = aloca_no(valor,++index);
    }     
}
void inserir_index(tipo_lista**ls,int valor,int index){
    tipo_lista *aux1,*aux2;
    int p = 0;
    if (index == 0)
    {
        aux1 = (*ls);
        inserir_first(ls,valor);
        return;
    }

    aux1 = (*ls);
    aux2 = (*ls)->no;
    while (1)
    {
        if (aux2->index == index)
        {
            aux1->no = aloca_no(valor,++(aux1->index));
            aux1 = aux1->no;
            aux1->no = aux2;
            aux1 = (*ls);
            while (aux1->no!= NULL)
            {
                aux1 = aux1->no;
                aux1->index = ++p;
            }
            return;
        }else{
            if (aux2->no == NULL)
            {
                printf("[ERROR] index maior que a lista\n");
                return;
            }
            aux1 = aux1->no;
            aux2 = aux2->no;
        }
    }
}


void imprimir(tipo_lista* ls){
    tipo_lista *aux;
    aux = ls;
    int flag = 1;
    while (flag)
    {
        if (aux->no == NULL)
        {
            flag = 0;
        }   
        printf("[%d] index = %d\n",aux->valor,aux->index);
        aux = aux->no;
    }
}
void buscar_index(tipo_lista* ls,int index){
    tipo_lista *aux;
    aux = ls;
    while (aux->no != NULL)
    {
        if (aux->index == index)
        {
            printf("valor no index %d [%d]\n",index,aux->valor);
        }
        aux = aux->no;
    }
}

void buscar_valor(tipo_lista* ls,int valor){
    tipo_lista *aux;
    aux = ls;
    while (aux->no != NULL)
    {
        if (aux->valor == valor)
        {
            printf("valor encontrado [%d] index [%d]\n",valor,aux->index);
        }
        aux = aux->no;
    }
}

void remover_first(tipo_lista** ls) {
    if (*ls == NULL) {
        printf("[ERROR] Lista vazia\n");
        return;
    }
    
    tipo_lista* temp = *ls;
    *ls = (*ls)->no;
    free(temp);

    // Atualizando índices
    tipo_lista* aux = *ls;
    int index = 0;
    while (aux != NULL) {
        aux->index = index++;
        aux = aux->no;
    }
}

void remover_end(tipo_lista** ls) {
    if (*ls == NULL) {
        printf("[ERROR] Lista vazia\n");
        return;
    }

    tipo_lista* aux = *ls;
    tipo_lista* prev = NULL;

    while (aux->no != NULL) {
        prev = aux;
        aux = aux->no;
    }

    if (prev == NULL) {
        free(*ls);
        *ls = NULL;
    } else {
        free(aux);
        prev->no = NULL;
    }
}

void remover_index(tipo_lista** ls, int index) {
    if (*ls == NULL) {
        printf("[ERROR] Lista vazia\n");
        return;
    }

    if (index == 0) {
        remover_first(ls);
        return;
    }

    tipo_lista* aux = *ls;
    tipo_lista* prev = NULL;

    while (aux != NULL && aux->index != index) {
        prev = aux;
        aux = aux->no;
    }

    if (aux == NULL) {
        printf("[ERROR] Index não encontrado\n");
        return;
    }

    prev->no = aux->no;
    free(aux);

    // Atualizando índices
    aux = prev->no;
    int i = index;
    while (aux != NULL) {
        aux->index = i++;
        aux = aux->no;
    }
}

void remover_valor(tipo_lista** ls, int valor) {
    if (*ls == NULL) {
        printf("[ERROR] Lista vazia\n");
        return;
    }

    tipo_lista* aux = *ls;
    tipo_lista* prev = NULL;

    while (aux != NULL) {
        if (aux->valor == valor) {
            if (prev == NULL) {
                *ls = aux->no;
            } else {
                prev->no = aux->no;
            }
            free(aux);
            break;
        }
        prev = aux;
        aux = aux->no;
    }

    // Atualizando índices
    aux = *ls;
    int index = 0;
    while (aux != NULL) {
        aux->index = index++;
        aux = aux->no;
    }
}

int contagem(tipo_lista*ls){
    tipo_lista *aux;
    aux = ls;
    while (aux->no != NULL)
    {
        aux = aux->no;
    }
    return aux->index + 1;
}

#include "pilha_din.h"

pilha_dado* alocar_no(int valor){
    pilha_dado* pd_no;

    pd_no = (pilha_dado*) malloc(sizeof(pilha_dado*));
    pd_no->valor = valor;
    pd_no->no = NULL;
    return pd_no;
}

void empilhar(int valor,pilha_dado **pd){
    if ((*pd)==NULL)
    {
        (*pd) = alocar_no(valor);
    }else{
        pilha_dado *aux;
        aux =alocar_no(valor);
        aux->no = (*pd);
        (*pd) = aux;
    }   
}

void print(pilha_dado *pd){
    if (pd==NULL)
    {
        printf("pilha vazia\n");
    }else{
        printf("pilha atualmente\n");
        pilha_dado *aux = pd;
        while (aux!= NULL)
        {
            printf("[%d]\n",aux->valor);
            aux = aux->no;
        }
    }
}

void desempilhar(pilha_dado **pd){
    if ((*pd)==NULL)
    {
        printf("[ERROR] pilha ja esta vazia\n");
    }else{    
        pilha_dado *aux;
        aux = (*pd);
        (*pd) = (*pd)->no;
        free(aux);
    }


}
int rec_print(pilha_dado*pd){
    if (pd->no==NULL)
    {
        return pd->valor;  
    }else{
        return rec_print(pd->no);
    }
    
}
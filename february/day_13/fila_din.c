/*** 
 * Alocacao dinamica de memoria
 * > encadeamento de nos
 * o no deve contar o dado e um componente que permite o encadeamento (ponteiro)
 * 
 */
#include "fila_din.h" 

tipo_fila *aloc_no(int valor){
    tipo_fila *novo_no;

    novo_no = (tipo_fila*) malloc(sizeof(tipo_fila));
    novo_no->valor = valor;
    novo_no->prox = NULL;
    return novo_no;
}

void inserir_fila(tipo_fila **fl,int valor){
    if ((*fl)==NULL)
    {
        (*fl) = aloc_no(valor);
    }else{
        tipo_fila * aux, *novo_no;

        aux = (*fl);
        while (aux->prox != NULL)
            aux = aux->prox;
        
        novo_no = aloc_no(valor);
        aux->prox = novo_no;
    }
}

int remover_fila(tipo_fila **fl){
    tipo_fila *aux;
    if ((*fl)!=NULL)
    {
        aux = (*fl);
        int aux_valor = aux->valor;
        (*fl) = (*fl)->prox;
        free(aux);
        return aux_valor;
    }
}

int print_primeiro(tipo_fila *fl){
    if (fl == NULL)
    {
        printf("fila vazia\n");
    }else{
        return fl->valor;
    }
}

int print_all(tipo_fila *ofl){
    tipo_fila *aux = ofl;

    if (aux == NULL)
    {
        printf("fila vazia\n");
    }else{
        printf("fila: ");
        while (aux != NULL)
        {
            printf("%d ",aux->valor);
            aux = aux->prox;
        }
        printf("\n");
    }
}


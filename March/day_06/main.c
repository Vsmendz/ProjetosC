#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define MAX 5

int main() {
    Lista l;
    l.count = 0;

    int a, posicao;


    printf("Inserir elementos no início da lista:\n");
    for (int i = 0; i < 3; i++) {
        printf("Informe um valor para inserir no início: ");
        scanf("%d", &a);
        inserirInicio(&l, a);
    }
    imprimirLista(&l);

    bubbleSort(&l);

    imprimirLista(&l); 

    return 0;
}

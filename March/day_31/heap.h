/***
 * Estrutura Hierarquica
 * A chave (QUE IDENTIFICA O DADO) determina o comportamento da estrutura
 * Ha dois tipos de heap
 * ->heap maximo
 * ->heap minino
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100


struct heap
{
    int lista[MAX];
    int cont;
};
typedef struct heap tipo_heap;

tipo_heap* iniciar_heap();
void inserir(tipo_heap*,int);
void sobe_heap(tipo_heap*,int);
void desce_heap(tipo_heap*,int);

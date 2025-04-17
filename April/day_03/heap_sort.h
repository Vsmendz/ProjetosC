/***
 * Estrutura Hierarquica
 * A chave (QUE IDENTIFICA O DADO) determina o comportamento da estrutura
* Ha dois tipos de heap
* ->heap maximo
* ->heap minino
* 
* heap sort
* metodo de ordenacao usando o heap
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100


struct heap
{
    int lista_ord[MAX];
    int lista[MAX];
    int cont;
    int cont_ord;
};
typedef struct heap tipo_heap;

tipo_heap* iniciar_heap();
void inserir(tipo_heap*,int);
void sobe_heap(tipo_heap*,int);
void desce_heap(tipo_heap*,int);
void remove_raiz_ord(tipo_heap*);

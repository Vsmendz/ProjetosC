/***
 * aula sobre pilha dinamica criada em c 
 * alocacao dinamica
 * ufmt-17/02/25
 * 
 * >empilhar
 * -verificar se pilha esta vazia 
 * --se sim, aloca um novo no de pilha
 * -
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef __PILHA_DIN_H__
#define __PILHA_DIN_H__

struct pilha_din
{
    int valor;
    struct pilha_din *no;
};
typedef struct pilha_din pilha_dado;

pilha_dado* alocar_no(int);
void empilhar(int,pilha_dado**);
void desempilhar(pilha_dado**);
void print(pilha_dado*);
int rec_print(pilha_dado*);
#endif
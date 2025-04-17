#ifndef __ARVORE_BIN_MULT_H__
#define __ARVORE_BIN_MULT_H__

#include <stdio.h>
#include <stdlib.h>
#define MAX_NO 3

struct dado
{
    int chave;
    char letra;
};
typedef struct dado tipo_dado;
//
struct arvore_bin_mult
{
    tipo_dado folha[MAX_NO];
    int contador;
    struct arvore_bin_mult *vet_prox[MAX_NO+1];
};
typedef struct arvore_bin_mult tipo_arvore;
//
tipo_arvore* aloca_no(char,int);
void insere(tipo_arvore**,char,int);
void ordena(tipo_dado[],char,int);


#endif

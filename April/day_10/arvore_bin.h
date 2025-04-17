#ifndef __ARVORE_BIN_H__
#define __ARVORE_BIN_H__

#include <stdio.h>
#include <stdlib.h>

struct arvore_bin
{
    int valor;
    struct arvore_bin *no_esq;
    struct arvore_bin *no_dir;
};
typedef struct arvore_bin tipo_arvore;

void insere_arvore(tipo_arvore**,int);
void pre_ordem(tipo_arvore*);
void pos_ordem(tipo_arvore*);
void ordem(tipo_arvore*);
void total_no(tipo_arvore*,int*);


#endif
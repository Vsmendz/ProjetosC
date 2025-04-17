#ifndef __FILA_DIN_H__
#define __FILA_DIN_H__

//libs
#include <stdio.h>
#include <stdlib.h>

//estrutura
struct st_fila
{
    int valor;
    struct st_fila *prox;
};
typedef struct st_fila tipo_fila;

//prototipo funcao

tipo_fila *aloc_no(int);
void inserir_fila(tipo_fila**,int);
int remover_fila(tipo_fila**);
int print_primeiro(tipo_fila*);
int print_all(tipo_fila*);

#endif //__FILA_DIN_H__
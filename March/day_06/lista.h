#ifndef __LISTA_H__
#define __LISTA_H__

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct {
    int lista[MAX];
    int count;
} Lista;

void inserirInicio(Lista *, int );
void adicionarFinal(Lista *, int );
void imprimirLista(Lista *);
void bubbleSort(Lista *);
void insertionSort(Lista *);
void shellSort(Lista *);
#endif
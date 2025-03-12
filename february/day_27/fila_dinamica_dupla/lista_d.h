/***
 * lista com encadeamento duplo
 * 27/02/25
 */

#ifndef __LISTA_D_H__
#define __LISTA_D_H__

#include <stdio.h>
#include <stdlib.h>

struct lista_d
{
    int valor;
    struct lista_d *prox,*ant;
};
typedef struct lista_d tipo_lista;

tipo_lista* alocaNo(int);
void inserirIni(tipo_lista**,int);
void inserirFim(tipo_lista**,int);
void inserirId(tipo_lista**,int,int);
void imprimir(tipo_lista*);
tipo_lista* buscar(tipo_lista*,int*);
void removerIni(tipo_lista**);
void removerFim(tipo_lista**);
void removerId(tipo_lista**,int);
void removervalor(tipo_lista**,int);



#endif
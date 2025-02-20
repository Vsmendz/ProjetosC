/***
 * aula sobre lista dinamica em c
 * 20/02/25
 */

#ifndef __LISTA_DIN_H__
#define __LISTA_DIN_H__

#include <stdio.h>
#include <stdlib.h>

struct lista_din
{
    int valor;
    int index;
    struct lista_din *no;
};
typedef struct lista_din tipo_lista;

tipo_lista* aloca_no(int,int);
void inserir_first(tipo_lista**,int);
void inserir_end(tipo_lista**,int);
void inserir_index(tipo_lista**,int,int);
void remover(tipo_lista**);
void imprimir(tipo_lista*);
void buscar_index(tipo_lista*,int);
void buscar_valor(tipo_lista*,int);
void remover_first(tipo_lista**);
void remover_end(tipo_lista**);
void remover_index(tipo_lista**,int);
void remover_valor(tipo_lista**,int);
int contagem(tipo_lista*);

#endif
/***
 * lista circular como encadeamento simples
 * 27/02/25
 */

#ifndef __LISTA_CIRCLE_H__
#define __LISTA_CIRCLE_H__

#include <stdio.h>
#include <stdlib.h>

struct lista_circle
{
    int valor ;
    struct lista_circle *no;
};
typedef struct lista_circle tipo_lista_c;

tipo_lista_c* alocaNo(int);
void giro(tipo_lista_c**,int);
void inserirIn(tipo_lista_c**);
void inserirFim(tipo_lista_c**);



#endif

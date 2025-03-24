/***
 * implementacao da tabela hash
 * aula ufmt 24/03/25
 */

#ifndef __TABELA_HASH_H__
#define __TABELA_HASH_H__

#include <stdlib.h>
#include <stdio.h>
#define TAM 10


struct no_tabela_hash
{
    int chave;
    int valor;
    struct no_tabela_hash *prox;
};
typedef struct no_tabela_hash no_tabela_hash;

struct est_tabela_hash 
{
    no_tabela_hash* tabela_hash[TAM];
};
typedef struct est_tabela_hash est_tabela_hash;


no_tabela_hash* aloca_no(int,int);
int funcao_hash(int);
void iniciar_tabela(est_tabela_hash*);
void inserir_tabela(est_tabela_hash*,int,int);
void remover_tabela(est_tabela_hash*,int);
void buscar_tabela(est_tabela_hash*,int);


#endif
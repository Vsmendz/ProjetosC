#include "arvore_bin_mult.h"

tipo_arvore* aloca_no(char letra,int chave){
    tipo_arvore*novo_no = malloc(sizeof(tipo_arvore));
    novo_no->folha[0].chave = chave;
    novo_no->folha[0].letra = letra;
    novo_no->contador = 1;

    for (int i = 0; i < MAX_NO+1; i++)
    {
        novo_no->vet_prox[i] = NULL;
    }
    return novo_no;
}

void insere(tipo_arvore**arv,char letra,int chave){
    if ((*arv) == NULL)
    {
        (*arv) = aloca_no(letra,chave);
        return;
    }

    if ((*arv)->contador < MAX_NO)
    {
        char temp_letra = letra;
        int temp_chave = chave;
        for (int i = 0; i < (*arv)->contador; i++)
        {
            if ((*arv)->folha[i].chave > temp_chave)
            {
                temp_letra = (*arv)->folha[i].letra;
                temp_chave = (*arv)->folha[i].chave;

                (*arv)->folha[i].letra = letra;
                (*arv)->folha[i].chave = chave;
            }
        }
        (*arv)->folha[(*arv)->contador].letra = letra;
        (*arv)->folha[(*arv)->contador++].chave = chave;    
    }else{
        int posicao = 0;
        int j = 0;
        while (chave > (*arv)->folha[j].chave && j < (*arv)->contador)
        {
            posicao++;
            j++;
        }
        insere(&(*arv)->vet_prox[posicao],letra,chave);
    }
}

void pre_ordem(tipo_arvore*arv,int nivel,int id_filho){
    if (arv == NULL) return;
    
    for (int i = 0; i < arv->contador; i++)
    {
        printf("chave:[%d] letra:[%c] nivel:[%d] filho:[%d]\n",arv->folha[i].chave,arv->folha[i].letra,nivel,id_filho+1);
    }
    for (int i = 0; i < MAX_NO + 1; i++)
    {
        pre_ordem(arv->vet_prox[i],nivel+1,i);
    }   
}

void pos_ordem(tipo_arvore*arv,int nivel,int id_filho){
    if (arv == NULL) return;

    for (int i = 0; i < MAX_NO + 1; i++)
    {
        pos_ordem(arv->vet_prox[i],nivel+1,i);
    }   
    for (int i = 0; i < arv->contador; i++)
    {
        printf("chave:[%d] letra:[%c] nivel:[%d] filho:[%d]\n",arv->folha[i].chave,arv->folha[i].letra,nivel,id_filho+1);
    }
}

void ordem(tipo_arvore*arv){
    if (arv == NULL) return;

    for (int i = 0; i < arv->contador ; i++)
    {
        ordem(arv->vet_prox[i]);
        printf("chave:[%d] letra:[%c]\n",arv->folha[i].chave,arv->folha[i].letra);
    }
    ordem(arv->vet_prox[arv->contador]);
}

int total_no(tipo_arvore*arv,int total){
    if (arv == NULL) return 0 ;
    for (int i = 0; i < arv->contador+1; i++)
    {
        total_no(arv->vet_prox[i],total);
        return total + arv->contador;
    }
    return total;
}
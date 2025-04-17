#include "arvore_bin.h"

void insere_arvore(tipo_arvore **arv, int valor) {
    if ((*arv) == NULL) {
        tipo_arvore *novo_no = malloc(sizeof(tipo_arvore));
        novo_no->no_dir = NULL;
        novo_no->no_esq = NULL;
        novo_no->valor = valor;
        (*arv) = novo_no; // Atualiza o ponteiro 

    } else {
        if ((*arv)->valor > valor) {
            insere_arvore(&(*arv)->no_esq, valor); // Passa o endereço do ponteiro esquerdo
        } else {
            insere_arvore(&(*arv)->no_dir, valor); // Passa o endereço do ponteiro direito
        }
    }
}

void pre_ordem(tipo_arvore* arv){
    printf("[%d]",arv->valor);
    if (arv->no_esq != NULL)
    {
        pre_ordem(arv->no_esq);
    }if (arv->no_dir != NULL)
    {
        pre_ordem(arv->no_dir);
    }
}
void pos_ordem(tipo_arvore* arv){
    if (arv->no_esq != NULL)
    {
        pos_ordem(arv->no_esq);
    }if (arv->no_dir != NULL)
    {
        pos_ordem(arv->no_dir);
    }
    printf("[%d]",arv->valor);
}

void ordem(tipo_arvore* arv){
    if (arv->no_esq != NULL)
    {
        ordem(arv->no_esq);
    }
    printf("[%d]",arv->valor);
    if (arv->no_dir != NULL)
    {
        ordem(arv->no_dir);
    }
}

void total_no(tipo_arvore *arv,int *total){
    if (arv->no_esq != NULL)
    {
        total_no(arv->no_esq,total);
    }if (arv->no_dir != NULL)
    {
        total_no(arv->no_dir,total);
    }
    (*total)++;
}

void total_folha(tipo_arvore *arv,int*total){
    if (arv->no_esq != NULL) total_folha(arv->no_esq,total);
    if (arv->no_dir != NULL) total_folha(arv->no_dir,total);

    if (arv->no_esq == NULL && arv->no_dir == NULL) (*total)++;
}

tipo_arvore* busca_no(tipo_arvore* arv, int valor) {
    if (arv == NULL || arv->valor == valor) {
        return arv;
    }

    tipo_arvore* no_buscado = busca_no(arv->no_esq, valor);
    if (no_buscado != NULL) {
        return no_buscado;
    }

    return busca_no(arv->no_dir, valor);
}

void verificar_no(tipo_arvore*arv){
    if (arv->no_esq == NULL && arv->no_dir == NULL)
    {
        printf("\no no encontrado é folha [%d]\n",arv->valor);
        return;
    }
    printf("\no no encontrado nao é folha [%d]\n",arv->valor);
}

int altura_arvore(tipo_arvore *arv) {
    if (arv == NULL) {
        return -1;  // Árvore vazia tem altura -1 (ou 0, dependendo da definição)
    }
    
    int altura_esq = altura_arvore(arv->no_esq);
    int altura_dir = altura_arvore(arv->no_dir);
    
    // Retorna a maior altura entre as subárvores + 1 (nó atual)
    return (altura_esq > altura_dir ? altura_esq : altura_dir) + 1;
}

int quant_no_nivel(tipo_arvore*arv,int nivel){
    if (nivel == 0)
    {
        if (arv == NULL)
        {
            return 0;
        }else{
            return 1;
        }
    }
    return quant_no_nivel(arv->no_esq,nivel - 1) + quant_no_nivel(arv->no_dir,nivel-1);
}

void imprime_por_nivel(tipo_arvore*arv,int nivel){
    if (nivel == 0)
    {
        if (arv == NULL)
        {
            return;
        }else{
            printf("[%d]",arv->valor);
            return;
        }
    }
    imprime_por_nivel(arv->no_esq,nivel-1);
    imprime_por_nivel(arv->no_dir,nivel-1);
}

tipo_arvore* menor_no(tipo_arvore*arv){
    tipo_arvore* no = NULL;
    if (arv->no_esq != NULL)
    {
        no = menor_no(arv->no_esq);
        return no;
    }
    no = arv;
    return no;
}

tipo_arvore* maior_no(tipo_arvore*arv){
    tipo_arvore* no = NULL;
    if (arv->no_dir != NULL)
    {
        no = maior_no(arv->no_dir);
        return no;
    }
    no = arv;
    return no;
}

void imprimir_rota_no(tipo_arvore *arv, int chave) {
    if (arv == NULL) {
        printf("Valor %d nao encontrado na arvore.\n", chave);
        return;
    }

    printf("[RAIZ: %d]", arv->valor);

    while (arv != NULL) {
        if (chave == arv->valor) {
            printf(" -> [ENCONTRADO]\n");
            return;
        } else if (chave < arv->valor) {
            arv = arv->no_esq;
            if (arv) printf(" -> [ESQ: %d]", arv->valor);
        } else {
            arv = arv->no_dir;
            if (arv) printf(" -> [DIR: %d]", arv->valor);
        }
    }

    printf(" -> [NAO ENCONTRADO]\n");
}

tipo_arvore* remocao(tipo_arvore*arv,int chave){
    if (arv == NULL)
    {
        return NULL;
    }    
    if (chave < arv->valor)
    {
        arv->no_esq = remocao(arv->no_esq,chave);
    }else if (chave > arv->valor)
    {
        arv->no_dir = remocao(arv->no_dir,chave);
    }else{
        if (arv->no_esq == NULL && arv->no_dir == NULL)
        {
            free(arv);
            arv = NULL;
        }else if (arv->no_esq == NULL && arv->no_dir != NULL)
        {
            tipo_arvore*temp = arv;
            arv = arv->no_dir;
            free(temp);
        }else if (arv->no_esq != NULL && arv->no_dir == NULL)
        {
            tipo_arvore*temp = arv;
            arv = arv->no_esq;
            free(temp);
        }else{
            tipo_arvore*temp = maior_no(arv->no_esq);
            arv->valor = temp->valor;
            arv->no_esq = remocao(arv->no_esq,temp->valor);
            free(temp);
        }
     return arv;   
    }
}


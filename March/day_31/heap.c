#include "heap.h"
tipo_heap* iniciar_heap(){
    tipo_heap* th = malloc(sizeof(tipo_heap));
    int i;
    for (i = 0; i < MAX; i++)
    {
        th->lista[i] = -1; //indica que o espaco esta vazio
    }
    th->cont = 0;
    return th;
}

void inserir(tipo_heap* th,int valor){
    if (th->cont == 100)
    {
        return;
    }
    th->lista[th->cont++] = valor;
    sobe_heap(th,th->cont-1);
}

void sobe_heap(tipo_heap*th,int id){
    int p = (id-1)/2;
    if (id > 0)
    {
        if (th->lista[id] > th->lista[p])
        {
            int aux = th->lista[p];
            th->lista[p] = th->lista[id];
            th->lista[id] = aux;
            sobe_heap(th,p); 
        }
    }
}

void remove_raiz(tipo_heap*th){
    if (th->cont == 0)
    {
        return;
    }
    th->lista[0] = th->lista[th->cont-1];
    th->lista[th->cont-1] = -1;
    th->cont--;
    desce_heap(th,0);
}

void desce_heap(tipo_heap* th,int id){
    int fi_esq = (id*2) + 1; 
    int fi_dir = (id*2) + 2;
    if (th->lista[fi_esq]!= -1)
    {
        if (th->lista[0] < th->lista[fi_esq])
        {
            int temp = th->lista[fi_esq];
            th->lista[fi_esq] = th->lista[0];
            th->lista[0] = temp;
            desce_heap(th,fi_esq);
        }
    }
    if (th->lista[fi_dir]!= -1)
    {
        if (th->lista[0] < th->lista[fi_dir])
        {
            int temp = th->lista[fi_dir];
            th->lista[fi_dir] = th->lista[0];
            th->lista[0] = temp;
            desce_heap(th,fi_dir);
        }
    }
}
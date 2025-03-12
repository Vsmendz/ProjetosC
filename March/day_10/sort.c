#include "sort.h"

void merge(int *vetor, int esquerda, int meio, int direita) {
    int i, j, k;
    int tamanho1 = meio - esquerda + 1;
    int tamanho2 = direita - meio;

    int *esquerdaArr = (int *)malloc(tamanho1 * sizeof(int));
    int *direitaArr = (int *)malloc(tamanho2 * sizeof(int));

    for (i = 0; i < tamanho1; i++)
        esquerdaArr[i] = vetor[esquerda + i];
    for (j = 0; j < tamanho2; j++)
        direitaArr[j] = vetor[meio + 1 + j];

    i = 0;
    j = 0;
    k = esquerda;
    while (i < tamanho1 && j < tamanho2) {
        if (esquerdaArr[i] <= direitaArr[j]) {
            vetor[k] = esquerdaArr[i];
            i++;
        } else {
            vetor[k] = direitaArr[j];
            j++;
        }
        k++;
    }

    while (i < tamanho1) {
        vetor[k] = esquerdaArr[i];
        i++;
        k++;
    }

    while (j < tamanho2) {
        vetor[k] = direitaArr[j];
        j++;
        k++;
    }

    free(esquerdaArr);
    free(direitaArr);
}

void merge_sort(int *vetor, int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        merge_sort(vetor, esquerda, meio);
        merge_sort(vetor, meio + 1, direita);
        merge(vetor, esquerda, meio, direita);
    }
}
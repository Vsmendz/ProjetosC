#include "sort.h"

int main() {
    int vetor[] = {38, 27, 43, 3, 9, 82, 10,9};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int i;

    printf("original:\n");

    for (i = 0; i < 8; i++)
    {
        printf("[%d]",vetor[i]);
    }
    
    printf("\n");

    merge_sort(vetor, 0,8);
    printf("ordenado:\n");

    for (i = 0; i < 8; i++)
    {
        printf("[%d]",vetor[i]);
    }
    
    return 0;
}
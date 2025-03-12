/**
 * UFMT CIÊNCIAS DA COMPUTAÇÃO 
 * ESTRUTURA DE DADOS 1
 * Funções Lista
 * Aula 6 10/02/25
 */

#include "lista.h"

void inserirInicio(Lista *l, int valor) {
    if (l->count >= MAX) {
        printf("Erro: Lista cheia, não é possível inserir no início.\n");
        return;
    }

    for (int i = l->count; i > 0; i--) {
        l->lista[i] = l->lista[i - 1];
    }

    l->lista[0] = valor;
    l->count++;
    printf("Elemento %d inserido no início.\n", valor);
}

void adicionarFinal(Lista *l, int valor) {
    if (l->count < MAX) {
        l->lista[l->count] = valor;
        l->count++;
        printf("Elemento %d adicionado ao final.\n", valor);
    } else {
        printf("Erro: A lista está cheia, não é possível adicionar ao final.\n");
    }
}


void imprimirLista(Lista *l) {
    if (l->count == 0) {
        printf("A lista está vazia.\n");
        return;
    }

    printf("Lista atual: ");
    for (int i = 0; i < l->count; i++) {
        printf("%d ", l->lista[i]);
    }
    printf("\n");
}

void bubbleSort(Lista *l) {
    if (l->count == 0) {
        printf("A lista está vazia, nada para ordenar.\n");
        return;
    }

    for (int i = 0; i < l->count - 1; i++) {
        for (int j = 0; j < l->count - 1 - i; j++) {
            if (l->lista[j] > l->lista[j + 1]) {
                // Troca os elementos se estiverem fora de ordem
                int temp = l->lista[j];
                l->lista[j] = l->lista[j + 1];
                l->lista[j + 1] = temp;
            }
        }
    }
    printf("Lista ordenada com Bubble Sort.\n");
}

void insertionSort(Lista *l) {
    if (l->count == 0) {
        printf("A lista está vazia, nada para ordenar.\n");
        return;
    }

    for (int i = 1; i < l->count; i++) {
        int chave = l->lista[i];
        int j = i - 1;

        // Move os elementos maiores que a chave uma posição à frente
        while (j >= 0 && l->lista[j] > chave) {
            l->lista[j + 1] = l->lista[j];
            j--;
        }
        l->lista[j + 1] = chave;
    }

    printf("Lista ordenada com Insertion Sort.\n");
}

void shellSort(Lista *l) {
    if (l->count == 0) {
        printf("A lista está vazia, nada para ordenar.\n");
        return;
    }

    // Definição do intervalo inicial (gap)
    for (int gap = l->count / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < l->count; i++) {
            int temp = l->lista[i];
            int j;
            
            // Move os elementos em intervalos de "gap"
            for (j = i; j >= gap && l->lista[j - gap] > temp; j -= gap) {
                l->lista[j] = l->lista[j - gap];
            }
            l->lista[j] = temp;
        }
    }

    printf("Lista ordenada com Shell Sort.\n");
}

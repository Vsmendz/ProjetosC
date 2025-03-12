/***
 * aula 10/03/2025
 */

#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *vetor, int esquerda, int direita);
void merge(int *vetor, int esquerda, int meio, int direita);
#endif
#include <stdio.h>
#include <stdlib.h>
#include "algoritmos_busca.h"

int BuscaSequencial(int *array, int tamanho, int busca, int *passos) {
    for (int i = 0; i < tamanho; i++) {
        (*passos)++;
        if (array[i] == busca) {
            return i;
        }
    }
    return -1;
}
#include <stdio.h>
#include "algoritmos_busca.h"

int BuscaBinaria(int *array, int valor, int inicio, int fim, int *passos) {
    if (fim < inicio) return -1;

    int meio = (inicio + fim) / 2;
    (*passos)++;

    if (array[meio] == valor) {
        return meio;
    } else if (valor < array[meio]) {
        return BuscaBinaria(array, valor, inicio, meio - 1, passos);
    } else {
        return BuscaBinaria(array, valor, meio + 1, fim, passos);
    }
}

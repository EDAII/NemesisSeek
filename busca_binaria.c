#include <stdio.h>
#include "algoritmos_busca.h"

int BuscaBinaria(int *array, int busca, int inicio, int fim){
    if (fim < inicio){
        return -1;
    }
    int meio = (inicio+fim)/2;
    if (busca == array[meio]){
        return meio;
    }
    else if(busca < array[meio]){
        return BuscaBinaria(array, busca, inicio, meio - 1);
    }
    return BuscaBinaria(array, busca, meio + 1, fim);
}

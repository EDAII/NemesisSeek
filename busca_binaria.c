#include <stdio.h>
#include <stdlib.h>
#include "busca_binaria.h"

int BuscaBinaria(int *array, int busca, int inicio, int fim){
    
    if (fim < inicio){
        return -1;
    }
    int meio = (inicio+fim)/2;
    if (busca == array[meio]){
        return meio;
    }
    else if(busca < array[meio]){
        fim = meio - 1;
        return BuscaBinaria(array, busca, inicio, fim);
    }
    inicio = meio + 1;
    return BuscaBinaria(array, busca, inicio, fim);
    
}


#include <stdio.h>
#include <stdlib.h>
#include "busca_binaria.h"
int main(){
    int alua[10] = {2,3,4,5,6,7,8,9,10,11};
    int a = BuscaBinaria(alua, 20, 0, 9);
    if(a!=-1){
        printf("Número encontrado na posição %d",a);
    }
    else{
        printf("Número não encontrado");
    }
    return 0;
}
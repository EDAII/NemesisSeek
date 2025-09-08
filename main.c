#include <stdio.h>
#include <stdlib.h>
#include "algoritmos_busca.h"

Registro registros[10] = {
    {1,"Algoritmo1"},
    {2,"Algoritmo2"},
    {3,"Algoritmo3"},
    {4,"Algoritmo4"},
    {5,"Algoritmo5"},
    {6,"Algoritmo6"},
    {7,"Algoritmo7"},
    {8,"Algoritmo8"},
    {9,"Algoritmo9"},
    {10,"Algoritmo10"}
};

int main(){
    Node *tabela[TAM_HASH] = {NULL}; //inicializa hash

    //Preenche a tabela hash
    for(int i=0;i<10;i++){
        inserirHash(tabela, registros[i]);
    }

    //busca binaria
    int ids[10];
    for(int i=0;i<10;i++) ids[i] = registros[i].id;

    int idBusca = 7;
    int pos = BuscaBinaria(ids, idBusca, 0, 9);
    if(pos != -1){
        printf("Encontrado por ID: %s (ID=%d)\n", registros[pos].nome, registros[pos].id);
    } else {
        printf("ID nao encontrado\n");
    }
    char nomeBusca[] = "Algoritmo4";
    Registro *res = buscarHash(tabela, nomeBusca);
    if(res != NULL){
        printf("Encontrado por Nome: %s (ID=%d)\n", res->nome, res->id);
    } else {
        printf("Nome nao encontrado\n");
    }
    return 0;
}
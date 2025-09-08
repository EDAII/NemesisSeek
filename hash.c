#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoritmos_busca.h"

int hash(char *nome){
    int soma = 0;
    for(int i=0; nome[i] != '\0'; i++){
        soma += nome[i];
    }
    return soma % TAM_HASH;
}

void inserirHash(Node *tabela[], Registro r){
    int idx = hash(r.nome);
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->r = r;
    novo->prox = tabela[idx];
    tabela[idx] = novo;
}

Registro* buscarHash(Node *tabela[], char *nome){
    int idx = hash(nome);
    Node *atual = tabela[idx];
    while(atual != NULL){
        if(strcmp(atual->r.nome, nome) == 0){
            return &atual->r;
        }
        atual = atual->prox;
    }
    return NULL;
}

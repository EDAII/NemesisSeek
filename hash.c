#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoritmos_busca.h"

#define A 0.6180339887 // Constante baseada na razão áurea (phi - 1)

int hash(char *nome) {
    unsigned long long int hash = 5381; // numero inicial da hash no algoritmo djb2 
    // O criador do algoritmo djb2 (Daniel J. Bernstein) escolheu 5381 de forma empírica
    // ele testou vários valores e percebeu que 5381 dava boa dispersão e poucas colisões
    // não existe uma razão matemática exata, foi escolhido porque funcionava bem na prática
    int c;
    // obs: O número da hash inicial não é a mesma coisa que o tamanho da tabela hash

    //algoritmo djb2 pra função hash
    while ((c = *nome++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    // Então o djb2 basicamente pega a hash acumulada (acumula a cada letra da string) e multiplica por 33 e soma com a ascii do caractere atual
    
    //O método de baixo, consiste, basicamente, em uma multiplicação com a constante baseada na razão áurea
    double val = hash * A; //ao multiplicar com o golden ratio, bagunça os números da função hash anterior
    double frac = val - (long long)val; // joga fora a parte inteira e só deixa a parte dos decimais
    
    return (int)(TAM_HASH * frac); //Transformacao em indice pra caber no escopo da tabela hash
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

#ifndef ALGORITMOS_BUSCA_H
#define ALGORITMOS_BUSCA_H

#define TAM_HASH 1001   // tamanho da tabela hash

typedef struct {
    int id;
    char nome[20];
} Registro;

// Nó para tratar colisões na hash (encadeamento separado)
typedef struct Node {
    Registro r;
    struct Node *prox;
} Node;

// Funções
int BuscaBinaria(int *array, int busca, int inicio, int fim);

int hash(char *nome);
void inserirHash(Node *tabela[], Registro r);
Registro* buscarHash(Node *tabela[], char *nome);

#endif

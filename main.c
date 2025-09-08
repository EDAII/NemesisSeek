#include <stdio.h>
#include <stdlib.h>
#include "algoritmos_busca.h"

int tam_combinacao;//quantidade de combinações que uma porta possui
typedef struct {
    int combinacao[1000];
    int tamanho;
    int chave;
    int ordenada;
}Porta;


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

Porta criar_porta() {
    Porta p;
    p.tamanho = rand() % tam_combinacao + 3; // tamanho entre 3 e 10
    p.ordenada = rand() % 2; //0 ou 1

    if (ordenada) {
        // gera em ordem crescente direto
        int inicio = rand() % tam_combinacao;  
        int atual = inicio;
    for (int i = 0; i < p.tamanho; i++) {
        p.combinacao[i] = atual;
        atual += rand() % 2679;
    }

    } else {
        // gera bagunçado
        for (int i = 0; i < p.tamanho; i++) {
            p.combinacao[i] = rand() % 50 + 1;
        }
    }
    p.chave = p.combinacao[(rand()%p.tamanho)]
    return p;
}

void Menu(){
    
    int escolha;
    scanf("%d", &escolha);
    if (escolha==1){
        printf("Escolha uma porta: ");
        for (int i = 0; i)
    }
    else if (escolha==2){

    }
    else if (escolha==3){

    }

    else{
        printf("Opção inválida, escolha uma opção válida");
        Menu();
    }
}

void jogo() {
    int distancia_monstro = 2000;
    int total_fases = 3;
    int quantidade_portas = 10
    int rodadas_

    for(int fase = 1; fase <= total_fases; fase++) {
        printf("Você chegou na fase %d", fase);

        // Criar portas da fase
        Porta portas[quantidade_portas];
        for(int i = 0; i < quantidade; i++){
            portas[i] = criar_porta();
        }

        int portaAberta = 0;
        while(!portaAberta && distancia_monstro > 0) {

            if(distancia_monstro <= 0) {
                printf("O monstro te alcançou! Game Over.\n");
            break;
            printf("O monstro está a %d passos\n", distancia_monstro)
        }
            // Mostrar portas e opções de ação
            printf("Escolha uma opção: ");
            Menu();
            // Aqui você adiciona ações: peek, dica, busca
            // Reduz distancia_monstro a cada ação
            distancia_monstro -= 50; // exemplo

            // Checar se o jogador encontrou a chave
            if(/* jogador encontrou a chave */) {
                printf("Porta %d aberta!\n", escolha);
                portaAberta = 1;
                distancia_monstro += 100; // bônus
            }
        }

    }

    if(distancia_monstro > 0) {
        printf("Parabéns! Você completou todas as fases.\n");
    }
}

int main() {
    Node *tabela[TAM_HASH] = {NULL}; // inicializa hash

    // Preenche a tabela hash
    for(int i=0;i<10;i++){
        inserirHash(tabela, registros[i]);
    }

    // exemplo de 10 ids num vetor
    int ids[10];
    for(int i=0;i<10;i++) ids[i] = registros[i].id;

    int idBusca;
    printf("Você está numa sala secreta e um monstro está 2000 passos atrás de você, precisa encontrar um meio de sair desse labirinto já");
    jogo();

    int pos = BuscaBinaria(ids, idBusca, 0, 9);
    if(pos != -1){
        printf("Encontrado por ID: %s (ID=%d)\n", registros[pos].nome, registros[pos].id);
    } else {
        printf("ID nao encontrado\n");
    }
    char nomeBusca[20];
    printf("Digite o nome para buscar: ");
    scanf("%19s", nomeBusca);

    Registro *res = buscarHash(tabela, nomeBusca);
    if(res != NULL){
        printf("Encontrado por Nome: %s (ID=%d)\n", res->nome, res->id);
    } else {
        printf("Nome nao encontrado\n");
    }

    return 0;
}

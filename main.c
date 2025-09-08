#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algoritmos_busca.h"

#define tam_combinacao 100
#define HASH_SIZE 101

typedef struct {
    int combinacao[tam_combinacao];
    int tamanho;
    int especial;
    int chave;
    int ordenada; // 1 = ordenada, 0 = bagunçada
    int ativa;
} Porta;


// ==================== PORTA ====================

Porta criar_porta() {
    Porta p;
    p.tamanho = tam_combinacao; 
    p.ordenada = rand() % 2;
    
    if (p.ordenada) {
        int atual = rand() % 100;
        for (int i = 0; i < p.tamanho; i++) {
            p.combinacao[i] = atual;
            atual += rand() % 30 + 1;
        }
    } else {
        for (int i = 0; i < p.tamanho; i++) {
            p.combinacao[i] = rand() % 100;
        }
    }
    p.chave = p.combinacao[rand() % p.tamanho];
    return p;
}

int dar_dica(Porta *p, int tipo) {
    int custo = 0;
    if (tipo == 0) {
        if (p->chave % 2 == 0) printf("Dica: A chave é par.\n");
        else printf("Dica: A chave é ímpar.\n");
        custo = 50;
    } 
    else if(tipo == 1) {
        printf("Dica: A chave está entre estes valores: ");
        printf("%d ", p->chave);
        for (int i = 0; i < 10; i++) {
            int idx = rand() % p->tamanho;
            if (p->combinacao[idx] != p->chave) printf("%d ", p->combinacao[idx]);
        }
        printf("\n");
        custo = 100;
    }
    else if(tipo == 2){
        if (p->ordenada) printf("O vetor está ordenado\n");
        else printf("O vetor não está ordenado\n");
        custo = 30;
    }
    else printf("Escolha uma seleção válida\n");
    return custo;
}

int abrir_porta(Porta *p, int *distancia_monstro) {
    
    while (1) {
        printf("\nVocê está na porta. Escolha uma ação:\n");
        printf("1 - Usar busca sequencial\n");
        printf("2 - Usar busca binária\n");
        printf("3 - Usar hash\n");
        printf("4 - Pedir dica\n");
        printf("5 - Voltar para escolher outra porta\n");
        int escolha;
        scanf("%d", &escolha);
        int passos = 0;
        
        if (escolha == 1 || escolha == 2 || escolha == 3) {
            int chute;
            printf("Digite o valor que deseja testar: \n");
            scanf("%d", &chute);

            int pos;
            if (escolha == 1) pos = BuscaSequencial(p->combinacao, p->tamanho, chute, &passos);
            else if (escolha == 2) pos = BuscaBinaria(p->combinacao, chute, 0, p->tamanho - 1, &passos);
            
            if (chute == p->chave && pos != -1 && p->especial) {
                printf("Você encontrou a chave correta!! Você conseguiu mudar de fase!\n");
                p->ativa = 0;
                return 1;
            }
            else if (chute == p->chave && pos != -1 && !p->especial) {
                printf("Você encontrou a chave de uma sala comum!\n");
                p->ativa = 0;   
                return 0;

            }
            else if (pos != -1) {
                printf("Esse valor existe na porta, mas não é a chave correta.\n");
                
            }
            else {
                printf("Esse valor não existe na porta.\n");
            }

            printf("Enquanto você tentava achar a senha da porta, o monstro andou %d passos!\n", passos);
            *distancia_monstro -= passos;
            printf("Distância atual do monstro: %d passos.\n", *distancia_monstro);
        }
        else if (escolha == 4) {
            int tipo;
            printf("Qual tipo de dica? \n 0 - Paridade \n 1 - Conjunto \n 2 - Ordenacao\n");
            scanf("%d", &tipo);
            passos = dar_dica(p, tipo);
            printf("Enquanto você ficava pensando em como desbloquear a porta, o monstro já andou %d passos!\n", passos);
            *distancia_monstro -= passos;
            printf("Distância atual do monstro: %d passos.\n", *distancia_monstro);

        }
        else if (escolha == 5) {
            *distancia_monstro -= 50;
            printf("Você voltou para o corredor... o monstro se aproximou 50 passos!\n");
            printf("Distância atual do monstro: %d passos.\n", *distancia_monstro);

            return 0; // volta para o menu de portas
        }
        else {
            printf("Opção inválida.\n");
        }
    }
}

// ==================== JOGO ====================

void jogo() {
    int distancia_monstro = 2000;
    int total_fases = 3;
    int quantidade_portas = 3;

    for (int fase = 1; fase <= total_fases; fase++) {
        printf("\n=== Fase %d ===\n", fase);
        int porta_especial = rand() % quantidade_portas;
        Porta portas[quantidade_portas];
        for (int i = 0; i < quantidade_portas; i++){
            portas[i] = criar_porta();
            portas[i].ativa = 1;
            if(i==porta_especial){
                portas[i].especial = 1;
            }
            else{
                portas[i].especial = 0;
            }
            
        }
        int portaAberta = 0;

        while (!portaAberta && distancia_monstro > 0) {
            printf("\nO monstro está a %d passos atrás.\n", distancia_monstro);
            printf("Portas disponíveis: ");
            for (int i = 0; i < quantidade_portas; i++) {
                if (portas[i].ativa) {
                    printf("%d ", i+1);
                }
            }
            printf("\nEscolha uma porta: ");

            int escolha;
            scanf("%d", &escolha);
            if (escolha < 1 || escolha > quantidade_portas) {
                printf("Opção inválida.\n");
                continue;
            }

            portaAberta = abrir_porta(&portas[escolha - 1], &distancia_monstro);
            if (!portaAberta) distancia_monstro -= 50;
            else distancia_monstro += 100;
        }

        if (distancia_monstro <= 0) {
            printf("O monstro te alcançou! Game Over.\n");
            return;
        }
    }

    printf("\nParabéns! Você completou todas as fases.\n");
}

// ==================== MAIN ====================

int main() {
    srand(time(NULL));
    printf("Bem-vindo ao jogo do Labirinto e das Portas!\n");
    jogo();
    return 0;
}

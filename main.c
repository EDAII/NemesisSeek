#include <stdio.h>
#include <stdlib.h>
#include "algoritmos_busca.h"
#include <time.h>

#define tam_combinacao 100

typedef struct {
    int combinacao[tam_combinacao];
    int tamanho;
    int chave;
    int ordenada; // 1 = ordenada, 0 = bagunçada
} Porta;

// Cria uma porta com combinações aleatórias
Porta criar_porta() {
    Porta p;
    p.tamanho = tam_combinacao; // 
    p.ordenada = rand() % 2;     // 0 ou 1

    if (p.ordenada) {
        int inicio = rand() % 100;
        int atual = inicio;
        for (int i = 0; i < p.tamanho; i++) {
            p.combinacao[i] = atual;
            atual += rand() % 30 + 1; // sequência crescente
        }
    } else {
        for (int i = 0; i < p.tamanho; i++) {
            p.combinacao[i] = rand() % 100;
        }
    }

    // escolhe aleatoriamente a chave
    p.chave = p.combinacao[rand() % p.tamanho];
    return p;
}

int dar_dica(Porta *p, int tipo) {
    int custo = 0;
    if (tipo == 0) {
        // dica de paridade
        if (p->chave % 2 == 0)
            printf("Dica: A chave é par.\n");
        else
            printf("Dica: A chave é ímpar.\n");
        custo = 50;
    } 
    else if(tipo == 1) {
        // dica de conjunto de candidatos
        printf("Dica: A chave está entre estes valores: ");
        printf("%d ", p->chave); // garante que a chave esteja incluída
        for (int i = 0; i < 10; i++) { //informacoes na tela dps da dica
            int idx = rand() % p->tamanho;
            if (p->combinacao[idx] != p->chave) {
                printf("%d ", p->combinacao[idx]);
            }
        }
        custo = 100;
        printf("\n");
    }
    else if(tipo==2){
        if (p->ordenada){
            printf("O vetor está ordenado\n");
        }
        else{
            printf("O vetor não está ordenado\n");
        }
        custo = 30;
    }
    else{
        printf("Escolha uma seleção válida\n");
    }
    return custo;
}



int abrir_porta(Porta *p) {
    int passos = 0;
    while (1) {
        printf("\nVocê está na porta. Escolha uma ação:\n");
        printf("1 - Usar busca sequencial\n");
        printf("2 - Usar busca binária\n");
        printf("3 - Pedir dica\n");
        printf("4 - Voltar para escolher outra porta\n");
        int escolha;
        scanf("%d", &escolha);

        if (escolha == 1 || escolha == 2) {
            int chute;
            printf("Digite o valor que deseja testar: ");
            scanf("%d", &chute);

            // Executa busca para contar passos, mas só libera se acertar a chave!
            int pos = (escolha == 1)
                ? BuscaSequencial(p->combinacao, p->tamanho, chute, &passos)
                : BuscaBinaria(p->combinacao, chute, 0, p->tamanho - 1, &passos);

            printf("O monstro andou %d passos!\n", passos);

            if (chute == p->chave) {
                printf("Você encontrou a chave correta!! Você está a salvo!\n");
                return 1;
            } else if (pos != -1) {
                printf("Esse valor existe na porta, mas não é a chave correta.\n");
            } else {
                printf("Esse valor não existe na porta.\n");
            }
        }
        else if (escolha == 3) {
            int tipo;
            printf("Qual tipo de dica? 0=Paridade | 1=Conjunto | 2=Ordenacao: ");
            scanf("%d", &tipo);
            passos += dar_dica(p, tipo);
            printf("O monstro andou %d passos!\n", passos);
        }
        else if (escolha == 4) {
            // Volta para o menu de portas
            return 0;
        }
        else {
            printf("Opção inválida.\n");
        }
    }
}



// Função principal do jogo
void jogo() {
    int distancia_monstro = 2000;
    int total_fases = 3;
    int quantidade_portas = 3;

    for (int fase = 1; fase <= total_fases; fase++) {
        printf("\n=== Fase %d ===\n", fase);

        Porta portas[quantidade_portas];
        for (int i = 0; i < quantidade_portas; i++) {
            portas[i] = criar_porta();
        }

        int portaAberta = 0;

        while (!portaAberta && distancia_monstro > 0) {
            printf("\nO monstro está a %d passos atrás.\n", distancia_monstro);
            printf("Escolha uma porta de 1 a %d: ", quantidade_portas);

            int escolha;
            scanf("%d", &escolha);
            if (escolha < 1 || escolha > quantidade_portas) {
                printf("Opção inválida.\n");
                continue;
            }

            portaAberta = abrir_porta(&portas[escolha - 1]);
            if (!portaAberta) {
                distancia_monstro -= 50; // penalidade se não encontrou
            } else {
                distancia_monstro += 100; // bônus se abriu
            }
        }

        if (distancia_monstro <= 0) {
            printf("O monstro te alcançou! Game Over.\n");
            return;
        }
    }

    printf("\nParabéns! Você completou todas as fases.\n");
}

int main() {
    srand(time(NULL)); // inicializa aleatoriedade
    printf("Bem-vindo ao jogo do Labirinto e das Portas!\n");
    jogo();
    return 0;
}

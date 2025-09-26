#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// ====== FUNÇÕES AUXILIARES ======

// Sorteia uma missão e copia para a string do jogador
void atribuirMissao(char* destino, char* missoes[], int totalMissoes) {
    int sorteio = rand() % totalMissoes;
    strcpy(destino, missoes[sorteio]);
    printf("\n");
}

// Mostra todos os territórios no mapa
void exibirMapa(struct Territorio* territorios, int tamanho) {
    printf("\n=== MAPA ===\n");
    for (int i = 0; i < tamanho; i++) {
        printf("TERRITÓRIO %d: %s (Exército %s, Tropas: %d)\n",
               i + 1, territorios[i].nome, territorios[i].cor, territorios[i].tropas);
    }
    printf("\n");
}

// Executa ataque entre dois territórios
void atacar(struct Territorio* atacante, struct Territorio* defensor) {
    int dado_atacante = (rand() % 6) + 1;
    int dado_defensor = (rand() % 6) + 1;

    printf("%s (Atacante) rolou: %d\n", atacante->nome, dado_atacante);
    printf("%s (Defensor) rolou: %d\n", defensor->nome, dado_defensor);

    if (dado_atacante > dado_defensor) {
        printf("Atacante venceu!\n");
        defensor->tropas -= 1;
        if (defensor->tropas <= 0) {
            printf("%s foi conquistado por %s!\n", defensor->nome, atacante->nome);
            strcpy(defensor->cor, atacante->cor);
            defensor->tropas = 1;
        }
    } else if (dado_atacante < dado_defensor) {
        printf("Defensor venceu!\n");
        atacante->tropas -= 1;
        if (atacante->tropas < 0) atacante->tropas = 0;
    } else {
        printf("Empate! Ninguém perde tropa.\n");
    }
}

// Verifica se a missão foi cumprida
int verificarMissao(char* missao, struct Territorio* mapa, int tamanho, char* corJogador) {
    if (strcmp(missao, "Conquistar 3 territorios consecutivos") == 0) {
        for (int i = 0; i < tamanho - 2; i++) {
            if (strcmp(mapa[i].cor, corJogador) == 0 &&
                strcmp(mapa[i+1].cor, corJogador) == 0 &&
                strcmp(mapa[i+2].cor, corJogador) == 0) {
                return 1;
            }
        }
    } else if (strcmp(missao, "Eliminar todas as tropas da cor Verde") == 0) {
        int existeVerde = 0;
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, "Verde") == 0 && mapa[i].tropas > 0) {
                existeVerde = 1;
            }
        }
        if (!existeVerde) return 1;
    } else if (strcmp(missao, "Ter pelo menos 2 tropas em todos os territorios") == 0) {
        int ok = 1;
        for (int i = 0; i < tamanho; i++) {
            if (mapa[i].tropas < 2) {
                ok = 0;
                break;
            }
        }
        if (ok) return 1;
    } else if (strcmp(missao, "Controlar todos os territorios do mapa") == 0) {
        int ok = 1;
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, corJogador) != 0) {
                ok = 0;
                break;
            }
        }
        if (ok) return 1;
    } else if (strcmp(missao, "Não perder nunhuma tropa o jogo inteiro") == 0) {
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, corJogador) == 0 && mapa[i].tropas >= 10) {
                return 1;
            }
        }
    }

    return 0;
}

// ====== PROGRAMA PRINCIPAL ======
int main() {
    srand(time(NULL));
    int num_territorios = 5;

    struct Territorio *territorios = (struct Territorio*) malloc(num_territorios * sizeof(struct Territorio));

    printf("==========================================================\n");
    printf("Vamos cadastrar os %d Territórios iniciais do nosso mundo.\n\n", num_territorios);

    // Cadastro dos territórios
    for (int i = 0; i < num_territorios; i++) {
        printf("--- Cadastrando Território %d ---\n", i + 1);
        printf("Nome do Território: ");
        scanf("%s", territorios[i].nome);
        printf("Cor do Exército: ");
        scanf("%s", territorios[i].cor);
        printf("Número de Tropas: ");
        scanf("%d", &territorios[i].tropas);
        printf("\n");
    }

    exibirMapa(territorios, num_territorios);

    // Missões
    #define NUM_MISSOES 5
    char* missoes[NUM_MISSOES] = {
        "Conquistar 3 territorios consecutivos",
        "Eliminar todas as tropas da cor Verde",
        "Ter pelo menos 2 tropas em todos os territorios",
        "Controlar todos os territorios do mapa",
        "Não perder nunhuma tropa o jogo inteiro"
    };

    char* missaoDoJogador = (char*) malloc(100 * sizeof(char));
    atribuirMissao(missaoDoJogador, missoes, NUM_MISSOES);

    // Guarda cor inicial do jogador para verificar missão
    char corJogador[10];
    strcpy(corJogador, territorios[0].cor);

    // Menu
    int escolha;
    while (1) {
        printf("Sua Missão (exercito %s): %s\n", corJogador, missaoDoJogador);
        printf("--- MENU DE AÇÕES ---\n");
        printf("1 - Atacar\n");
        printf("2 - Verificar Missao\n");
        printf("0 - Sair\n");
        printf("Escolha sua acao: ");
        scanf("%d", &escolha);

        if (escolha == 0) break;
        else if (escolha == 1) {
            int atacante, defensor;
            printf("Escolha o Território atacante (1-%d): ", num_territorios);
            scanf("%d", &atacante);
            printf("Escolha o Território defensor (1-%d): ", num_territorios);
            scanf("%d", &defensor);
            atacar(&territorios[atacante-1], &territorios[defensor-1]);
            exibirMapa(territorios, num_territorios);
        } else if (escolha == 2) {
            if (verificarMissao(missaoDoJogador, territorios, num_territorios, corJogador)) {
                printf("Parabéns! Você cumpriu a missão: %s\n", missaoDoJogador);
                break;
            } else {
                printf("Missão ainda não cumprida. Continue jogando!\n");
            }
        } else {
            printf("Opção inválida!\n");
        }
    }

    free(territorios);
    free(missaoDoJogador);
    return 0;


}
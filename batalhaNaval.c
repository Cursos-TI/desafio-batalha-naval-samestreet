#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3

void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n===== BATALHA NAVAL =====\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tabuleiro[i][j] == 3 ? '#' : '~');
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[0][i] = 3; // horizontal

    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[i][5] = 3; // vertical

    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[5 + i][2 + i] = 3; // diagonal principal

    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[6 + i][8 - i] = 3; // diagonal secundária

    exibirTabuleiro(tabuleiro);
    return 0;
}

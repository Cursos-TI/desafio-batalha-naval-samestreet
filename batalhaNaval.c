#include <stdio.h>
#include <math.h>

#define TAM 10
#define TAM_HAB 5

void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0) printf("0 ");
            else if (tabuleiro[i][j] == 3) printf("3 ");
            else if (tabuleiro[i][j] == 5) printf("5 ");
        }
        printf("\n");
    }
}

void gerarCone(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= TAM_HAB / 2 - i && j <= TAM_HAB / 2 + i)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

void gerarCruz(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

void gerarOctaedro(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int centro = TAM_HAB / 2;
            if (abs(i - centro) + abs(j - centro) <= centro)
                habilidade[i][j] = 1;
            else
                habilidade[i][j] = 0;
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemX, int origemY) {
    int offset = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int x = origemX - offset + i;
            int y = origemY - offset + j;
            if (x >= 0 && x < TAM && y >= 0 && y < TAM && habilidade[i][j] == 1) {
                if (tabuleiro[x][y] == 0)
                    tabuleiro[x][y] = 5;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};
    int tabuleiroCone[TAM][TAM] = {0};
    int tabuleiroCruz[TAM][TAM] = {0};
    int tabuleiroOctaedro[TAM][TAM] = {0};

    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];

    for (int i = 0; i < 3; i++) tabuleiro[0][i] = 3;
    for (int i = 0; i < 3; i++) tabuleiro[i][5] = 3;
    for (int i = 0; i < 3; i++) tabuleiro[5 + i][2 + i] = 3;
    for (int i = 0; i < 3; i++) tabuleiro[6 + i][8 - i] = 3;

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiroCone[i][j] = tabuleiro[i][j];
            tabuleiroCruz[i][j] = tabuleiro[i][j];
            tabuleiroOctaedro[i][j] = tabuleiro[i][j];
        }
    }

    printf("\nBATALHA NAVAL\n");

    printf("\nTABULEIRO PADRAO\n");
    exibirTabuleiro(tabuleiro);

    printf("\nHABILIDADE: CONE\n");
    gerarCone(cone);
    aplicarHabilidade(tabuleiroCone, cone, 2, 2);
    exibirTabuleiro(tabuleiroCone);

    printf("\nHABILIDADE: CRUZ\n");
    gerarCruz(cruz);
    aplicarHabilidade(tabuleiroCruz, cruz, 5, 5);
    exibirTabuleiro(tabuleiroCruz);

    printf("\nHABILIDADE: OCTAEDRO\n");
    gerarCruz(octaedro);
    aplicarHabilidade(tabuleiroOctaedro, octaedro, 8, 3);
    exibirTabuleiro(tabuleiroOctaedro);

    return 0;
}

#include <stdio.h>

#define TAM 10
#define TAM_HAB 5

int mod(int x) {
    return (x >= 0) ? x : -x;
}

void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int linha = origemLinha - TAM_HAB / 2 + i;
                int coluna = origemColuna - TAM_HAB / 2 + j;
                if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM && tabuleiro[linha][coluna] == 0) {
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;
    int tamanho = 3;

    for (i = 0; i < TAM; i++)
        for (j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;

    int lh = 2, ch = 4;
    if (ch + tamanho <= TAM) {
        int ok = 1;
        for (i = 0; i < tamanho; i++) if (tabuleiro[lh][ch + i] != 0) ok = 0;
        if (ok) for (i = 0; i < tamanho; i++) tabuleiro[lh][ch + i] = 3;
    }

    int lv = 5, cv = 7;
    if (lv + tamanho <= TAM) {
        int ok = 1;
        for (i = 0; i < tamanho; i++) if (tabuleiro[lv + i][cv] != 0) ok = 0;
        if (ok) for (i = 0; i < tamanho; i++) tabuleiro[lv + i][cv] = 3;
    }

    int ld1 = 0, cd1 = 0;
    if (ld1 + tamanho <= TAM && cd1 + tamanho <= TAM) {
        int ok = 1;
        for (i = 0; i < tamanho; i++) if (tabuleiro[ld1 + i][cd1 + i] != 0) ok = 0;
        if (ok) for (i = 0; i < tamanho; i++) tabuleiro[ld1 + i][cd1 + i] = 3;
    }

    int ld2 = 1, cd2 = 8;
    if (ld2 + tamanho <= TAM && cd2 - (tamanho - 1) >= 0) {
        int ok = 1;
        for (i = 0; i < tamanho; i++) if (tabuleiro[ld2 + i][cd2 - i] != 0) ok = 0;
        if (ok) for (i = 0; i < tamanho; i++) tabuleiro[ld2 + i][cd2 - i] = 3;
    }

    int cone[TAM_HAB][TAM_HAB] = {0};
    int cruz[TAM_HAB][TAM_HAB] = {0};
    int octaedro[TAM_HAB][TAM_HAB] = {0};

    for (i = 0; i < TAM_HAB; i++)
        for (j = 0; j < TAM_HAB; j++)
            if (j >= (TAM_HAB - 1) / 2 - i && j <= (TAM_HAB - 1) / 2 + i)
                cone[i][j] = 1;

    for (i = 0; i < TAM_HAB; i++) cruz[i][(TAM_HAB - 1) / 2] = 1;
    for (j = 0; j < TAM_HAB; j++) cruz[(TAM_HAB - 1) / 2][j] = 1;

    for (i = 0; i < TAM_HAB; i++)
        for (j = 0; j < TAM_HAB; j++)
            if (mod(i - (TAM_HAB - 1) / 2) + mod(j - (TAM_HAB - 1) / 2) <= (TAM_HAB - 1) / 2)
                octaedro[i][j] = 1;

    aplicarHabilidade(tabuleiro, cone, 7, 2);
    aplicarHabilidade(tabuleiro, cruz, 4, 4);
    aplicarHabilidade(tabuleiro, octaedro, 6, 6);

    printf("Tabuleiro com navios e habilidades:\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0)
                printf("~ ");
            else if (tabuleiro[i][j] == 3)
                printf("N ");
            else if (tabuleiro[i][j] == 5)
                printf("* ");
        }
        printf("\n");
    }

    return 0;
}

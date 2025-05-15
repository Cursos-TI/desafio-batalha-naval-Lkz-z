#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int lh = 2, ch = 4; // horizontal
    int lv = 5, cv = 7; // vertical

    // Tamanho fixo dos navios
    int tamanho = 3;

    if (ch + tamanho <= 10) {
        int ok = 1;
        for (i = 0; i < tamanho; i++) {
            if (tabuleiro[lh][ch + i] != 0) ok = 0;
        }
        if (ok) {
            for (i = 0; i < tamanho; i++) {
                tabuleiro[lh][ch + i] = 3;
            }
        }
    }

    if (lv + tamanho <= 10) {
        int ok = 1;
        for (i = 0; i < tamanho; i++) {
            if (tabuleiro[lv + i][cv] != 0) ok = 0;
        }
        if (ok) {
            for (i = 0; i < tamanho; i++) {
                tabuleiro[lv + i][cv] = 3;
            }
        }
    }

    // Exibe o tabuleiro
    printf("Tabuleiro:\n\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
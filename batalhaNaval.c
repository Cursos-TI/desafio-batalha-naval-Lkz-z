#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int tamanho = 3;

    int lh = 2, ch = 4;
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

    int lv = 5, cv = 7;
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

    int ld1 = 0, cd1 = 0;
    if (ld1 + tamanho <= 10 && cd1 + tamanho <= 10) {
        int ok = 1;
        for (i = 0; i < tamanho; i++) {
            if (tabuleiro[ld1 + i][cd1 + i] != 0) ok = 0;
        }
        if (ok) {
            for (i = 0; i < tamanho; i++) {
                tabuleiro[ld1 + i][cd1 + i] = 3;
            }
        }
    }

    int ld2 = 1, cd2 = 8;
    if (ld2 + tamanho <= 10 && cd2 - (tamanho - 1) >= 0) {
        int ok = 1;
        for (i = 0; i < tamanho; i++) {
            if (tabuleiro[ld2 + i][cd2 - i] != 0) ok = 0;
        }
        if (ok) {
            for (i = 0; i < tamanho; i++) {
                tabuleiro[ld2 + i][cd2 - i] = 3;
            }
        }
    }

    printf("Tabuleiro:\n\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
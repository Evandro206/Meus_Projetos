#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 8

int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

void impressaotabuleiro() {
    int x, y;
    printf("| ||A||B||C||D||E||F||G||H|\n");
    for (x = 0; x < TAMANHO_TABULEIRO; x++) {
        printf("|%d|", x + 1);
        for (y = 0; y < TAMANHO_TABULEIRO; y++) {
            if (tabuleiro[x][y] == 1) {
                printf("|#|");
            } else {
                printf("| |");
            }
        }
        printf("\n");
    }
}

void criacaotabuleiro() {
    int x, y;
    for (x = 0; x < TAMANHO_TABULEIRO; x++) {
        for (y = 0; y < TAMANHO_TABULEIRO; y++) {
            if (x % 2 != 0) {
                if (y % 2 == 0) {
                    tabuleiro[x][y] = 1;
                } else {
                    tabuleiro[x][y] = 0;
                }
            } else {
                if (y % 2 != 0) {
                    tabuleiro[x][y] = 1;
                } else {
                    tabuleiro[x][y] = 0;
                }
            }
        }
    }
    impressaotabuleiro();
}

void posicaoreibranca(int x, int y) { 
    int rodadaatual;
    rodada(&rodadaatual);
    if(rodadaatual == 1){
        x = 5;
        y = 8;
    }
    printf("O rei esta na posicao x = %d e y = %d\n", x, y);
}

void movimentacaorei(int x_atual, int y_atual, int x_destino, int y_destino) {
    int dx = x_destino - x_atual;
    int dy = y_destino - y_atual;

    switch (dx) {
        case -1:
        case 0:
        case 1:
            switch (dy) {
                case -1:
                case 0:
                case 1:
                    tabuleiro[x_destino][y_destino] = tabuleiro[x_atual][y_atual];
                    tabuleiro[x_atual][y_atual] = 0;
                    break;
                default:
                    printf("Movimento invalido.\n");
                    break;
            }
            break;
        default:
            printf("Movimento invalido.\n");
            break;
    }
}

void reibranca() {
    int x = 0, y = 0, dx, dy;
    posicaoreibranca(x, y);
    printf("Digite a posicao de destino para o rei (x y): ");
    scanf("%d %d", &dx, &dy);
    movimentacaorei(x, y, dx, dy);
    printf("O rei esta agora na posicao x = %d e y = %d\n", dx, dy);
}

void reipreta() {
    
}

void rainhabranca() {
    
}

void rainhapreta() {
    
}

void torrebranca() {
    
}

void torrepreta() {
    
}

void bispobranca() {
    
}

void bispopreta() {
    
}

void cavalobranca() {
    
}

void cavalopreta() {
    
}

void peaobranca() {
    
}

void peaopreta() {
    
}

void posicaoinicialpecabranca() {
    reibranca();
    rainhabranca();
    torrebranca();
    bispobranca();
    cavalobranca();
    peaobranca();
}

void posicaoinicialpecapreta() {
    reipreta();
    rainhapreta();
    torrepreta();
    bispopreta();
    cavalopreta();
    peaopreta();
}

void posicaoinicialpeca() {
    posicaoinicialpecabranca();
    posicaoinicialpecapreta();
}

void rodada(int *rodadaatual) {
    (*rodadaatual)++;
}

void iniciojogo() {
    int rodadaatual = 0; 
    while (rodadaatual == 0) {
        criacaotabuleiro();
        posicaoinicialpeca();
        rodada(&rodadaatual); 
    }
}

int main() {
    iniciojogo();
}

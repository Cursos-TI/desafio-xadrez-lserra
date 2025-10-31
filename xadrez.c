//
// Created by Laercio Serra (laercio.serra@gmail.com) on 29/10/2025.
// Desafio de Xadrez - MateCheck
// Niveis: novato, aventureiro e mestre
//
#include <stdio.h>

// Tamanho do tabuleiro
#define TAM 8

// Função auxiliar para imprimir a posição
void imprimirMovimento(const char* peca, int x, int y) {
    if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
        printf(">> %s pode mover para (%d, %d)\n", peca, x, y);
    }
}

// Função recursiva para movimentação do Bispo (nível mestre)
void moverBispoRecursivo(int x, int y, int dx, int dy) {
    if (x < 0 || x >= TAM || y < 0 || y >= TAM) return;
    imprimirMovimento("Bispo (Recursivo)", x, y);
    moverBispoRecursivo(x + dx, y + dy, dx, dy);
}

int main() {
    // Posição inicial das peças
    int x = 3, y = 3;

    // Nível: NOVATO
    printf("\n::: Voce esta no nivel: NOVATO.\n");
    printf("::: Pressione a tecla ENTER para iniciar o jogo . . .\n");
    printf("############################################################\n");
    getchar(); // aguarda qualquer tecla Enter


    // Constantes de movimentação
    const int maxMovimento = TAM - 1;

    // Bispo - movimentação diagonal
    printf("\n** Movimentando o Bispo . . .\n");
    for (int i = 1; i <= maxMovimento; i++) {
        imprimirMovimento("Bispo", x + i, y + i); // diagonal inferior direita
        imprimirMovimento("Bispo", x - i, y - i); // diagonal superior esquerda
        imprimirMovimento("Bispo", x + i, y - i); // diagonal inferior esquerda
        imprimirMovimento("Bispo", x - i, y + i); // diagonal superior direita
    }

    // Torre - movimentação para a direita
    printf("\n** Movimentando a Torre . . .\n");
    for (int i = 1; i <= maxMovimento; i++) {
        imprimirMovimento("Torre", x, y + i);
    }

    // Rainha - movimentação para a esquerda
    printf("\n** Movimentando a Rainha . . .\n");
    for (int i = 1; i <= maxMovimento; i++) {
        imprimirMovimento("Rainha", x, y - i);
    }

    // Nível: AVENTUREIRO
    printf("\n::: Voce passou para o nivel: AVENTUREIRO.\n");
    printf("::: Pressione a tecla ENTER para continuar o jogo . . .\n");
    printf("############################################################\n");
    getchar(); // aguarda qualquer tecla Enter

    // Cavalo - movimentação em L com loops aninhados
    printf("** Movimentando o Cavalo . . .\n");
    for (int dx = -2; dx <= 2; dx++) {
        for (int dy = -2; dy <= 2; dy++) {
            if ((dx * dx + dy * dy) == 5) {
                imprimirMovimento("Cavalo", x + dx, y + dy);
            }
        }
    }

    // Nível: MESTRE
    printf("\n::: Voce passou para o nivel: MESTRE.\n");
    printf("::: Pressione a tecla ENTER para continuar o jogo . . .\n");
    printf("############################################################\n");
    getchar(); // aguarda qualquer tecla Enter

    // Bispo com função recursiva
    printf("** Movimentando o Bispo (recursivamente) . . .\n");
    moverBispoRecursivo(x + 1, y + 1, 1, 1); // diagonal inferior direita
    moverBispoRecursivo(x - 1, y - 1, -1, -1); // diagonal superior esquerda
    moverBispoRecursivo(x + 1, y - 1, 1, -1); // diagonal inferior esquerda
    moverBispoRecursivo(x - 1, y + 1, -1, 1); // diagonal superior direita

    // Cavalo com controle avançado usando break para abandonar o sistema
    printf("\n** Movimentando o Cavalo (com break/continue) . . .\n");

    int abandonar = 0;

    for (int dx = -2; dx <= 2 && !abandonar; dx++) {
        for (int dy = -2; dy <= 2; dy++) {
            if ((dx * dx + dy * dy) != 5) {
                printf(">> Movimento invalido (%d, %d) - nao e um L!\n", dx, dy);
                abandonar = 1;
                break;
            }

            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= TAM || ny < 0 || ny >= TAM) {
                printf(">> Movimento invalido (%d, %d) - fora do tabuleiro!\n", nx, ny);
                abandonar = 1;
                break;
            }

            imprimirMovimento("Cavalo (Avancado)", nx, ny);
        }
}

    printf("\n===> GAME OVER!\n");

    return 0;
}

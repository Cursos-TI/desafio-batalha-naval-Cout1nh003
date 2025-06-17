#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

/*
  Desafio MateCheck - Batalha Naval: Posicionamento com Coordenadas
  Autor: [Seu Nome Aqui]

  Objetivo:
  - Criar um tabuleiro 10x10
  - Posicionar dois navios (um horizontal e um vertical)
  - Mostrar as coordenadas de cada parte dos navios
*/

// Função para exibir as coordenadas ocupadas por um navio
void exibirCoordenadas(char* tipo, int coords[][2], int tamanho) {
    printf("Coordenadas do navio %s:\n", tipo);
    for (int i = 0; i < tamanho; i++) {
        printf("(%d, %d)\n", coords[i][0], coords[i][1]);
    }
    printf("\n");
}

int main() {
    // Tabuleiro 10x10 inicializado com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios
    int linha_horizontal = 2, coluna_horizontal = 4;
    int linha_vertical = 5, coluna_vertical = 1;

    // Vetores para armazenar as coordenadas dos navios
    int coords_horizontal[TAMANHO_NAVIO][2];
    int coords_vertical[TAMANHO_NAVIO][2];

    // Posiciona o navio horizontal (3 casas)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int x = linha_horizontal;
        int y = coluna_horizontal + i;

        tabuleiro[x][y] = NAVIO;
        coords_horizontal[i][0] = x;
        coords_horizontal[i][1] = y;
    }

    // Posiciona o navio vertical (3 casas)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int x = linha_vertical + i;
        int y = coluna_vertical;

        // Verifica se já existe outro navio na posição (evita sobreposição)
        if (tabuleiro[x][y] == AGUA) {
            tabuleiro[x][y] = NAVIO;
            coords_vertical[i][0] = x;
            coords_vertical[i][1] = y;
        } else {
            printf("Erro: Sobreposição de navios nas coordenadas (%d, %d)\n", x, y);
        }
    }

    // Exibir as coordenadas dos navios
    exibirCoordenadas("Horizontal", coords_horizontal, TAMANHO_NAVIO);
    exibirCoordenadas("Vertical", coords_vertical, TAMANHO_NAVIO);

    return 0;
}

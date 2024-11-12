#include <stdio.h>

// QUESTÃO CORRIGIDA (NÃO CONSEGUI FAZER A QUESTÃO CORRETA NA PROVA)

/*--------------------------------------------------------------------------*/
// Função multiplicar_matrizes
// Realiza a multiplicação de duas matrizes quadradas e armazena o resultado.
/*--------------------------------------------------------------------------*/
void multiplicar_matrizes(int N, double A[N][N], double B[N][N], double resultado[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultado[i][j] = 0.0;
            for (int k = 0; k < N; k++) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

/*----------------------------------------------------------------------*/
// Função copiar_matriz
// Copia os elementos de uma matriz de origem para uma matriz de destino.
/*----------------------------------------------------------------------*/
void copiar_matriz(int N, double origem[N][N], double destino[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            destino[i][j] = origem[i][j];
        }
    }
}

/*------------------------------------------------------------------------*/
// Função elevar_matriz
// Eleva uma matriz quadrada à potência k usando multiplicações sucessivas.
// Utiliza uma matriz identidade como base para realizar as multiplicações.
/*------------------------------------------------------------------------*/
void elevar_matriz(int N, double matriz[N][N], int k) {
    double resultado[N][N];
    double temp[N][N];
    
    // Inicializar resultado como matriz identidade (uma matriz vezes sua identidade é igual a ela mesma)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            resultado[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }
    
    // Elevar a matriz à potência k
    for (int i = 0; i < k; i++) {
        multiplicar_matrizes(N, resultado, matriz, temp);
        copiar_matriz(N, temp, resultado);
    }
    
    // Copiar o resultado final de volta para a matriz original
    copiar_matriz(N, resultado, matriz);
}

/*------------------------------------------------------------------------*/
// Função principal
// Lê a dimensão e os elementos de uma matriz, eleva a matriz à potência k,
// e imprime o resultado com três casas decimais.
/*------------------------------------------------------------------------*/
int main() {
    int N, k;
    scanf("%d %d", &N, &k);
    
    double matriz[N][N];
    
    // Ler a matriz
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }
    
    // Elevar a matriz à potência k
    elevar_matriz(N, matriz, k);
    
    // Imprimir a matriz resultante com 3 casas decimais
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.3f ", matriz[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
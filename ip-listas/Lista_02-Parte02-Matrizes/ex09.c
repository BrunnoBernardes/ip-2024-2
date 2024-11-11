#include <stdio.h>

#define MAX_L 100 // Largura máxima da matriz

/*---------------------------------------------------------------------------------------*/
// Calcula o traço de uma matriz quadrada e multiplica cada elemento da matriz pelo traço
/*---------------------------------------------------------------------------------------*/
void traco_matriz(int N, int matriz[MAX_L][MAX_L], int matriz_final[MAX_L][MAX_L])
{
    int traco = 0;
    int i, j;

    // Calcula o traço (soma dos elementos da diagonal principal)
    for (i = 0; i < N; i++)
    {
        traco += matriz[i][i];
    }

    // Multiplica cada elemento da matriz pelo traço e armazena em matriz_final
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            matriz_final[i][j] = matriz[i][j] * traco;
        }
    }
}

/*----------------------------------------------------------------*/
// Calcula a transposta da matriz e soma os valores na matriz final.
/*----------------------------------------------------------------*/
void transposta_matriz(int N, int matriz[MAX_L][MAX_L], int matriz_final[MAX_L][MAX_L])
{
    int i, j;

    // Transpõe a matriz e acumula o valor na matriz_final
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            matriz_final[i][j] += matriz[j][i];
        }
    }
}

/*------------*/
// Função main
/*------------*/
int main()
{
    int N, matriz[MAX_L][MAX_L], matriz_final[MAX_L][MAX_L] = {0};
    int i, j;

    // Lê a dimensão da matriz
    scanf("%d", &N);

    // Lê os elementos da matriz de entrada
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    traco_matriz(N, matriz, matriz_final);    // Calcula traço * matriz e armazena em matriz_final
    transposta_matriz(N, matriz, matriz_final); // Adiciona a transposta à matriz_final

    // Imprime a matriz final resultante
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", matriz_final[i][j]);
        }
        printf("\n");
    }

    return 0;
}

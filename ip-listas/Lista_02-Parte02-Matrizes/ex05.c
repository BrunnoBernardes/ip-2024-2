#include <stdio.h>

#define MAX 6 // Tamanho máximo da matriz

/*-------------------------------------------------------------------------------------------------------*/
// Calcula a soma de todas as possíveis "ampulhetas" em uma matriz 6x6 e armazena a maior soma encontrada.
/*-------------------------------------------------------------------------------------------------------*/

void verificacao_ampulheta (int M[][MAX], int *ampulheta_maior)
{
    int i, j, soma = -63;

    // Percorre a matriz até a posição limite para formar uma ampulheta
    for (i = 0; i < MAX - 2; i++)
    {
        for (j = 0; j < MAX - 2; j++)
        {
            soma = M[i][j] + M[i][j + 1] + M[i][j + 2] + M[i + 1][j + 1] + M[i + 2][j] + M[i + 2][j + 1] + M[i + 2][j + 2];

            // Atualiza o valor de ampulheta_maior se a soma atual for maior
            if (soma > *ampulheta_maior)
            {
                *ampulheta_maior = soma;
            }
        }
    }
}

/*------------*/
// Função main
/*------------*/

int main ()
{
    int i, j;
    int M[MAX][MAX], ampulheta_maior = -63;

    // Lê os elementos da matriz 6x6
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            scanf("%d", &M[i][j]);
        }
    }

    verificacao_ampulheta(M, &ampulheta_maior);

    printf("%d\n", ampulheta_maior);

    return 0;
}
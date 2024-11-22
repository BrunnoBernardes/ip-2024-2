#include <stdio.h>

#define MAX 1000 // Largura máxima da matriz

/*-------------------------------------------------------------*/ 
// Função que ordena as colunas de uma matriz em ordem crescente
/*-------------------------------------------------------------*/
void ordena_colunas(int A[MAX][MAX], int n)
{
    int i, j, k;
    int aux;

    // Loop para ordenar cada coluna da matriz
    for (j = 0; j < n; j++) // Percorre as colunas
    {
        for (i = 0; i < n - 1; i++) // Percorre as linhas para encontrar os menores elementos
        {
            for (k = i + 1; k < n; k++) // Compara a linha atual com as linhas abaixo
            {
                if (A[i][j] > A[k][j]) // Troca os valores se estiverem fora de ordem
                {
                    aux = A[i][j];
                    A[i][j] = A[k][j];
                    A[k][j] = aux;
                }
            }
        }
    }

    // Imprime a matriz após a ordenação das colunas
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

/*-----------------*/ 
// Função Principal
/*-----------------*/
int main()
{
    int i, j;
    int n, A[MAX][MAX];

    scanf("%d", &n);

    // Lê os elementos da matriz
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    // Chama a função para ordenar as colunas da matriz
    ordena_colunas(A, n);

    return 0;
}
#include <stdio.h>

#define MAX 10 // Largura máxima da matriz

/*---------------------------------------------------------------------------*/
// Função verificar_bissimetria
// Verifica se a matriz é bissimétrica (ou seja, se é igual à sua transposta).
// Imprime "bissimetrica" se for, ou "nao bissimetrica" caso contrário.
/*---------------------------------------------------------------------------*/
void verificar_bissimetria(int matriz[MAX][MAX], int bis_matriz[MAX][MAX], int n)
{
    int i, j;
    int bissimetrica = 1; // Assume inicialmente que a matriz é bissimétrica

    // Compara cada elemento da matriz com o elemento correspondente em sua transposta
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (matriz[i][j] != bis_matriz[i][j])
            {
                bissimetrica = 0; // Define como não bissimétrica se houver diferença
                break;
            }
        }
        if (!bissimetrica)
        {
            break;
        }
    }

    // Imprime o resultado da verificação de bissimetria
    if (bissimetrica)
    {
        printf("bissimetrica\n");
    }
    else
    {
        printf("nao bissimetrica\n");
    }
}

/*----------------------------------------------------------------------------------*/
// Função principal
// Lê uma matriz quadrada e cria sua transposta, depois verifica se ambas são iguais.
/*----------------------------------------------------------------------------------*/
int main ()
{
    int i, j;
    int n;
    int matriz[MAX][MAX], bis_matriz[MAX][MAX];

    // Lê a dimensão da matriz
    scanf("%d", &n);

    // Verifica se a dimensão está dentro do limite permitido
    if (n > MAX || n < 1)
    {
        printf("dimensao invalida\n");
        return 0;
    }

    // Lê os elementos da matriz e gera a matriz transposta
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matriz[i][j]);
            bis_matriz[j][i] = matriz[i][j]; // Cria a transposta
        }
    }

    // Verifica e imprime se a matriz é bissimétrica
    verificar_bissimetria(matriz, bis_matriz, n);

    return 0;
}

#include <stdio.h>

#define MAX 10 // Largura máxima da matriz

/*------------------------------------------------------*/
// Função lendo_elementos
// Copia os elementos de uma matriz para um array linear.
/*------------------------------------------------------*/
void lendo_elementos(int matriz[MAX][MAX], int N, int M, int elementos[MAX * MAX])
{
    int i, j, k = 0;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            elementos[k] = matriz[i][j];
            k++;
        }
    }
}

/*-------------------------------------------------------------------------*/
// Função freq_menor
// Calcula o valor mínimo em um array e a frequência percentual desse valor.
/*-------------------------------------------------------------------------*/
void freq_menor(int elementos[MAX * MAX], int tam)
{
    int i, j, menor, freq_menor = 0;

    // Encontra o menor valor no array
    menor = elementos[0];
    for (i = 0; i < tam; i++)
    {
        if (elementos[i] < menor)
        {
            menor = elementos[i];
        }
    }

    // Conta a frequência do menor valor
    for (j = 0; j < tam; j++)
    {
        if (elementos[j] == menor)
        {
            freq_menor++;
        }
    }

    // Calcula a frequência percentual do menor valor
    freq_menor = freq_menor * 100;

    printf("%d ", menor);
    printf("%.2lf%%\n", (double)freq_menor / tam);
}

/*-------------------------------------------------------------------------*/
// Função freq_maior
// Calcula o valor máximo em um array e a frequência percentual desse valor.
/*-------------------------------------------------------------------------*/
void freq_maior(int elementos[MAX * MAX], int tam)
{
    int i, j, maior, freq_maior = 0;

    // Encontra o maior valor no array
    maior = elementos[0];
    for (i = 0; i < tam; i++)
    {
        if (elementos[i] > maior)
        {
            maior = elementos[i];
        }
    }

    // Conta a frequência do maior valor
    for (j = 0; j < tam; j++)
    {
        if (elementos[j] == maior)
        {
            freq_maior++;
        }
    }

    // Calcula a frequência percentual do maior valor
    freq_maior = freq_maior * 100;

    printf("%d ", maior);
    printf("%.2lf%%\n", (double)freq_maior / tam);
}

/*-----------------------------------------------------------------*/
// Função principal
// Lê uma matriz, armazena seus elementos em um array,
// e imprime o valor mínimo e máximo da matriz com suas frequências.
/*-----------------------------------------------------------------*/
int main()
{
    int i, j;
    int N, M;
    int matriz[MAX][MAX];
    int elementos[MAX * MAX];

    // Lê as dimensões da matriz
    scanf("%d %d", &N, &M);

    // Lê os elementos da matriz
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Copia os elementos da matriz para o array linear
    lendo_elementos(matriz, N, M, elementos);
    
    // Calcula e imprime o menor valor e sua frequência
    freq_menor(elementos, N * M);
    
    // Calcula e imprime o maior valor e sua frequência
    freq_maior(elementos, N * M);

    return 0;
}

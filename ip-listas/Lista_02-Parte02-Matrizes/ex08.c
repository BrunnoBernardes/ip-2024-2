#include <stdio.h>

#define MAX 500 // Tamanho máximo da matriz quadrada

/*-------------------------------------------------------------------------------------------------------*/
// Verifica se uma matriz quadrada é uma matriz de permutação e calcula a soma dos elementos de cada linha
/*-------------------------------------------------------------------------------------------------------*/
int ehPermutacao(int M[][MAX], int dimensao, int *soma)
{
    int i, j, soma_linha, soma_coluna;
    int permutacao = 1; // Assume que é uma matriz de permutação até provar o contrário

    for (i = 0; i < dimensao; i++)
    {
        soma_linha = 0;
        soma_coluna = 0;

        for (j = 0; j < dimensao; j++)
        {
            // Verifica se os elementos são apenas 0 ou 1 (requisito para matriz de permutação)
            if (M[i][j] != 0 && M[i][j] != 1)
            {
                permutacao = 0;
            }

            // Calcula a soma dos elementos da linha e da coluna
            soma_linha += M[i][j];
            soma_coluna += M[j][i];
        }

        // Verifica se a soma da linha é igual à soma da coluna correspondente ( = 1 )
        if (soma_linha != soma_coluna)
        {
            permutacao = 0;
        }

        *soma += soma_linha; // Atualiza o valor de 'soma' com a soma da linha atual
    }

    return permutacao;
}

/*------------*/
// Função main
/*------------*/
int main ()
{
    int i, j;
    int dimensao, soma = 0;
    int M[MAX][MAX];

    scanf ("%d", &dimensao);

    for (i = 0; i < dimensao; i++)
    {
        for (j = 0; j < dimensao; j++)
        {
            scanf ("%d", &M[i][j]);
        }
    }

    printf("%d\n", dimensao);
    
    // Verifica se a matriz é uma matriz de permutação
    if (ehPermutacao(M, dimensao, &soma))
    {
        printf("PERMUTACAO\n");
    }
    else
    {
        printf("NAO EH PERMUTACAO\n");
    }
    
    printf("%d\n", soma); // Imprime a soma total das linhas

    return 0;
}

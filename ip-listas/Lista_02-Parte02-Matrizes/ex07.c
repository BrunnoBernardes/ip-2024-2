#include <stdio.h>

#define MAX 99 // Tamanho máximo da matriz

/*-------------------------------------------------------------------------------------------------------------*/
// Preenche uma matriz com um padrão em forma de losango, usando caracteres específicos para a borda e o centro.
/*-------------------------------------------------------------------------------------------------------------*/
void losango(char M[][MAX], int dimensao, char borda, char centro)
{
    int i, j;

    for (i = 0; i < dimensao; i++)
    {
        for (j = 0; j < dimensao; j++)
        {
            // Verifica se a posição (i, j) está fora do losango e preenche com espaço
            if (i + j < dimensao / 2 || i + j > dimensao + dimensao / 2 - 1 || // Quadrante 2 e 4
                i - j > dimensao / 2 || j - i > dimensao / 2) // Quadrante 1 e 3
            {
                M[i][j] = ' ';
            }
            // Verifica se a posição (i, j) está na borda do losango e preenche com o caractere de borda
            else if (i + j == dimensao / 2 || i + j == dimensao + dimensao / 2 - 1 || // Quadrante 2 e 4
                     i - j == dimensao / 2 || j - i == dimensao / 2) // Quadrante 1 e 3
            {
                M[i][j] = borda;
            }
            // Caso contrário, preenche com o caractere do centro
            else
            {
                M[i][j] = centro;
            }
        }
    }
}

/*------------*/
// Função main
/*------------*/
int main ()
{
    int dimensao;
    char borda, centro;
    char M[MAX][MAX];
    int i, j;

    // Lê a dimensão da matriz, caractere da borda e caractere do centro
    scanf("%d%*c%c%*c%c", &dimensao, &borda, &centro);

    // Verifica se a dimensão é válida (ímpar)
    if (dimensao % 2 == 0)
    {
        printf("Dimensao invalida!\n");
        return 1;
    }

    losango(M, dimensao, borda, centro); // Preenche a matriz com o padrão de losango

    // Imprime a matriz com o losango
    for (i = 0; i < dimensao; i++)
    {
        for (j = 0; j < dimensao; j++)
        {
            printf("%c ", M[i][j]);
        }
        printf("\n");
    }

    return 0;
}
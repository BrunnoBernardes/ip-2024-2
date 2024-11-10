#include <stdio.h>

#define MAX 1000 // Tamanho máximo da matriz

/*------------*/
// Função main	
/*------------*/

int main ()
{
    int dimensao, i, j, M [MAX][MAX];

    scanf("%d", &dimensao);

    for (i = 0; i < dimensao; i++)
    {
        for (j = 0; j < dimensao; j++)
        {
            scanf("%d", &M[i][j]);
        }
    }

    // Imprime os elementos da diagonal secundária
    for (i = 0; i < dimensao; i++)
    {
        for (j = 0; j < dimensao; j++)
        {
            if (i + j == dimensao - 1) // Condição para a diagonal secundária
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    return 0;
}
#include <stdio.h>

#define MAX 100 // Largura máxima da matriz

void identifica_wally(int *largura, int *altura, int matriz[MAX][MAX])
{
    int i, j, check, verificador = 0, wallyi, wallyj;

    for (i = 0; i < *largura - 2; i++)
    {
        for (j = 0; j < *altura - 2; j++)
        {
            if (matriz[i][j] == 1111)
            {

                check = 1;

                if (matriz [i-1][j] != 4 && matriz[i+1][j] != 8 && matriz[i][j-1] != 0 && matriz[i][j+1] != 0)
                {
                    break;
                }
            
                if (matriz[i - 1][j] == 4)
                {
                    check += 1;
                }
                else if (matriz[i + 1][j] == 8)
                {
                    check += 1;
                }
                else if (matriz[i][j - 1] == 0)
                {
                    check += 1;
                }
                else if (matriz[i][j + 1] == 0)
                {
                    check += 1;
                }
                
            }
            if (check > verificador)
            {
                verificador = check;
                wallyi = i;
                wallyj = j;
            }
        }
    }

    if (verificador == 0)
    {
        printf("WALLY NAO ESTA NA MATRIZ\n");
    }
    else
    {
        printf("%d %d\n", wallyi, wallyj);
    }
}

int main()
{
    int i, j;
    int largura, altura, matriz[MAX][MAX];

    scanf("%d %d", &largura, &altura);

    for (i = 0; i < largura; i++)
    {
        for (j = 0; j < altura; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    identifica_wally(&largura, &altura, matriz);

    return 0;
}
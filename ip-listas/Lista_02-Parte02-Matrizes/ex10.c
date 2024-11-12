#include <stdio.h>

#define MAX 100 // Largura máxima da matriz

/*---------------------------------------------------------------------------------------------------------------------------------------------*/
// Procura por uma posição na matriz que contenha o valor 1111, que representa "Wally", e verifica se ele está cercado por valores específicos.
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
void identifica_wally(int *largura, int *altura, int matriz[MAX][MAX])
{
    int i, j, check = 0, verificador = 0, wallyi, wallyj;

    // Percorre cada posição da matriz
    for (i = 0; i < *largura; i++)
    {
        for (j = 0; j < *altura; j++)
        {
            // Verifica se a posição atual contém o valor 1111 (representando Wally)
            if (matriz[i][j] == 1111)
            {
                check = 1; // Marca que encontrou Wally

                // Verifica condições específicas ao redor de Wally
                if (matriz[i - 1][j] != 4 && matriz[i + 1][j] != 8 && matriz[i][j - 1] != 0 && matriz[i][j + 1] != 0)
                {
                    break; // Se Wally não estiver cercado corretamente, interrompe
                }
            
                // Conta as posições válidas ao redor de Wally
                if (i >= 1 && matriz[i - 1][j] == 4)
                {
                    check += 1;
                }
                else if (i < (*largura - 1) && matriz[i + 1][j] == 8)
                {
                    check += 1;
                }
                else if (j >= 1 && matriz[i][j - 1] == 0)
                {
                    check += 1;
                }
                else if (j < (*altura - 1) && matriz[i][j + 1] == 0)
                {
                    check += 1;
                }
            }
            
            // Atualiza a posição de Wally com o maior valor de 'check'
            if (check > verificador)
            {
                verificador = check;
                wallyi = i;
                wallyj = j;
            }
        }
    }

    // Imprime a posição de Wally ou mensagem de ausência
    if (verificador == 0)
    {
        printf("WALLY NAO ESTA NA MATRIZ\n");
    }
    else
    {
        printf("%d %d\n", wallyi, wallyj); // Posição de Wally encontrada
    }
}

/*------------*/
// Função main
/*------------*/
int main()
{
    int i, j;
    int largura, altura, matriz[MAX][MAX];

    // Lê a largura e altura da matriz
    scanf("%d %d", &largura, &altura);

    // Lê os elementos da matriz
    for (i = 0; i < largura; i++)
    {
        for (j = 0; j < altura; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Procura por Wally na matriz
    identifica_wally(&largura, &altura, matriz);

    return 0;
}

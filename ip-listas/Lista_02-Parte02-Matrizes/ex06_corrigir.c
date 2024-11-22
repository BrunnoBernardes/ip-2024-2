#include <stdio.h>

#define MAX_L 100 // Largura máxima da matriz
#define MAX_A 100 // Altura máxima da matriz

/*-----------------------------------------------------*/
// Imprime a matriz M em formato PGM (Portable GrayMap).
/*-----------------------------------------------------*/
void print_pgm(int largura, int altura, int M[MAX_L][MAX_A])
{
    int i, j;

    // Imprime o cabeçalho do formato PGM
    printf("P2\n");
    printf("%d %d\n", largura, altura);
    printf("255\n");

    // Imprime os valores de pixels da imagem em formato PGM
    for (i = 0; i < largura; i++)
    {
        for (j = 0; j < altura; j++)
        {
            if (j == altura - 1) // Último pixel da linha
            {
                printf("%d", M[i][j]);
            }
            else
            {
                printf("%d ", M[i][j]);
            }
        }
        printf("\n"); // Nova linha após cada linha de pixels
    }
}

/*------------*/
// Função main
/*------------*/
int main ()
{
    int largura, altura, borda, valor;
    int M[MAX_L][MAX_A] = {0}; // Matriz de pixels
    int i, j;

    scanf("%d%d", &largura, &altura);
    scanf("%d", &borda);
    scanf("%d", &valor);

    // Verifica se a largura e altura estão dentro dos limites
    if (largura > MAX_L || altura > MAX_A)
    {
        return 0;
    }

    // Define a matriz com a borda
    for (i = 0; i < largura; i++)
    {
        for (j = 0; j < altura; j++)
        {
            // Se a posição estiver dentro da borda, define o valor especificado
            if (i < borda || i >= (largura - borda) || j < borda || j >= (altura - borda))
            {
                M[i][j] = valor;
            }
        }
    }

    // Imprime a imagem em formato PGM
    print_pgm(largura, altura, M);

    return 0;
}

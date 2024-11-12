#include <stdio.h>

#define MAX 10 // Largura máxima da matriz

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/
// Encontra e imprime os elementos únicos em uma matriz, separando-os por vírgulas. Caso não haja elementos únicos, imprime uma mensagem apropriada.
/*-------------------------------------------------------------------------------------------------------------------------------------------------*/
void numero_unico(int linhas, int colunas, int M[MAX][MAX])
{
    int i, j, k = 0, unico[MAX * MAX];
    int repetiu = 0, verificador = 0, primeiro_elemento = 1;

    // Copia os elementos da matriz para um array linear
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            unico[k] = M[i][j];
            k++;
        }
    }

    // Verifica quais elementos do array são únicos
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < k; j++)
        {
            if (unico[i] == unico[j])
            {
                repetiu++;
            }
        }
        
        // Imprime o elemento se ele aparecer apenas uma vez
        if (repetiu == 1)
        {
            verificador = 1;
            if (!primeiro_elemento)
            {
                printf(","); // Adiciona vírgula antes de elementos únicos adicionais
            }
            printf("%d", unico[i]);
            primeiro_elemento = 0; // Marca que o primeiro elemento único foi impresso
        }
        repetiu = 0;
    }
    
    // Se nenhum elemento único foi encontrado, imprime uma mensagem
    if (verificador == 0)
    {
        printf("sem elementos unicos\n");
    }
    else
    {
        printf("\n");
    }
}

/*------------*/
// Função main
/*------- ----*/
int main()
{
    int linhas, colunas, i, j, matriz[MAX][MAX];

    // Lê as dimensões da matriz
    scanf("%d %d", &linhas, &colunas);

    // Verifica se as dimensões estão dentro do limite permitido
    if (linhas > MAX || colunas > MAX || linhas < 1 || colunas < 1)
    {
        printf("dimensao invalida\n");
        return 0;
    }

    // Lê os elementos da matriz
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Chama a função para identificar e imprimir os elementos únicos
    numero_unico(linhas, colunas, matriz);

    return 0;
}

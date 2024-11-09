#include <stdio.h>

#define N 1000 // Número máximo de elementos

/*----------------------------------------------------------*/
// Função que identifica elementos únicos no array 'elemento'
/*----------------------------------------------------------*/

void elemento_unico(int *elemento, int *unico, int n, int *k)
{
    int i, j, repetiu = 0;
    *k = 0;
    for (i = 0; i < n; i++)
    {
        // Verifica se o elemento atual já apareceu antes no array
        for (j = i - 1; j >= 0; j--)
        {
            if (elemento[j] == elemento[i])
            {
                repetiu = 1;
                break; // Interrompe o loop para econimizar processamento
            }
        }
        // Se o elemento não se repetiu, armazena no array 'unico'
        if (repetiu == 0)
        {
            unico[*k] = elemento[i];
            *k += 1;
        }
        repetiu = 0;
    }
}

/*-----------------*/
// Função principal
/*-----------------*/

int main()
{
    int n, elemento[N], unico[N]; 
    int i, k;

    scanf("%d", &n); 

    // Recebe os elementos do array
    for (i = 0; i < n; i++)
    {
        scanf("%d", &elemento[i]);
    }

    // Chama a função para identificar elementos únicos
    elemento_unico(elemento, unico, n, &k);

    // Imprime os elementos únicos
    for (i = 0; i < k; i++)
    {
        printf("%d\n", unico[i]);
    }

    return 0;
}

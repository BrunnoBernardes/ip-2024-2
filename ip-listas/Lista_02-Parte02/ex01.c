#include <stdio.h>
 
int main()
{
    int N, M, i, j;
    scanf("%d", &N);
    int numeros[N];
    int numero, count = 0;
    for (i = 0; i < N; i++) scanf("%d", &numeros[i]);
    scanf("%d", &M);
    for (i = 0; i < M; i++)
    {
        scanf("%d", &numero);
        count = 0;
        for (j = 0; j < N; j++)
        {
            if (numeros[j] == numero)
            {
                count = 1;
                break;
            }
        }
        if (count == 1) printf("ACHEI\n");
        else printf("NAO ACHEI\n");
    }
    return 0;
}
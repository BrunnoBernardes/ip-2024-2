#include <stdio.h>
#define N 10000

int maior_numero(int V[N], int n)
{
    int i, maior = V[0];
    for (i = 1; i < n; i++)
    {
        if (V[i] > maior)
        {
            maior = V[i];
        }
    }
    return maior;
}

int verificador(int V[N], int n, int i)
{
    int j, count = 0;
    for (j = 0; j < n; j++)
    {
        if (V[j] <= i)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n, i, j, k, count;
    int V[N];

    scanf("%d", &n);
    while (n != 0)
    {
        for (i = 0; i < n; i++)
        {
            scanf("%d", &V[i]);
        }
        k = maior_numero(V, n);
        //printf("k = %d\n", k);
        for (i = 0; i <= k; i++)
        {
            count = verificador(V, n, i);
            printf("(%d) %d\n", i, count);
        }
        scanf("%d", &n);
    }
    return 0;
}
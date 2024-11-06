#include <stdio.h>

void ordenar (int v[], int N)
{
    int i, j, aux;

    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

void print_mediana (int v[], int N)
{
    if (N % 2 == 0) printf("%.2f\n", (v[N/2] + v[N/2 - 1]) / 2.0);
    else printf("%.2f\n", (double)v[N/2]);
}

int main ()
{
    int N, i;
    scanf("%d", &N);
    if (N <= 0 || N > 1000000) return 1;
    int v[N];
    for (i = 0; i < N; i++) scanf(" %d", &v[i]);
    ordenar(v, N);
    print_mediana(v, N);
    return 0;
}
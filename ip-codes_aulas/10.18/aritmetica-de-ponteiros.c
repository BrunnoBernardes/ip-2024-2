#include <stdio.h>

#define N 5
int main ()
{
    int v[N], i;
    int *pv; // int *pv = v;
    pv = v;

    for (i=0; i<N; i++)
    {
        printf("Escreva o valor a armazenado no vetor %d: ", i+1);
        scanf("%d", &*(pv+i)); // scanf("%d", pv+i);
    }

    printf("\n");

    for (i=0; i<N; i++)
    {
        printf("Valor armazenado no vetor %d: ", i+1);
        printf("%d\n", *(pv+i));
    }

    return 0;
}
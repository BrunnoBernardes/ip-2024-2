#include <stdio.h>
#define N 6

void bubble_sort (int *v, int n)
{
    int i, j, aux;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-1; j++)
        {
            if (v[j] > v[j+1])
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

void print_vetor (int *v, int n)
{
    int i;
    printf("Vetor ordenado: ");
    for (i = 0; i < n; i++) printf("%d ", v[i]);
    printf("\n");
}

int main ()
{
    int v[N];
    printf("Digite %d numeros do vetor: ", N);
    scanf("%d %d %d %d %d %d", &v[0], &v[1], &v[2], &v[3], &v[4], &v[5]);
    bubble_sort(v, N);
    print_vetor(v, N);
    return 0;
}
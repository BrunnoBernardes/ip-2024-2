#include <stdio.h>

#define N 10000
int main ()
{
    int notas[N];
    int n, i, count, maior, id;

    // leitura de elementos
    scanf("%d", &n);
    if (n<1 || n>N)
    {
        printf("Tamanho Invalido!\n");
        return 0;
    }

    // leitura de vetor
    for (i=0; i<n; i++) scanf("%d", &notas[i]);
    
    // contabilizar quantas vezes o v[n-1] aparece
    count = 0;
    for (i=0; i<n; i++) if (notas[i] == notas[n-1]) count++;
    printf("Nota %d, %d vezes\n", notas[n-1], count);

    // encontrar o maior valor
    maior = notas[0];
    id = 0;
    for (i=0; i<n; i++) if (notas[i]>maior)
    {
        maior = notas[i];
        id = i;
    }
    printf("Nota %d, indice %d\n", maior, id);
    

    return 0;
}
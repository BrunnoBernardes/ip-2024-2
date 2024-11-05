#include <stdio.h>
#include <string.h>
#define MAX1 1001

void mover_3(char *M, int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        if ((M[i] >= 65 && M[i] <= 90) || (M[i] >= 97 && M[i] <= 122)) M[i] += 3;
    }
}

void inverter(char *M, int tamanho)
{
    int i, j, aux;
    for (i = 0, j = tamanho - 1; i < j; i++, j--)
    {
        aux = M[i];
        M[i] = M[j];
        M[j] = aux;
    }
}

void voltar_1(char *M, int tamanho)
{
    int i;
    for (i = tamanho / 2; i < tamanho; i++) M[i] -= 1;
}

void print_string(char *M)
{
    int i;
    for (i = 0; M[i] != '\0'; i++) printf("%c", M[i]);
    printf("\n");
}

int main()
{
    int i, j, tamanho, N;
    scanf("%d", &N);
    if (N < 1 || N > 10000) return 1;
    char M[MAX1];
    for (i = 0; i < N; i++)
    {
        scanf(" %[^\n]%*c", M);
        tamanho = strlen(M);
        mover_3(M, tamanho);
        inverter(M, tamanho);
        voltar_1(M, tamanho);
        print_string(M);
    }
    return 0;
}
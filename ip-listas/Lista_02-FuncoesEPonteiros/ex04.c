#include <stdio.h>

void somaDivisores (int n)
{
int divisor = 2, soma = 1;
    printf("%d = 1 ", n);
    while (n>divisor) {
        if (n%divisor==0) {
            soma += divisor;
            printf("+ %d ", divisor);
        }
        divisor++;
    }
    printf("= %d", soma);
    if (n == soma) printf(" (NUMERO PERFEITO)");
    else printf(" (NUMERO NAO E PERFEITO)");
}

int main ()
{
    int n;
    scanf("%d", &n);
    somaDivisores(n);
    return 0;
}
#include <stdio.h>
 
int main () {

    int n, divisor = 2, soma = 1;

    scanf("%d", &n);

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

    return 0;
}
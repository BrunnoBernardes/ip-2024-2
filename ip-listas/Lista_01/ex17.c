#include <stdio.h>
 
int main () {
    
    int n1, n2, n3, n4;
    int maior, soma;

    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

    maior = n1; //assumindo que n1 é o maior número para começar

    if (n2 > maior) {
        maior = n2;
    }
    if (n3 > maior) {
        maior = n3;
    }
    if (n4 > maior) {
        maior = n4;
    }

    soma = n1 + n2 + n3 + n4 - maior;

    printf("%d\n", soma);
 
    return 0;
}
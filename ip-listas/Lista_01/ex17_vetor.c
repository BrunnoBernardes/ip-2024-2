#include <stdio.h>
 
int main () {
    
    int numero[4], lixo, soma;
    int i, j;

    for (i = 1; i < 5; i++) {
        scanf("%d", &numero[i]);
    }

    for (i = 1; i < 4; i++) {
        for (j = i + 1; j < 5; j++) {
            if (numero[i] > numero[j]) {
                lixo = numero [i];
                numero [i] = numero [j];
                numero [j] = lixo;
            }
        }
    }

    soma = numero[1] + numero[2] + numero[3];

    printf("%d\n", soma);
 
    return 0;
}
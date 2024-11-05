#include <stdio.h>
 

int inverter (int x) {

    int inverso = 0;

    while (x > 0) {
        inverso = inverso * 10 + (x % 10);
        x /= 10;
    }

    return inverso;
}

int main () {

    int n;

    scanf("%d", &n);

    if (n>=100000) printf("NUMERO INVALIDO"); // NÚMERO COM 1 DIGITO?
    else if (n==inverter(n)) printf("PALINDROMO\n");
    else printf("NAO PALINDROMO");
    
    return 0;
}
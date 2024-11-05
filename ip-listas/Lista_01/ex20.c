#include <stdio.h>

int main () {
    
    int n;

    scanf ("%d", &n);

    n = (n * 95); // 32 casas brancas (n) e 32 casas pretas (31*2*n + n)

    printf("%d", n);

    return 0;
}
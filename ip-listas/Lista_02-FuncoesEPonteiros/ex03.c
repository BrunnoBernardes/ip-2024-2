#include <stdio.h>

void separaDigitos (int n, int *d1, int *d2, int *d3)
{
*d1 = n/100; 
*d2 = (n/10)%10;
*d3 = n%10;
}

int main ()
{
    int n, d1, d2, d3;
    scanf("%d", &n);
    separaDigitos(n, &d1, &d2, &d3);
    printf("%d%d%d\n", d3, d2, d1);
    return 0;
}
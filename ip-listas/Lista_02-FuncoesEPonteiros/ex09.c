#include <stdio.h>

void converteEmNotasMoedas(int val)
{
    int n100=0, n50=0, n10=0, m1=0;
    m1 = val%10;
    n10 = (val/10)%10;
    if (n10 >= 5)
    {
        n50 = 1;
        n10 -= 5;
    }
    n100 = val/100;
    printf("NOTAS DE 100 = %d\n", n100);
    printf("NOTAS DE 50 = %d\n", n50);
    printf("NOTAS DE 10 = %d\n", n10);
    printf("MOEDAS DE 1 = %d\n", m1);
}

int main ()
{
    int valor;
    scanf("%d", &valor);
    converteEmNotasMoedas(valor);
    return 0;
}
#include <stdio.h>

double compute_pi(int n)
{
    double pi = 1.0, numerador = 2.0, denominador = 1.0;
    int  i = 1;
    if (n == 0) return 0;
    while (n > 0)
    {
        pi = pi*numerador/denominador;
        if (i%2!=0) denominador += 2;
        else numerador += 2;
        i++;
        n--;
    }
    return pi*2;
}

int main ()
{
    int n_termos;
    scanf("%d", &n_termos);
    printf("%.12lf", compute_pi(n_termos));
    return 0;
}
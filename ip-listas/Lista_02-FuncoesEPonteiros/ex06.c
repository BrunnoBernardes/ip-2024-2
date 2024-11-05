#include <stdio.h>

double absoluto ( double n)
{
    double absol;
    if (n<0) absol = -n;
    else absol = n;
    return absol;
}

void raiz( double n, double e)
{
    double r = 1.0;
    double modulo = absoluto(n - (r*r));
    while (modulo > e)
    {
        r = (r + (n / r)) / 2;
        modulo = absoluto(n - (r * r));
        printf("r: %.9lf, err: %.9lf\n", r, modulo);
    }
}

int main ()
{
    double n, e;
    scanf("%lf", &n);
    scanf("%lf", &e);
    raiz(n, e);
    return 0;
}
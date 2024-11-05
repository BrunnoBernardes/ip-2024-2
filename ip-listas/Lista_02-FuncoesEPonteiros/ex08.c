#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int next_power(int n, int p, int *k)
{
    int i, x;
    double j;
    int np = n;
    int aux1, aux2;
    for (i = 0; i <= n; i++)
    {
        j = pow((double)i, (double)p);
        if (j <= n)
        {
            np = j;
            *k = i;
        }
        else
        {
            break;
        }
    }
    aux1 = abs(n - j);
    aux2 = abs(n - np);
    if (aux1 < aux2)
    {
        np = j;
        *k = i;
    }
    else
    {
        *k = i - 1;
    }
    return np;
}

int main()
{
    int n, p, np = 0, k = 1;
    scanf("%d%d", &n, &p);
    np = next_power(n, p, &k);
    printf("%d -> %d^%d = %d\n", n, k, p, np);
    return 0;
}
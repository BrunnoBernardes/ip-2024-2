#include <stdio.h>

int fatorial(int n)
{
    int f = 1, i;
    for (i = 1; i <= n; i++)
    {
        f *= i;
    }
    return f;
}

int combinacao(int n, int k)
{
    return fatorial(n) / (fatorial(k) * fatorial(n - k));
}

int main()
{
    int n1, n2, i, j;

    scanf("%d %d", &n1, &n2);

    for (i = n1; i <= n2; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("%d", combinacao(i, j));
            if (j < i)
            {
                printf(",");
            }
        }
        printf("\n");
    }
    return 0;
}
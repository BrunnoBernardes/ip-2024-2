#include <stdio.h>

int main()
{
    int n, i, tamanho;
    int binario[32];
    while (scanf("%d", &n) != EOF)
    {
        i = 0;
        if (n == 0) printf("0");
        while (n > 0)
        {
            binario[i] = n % 2;
            n /= 2;
            i++;
        }
        for (i--; i >= 0; i--) printf("%d", binario[i]);
        printf("\n");
    }
    return 0;
}
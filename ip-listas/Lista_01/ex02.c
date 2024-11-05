#include <stdio.h>

int main()
{

    int n1, n2, n3, n4, n5;

    scanf("%d%d%d", &n1, &n2, &n3);

    if (n1 >= 10 || n2 >= 10 || n3 >= 10)
    {

        printf("DIGITO INVALIDO");
    }
    else
    {

        n1 = n1 * 100;
        n2 = n2 * 10;
        n4 = n1 + n2 + n3;
        n5 = n4 * n4;

        printf("%d, %d", n4, n5);
    }

    return 0;
}
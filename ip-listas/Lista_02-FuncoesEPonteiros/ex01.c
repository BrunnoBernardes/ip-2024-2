#include <stdio.h>

unsigned long int fat(int n)
{
    unsigned long int fat = 1;
    while (n > 0)
    {
        fat *= n;
        n--;
    }
    return fat;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d! = %lu\n", n, fat(n));
    return 0;
}
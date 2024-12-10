#include <stdio.h>

int main ()
{
    int n;
    FILE *f = fopen("input", "r");
    while (1)
    {
        if (fscanf(f, "%d", &n) == EOF) break;
        printf("%d\n", n);
    }
    
    return 0;
}
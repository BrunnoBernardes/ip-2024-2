#include <stdio.h>

int main ()
{
    int L, A;
    int cor = 0;
    int l, c;
    printf("P2\n");
    scanf("%d %d", &L, &A);
    printf("%d %d\n", L, A);
    printf("255\n");
    for (l = 0; l < A; l++)
    {
        for (c = 0; c < L; c++)
        {
            printf("%d ", cor);
        }
        cor++;
        printf("\n");
    }
    return 0;
}
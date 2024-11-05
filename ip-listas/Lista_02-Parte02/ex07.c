#include <stdio.h>
#include <string.h>
#define T 12

int main ()
{
    int M, N, i = 0;
    char R[T];
    scanf("%d %d", &M, &N);
    while (M != 0 && N != 0)
    {
        sprintf(R, "%d", M + N);
        for (i = 0; R[i] != '\0'; i++) if (R[i] != '0') printf("%c", R[i]);
        printf("\n");
        scanf("%d %d", &M, &N);
    }
    return 0;
}
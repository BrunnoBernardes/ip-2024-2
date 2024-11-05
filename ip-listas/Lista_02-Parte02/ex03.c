#include <stdio.h>

int main ()
{
    int N, i, count = 0;

    scanf("%d", &N);

    int V[N];

    for (i = 0; i < N; i++) scanf("%d", &V[i]);
    for (i = 0; i < N; i++)
    {
        if (V[i]%2==0)
        {
            count += 1;
            printf("%d ", V[i]);
        }
    }
    printf("%d ", count);
    return 0;
}
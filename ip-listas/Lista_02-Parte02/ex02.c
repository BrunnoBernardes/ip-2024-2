#include <stdio.h>

int main()
{
    int K, N, i, count = 0;
    do scanf("%d", &N);
    while (N < 1 || N > 1000);
    int V[N];
    for (i = 0; i < N; i++) scanf("%d", &V[i]);
    scanf("%d", &K);
    for (i = 0; i < N; i++)
    {
        if (V[i] >= K)
        {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
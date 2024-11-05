#include <stdio.h>

void maior_frequencia (int *v, int n)
{
    int i, j, freq = 0, freq_max = 0, num = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (v[i] == v[j]) freq++;
        }
        if (freq > freq_max)
        {
            freq_max = freq;
            num = v[i];
        }
        freq = 0;
    }
    printf("%d\n", num);
    printf("%d\n", freq_max);
}

int main ()
{
    int N, i;
    scanf("%d", &N);
    if (N < 1 || N > 1000000) return 1;
    int v[N];
    for (i = 0; i < N; i++) scanf("%d", &v[i]);
    maior_frequencia(v, N);
    return 0;
}
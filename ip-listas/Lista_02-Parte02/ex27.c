#include <stdio.h>

void ordenar_vetor(int vetor[]) {
    int i, j, temp;
    for (i = 0; i < 9 - 1; i++) {
        for (j = 0; j < 9 - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int T, i, j, k, anao[9], soma_total = 0, resto = 0;
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        soma_total = 0;
        resto = 0;
        for (j = 0; j < 9; j++)
        {
            scanf("%d", &anao[j]);
            soma_total += anao[j];
        }
        resto = soma_total - 100;
        for (j = 0; j < 9; j++)
        {
            for (k = j + 1; k < 9; k++)
            {
                if (anao[j] + anao[k] == resto)
                {
                    anao[j] = 0;
                    anao[k] = 0;
                    break;
                }
            }
        }
        ordenar_vetor(anao);
        for (j = 2; j < 9; j++)
        {
            printf("%d\n", anao[j]);
        }
    }
    return 0;
}
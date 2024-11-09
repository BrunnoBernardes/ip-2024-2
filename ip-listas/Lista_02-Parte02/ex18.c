#include <stdio.h>

#define MAX_ALUNOS 1000 // Número máximo de alunos

int main ()
{
    int N, K, h_chegada[MAX_ALUNOS];
    int i;
    scanf("%d %d", &N, &K); // Número de alunos e número de alunos necessários para aula começar
    for (i = 0; i < N; i++)
    {
        scanf("%d", &h_chegada[i]); // Hora de chegada de cada aluno
    }
    if (N < K)
    {
        printf("NAO\n"); // Se o número de alunos for menor que o necessário
    }
    else
    {
        int cont = 0;
        for (i = 0; i < N; i++) // Conta quantos alunos chegaram adiantados
        {
            if (h_chegada[i] <= 0)
            {
                cont++;
            }
        }
        if (cont < K) // Se não atingiu o número de alunos necessários
        {
            printf("SIM\n");
        }
        else
        {
            printf("NAO\n");
            for (i = N - 1; i >= 0; i--) // Imprime os alunos que chegaram adiantados 
            {
                if (h_chegada[i] <= 0)
                {
                    printf("%d\n", i + 1);
                }
            }
        }
    }
    return 0;
}
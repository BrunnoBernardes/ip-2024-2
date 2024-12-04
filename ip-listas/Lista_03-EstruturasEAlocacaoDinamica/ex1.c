#include <stdio.h>
#include <stdlib.h>

/*-----------------*/
// Função Principal
/*-----------------*/
int main()
{
    int ct, n_fracoes, verificador = 0; // Variáveis principais: ct (número de casos de teste), n_fracoes (número de frações em cada caso), verificador (indica se há frações equivalentes)
    int i, j, k; // Variáveis auxiliares para iteração nos loops
    double *OP = NULL; // Ponteiro para armazenar os valores das frações e seus resultados (numerador, denominador e valor decimal)

    scanf("%d", &ct);

    // Loop principal para cada caso de teste
    for (i = 0; i < ct; i++)
    {
        scanf("%d", &n_fracoes); // Lê o número de frações no caso de teste atual
        OP = (double *) malloc(3 * n_fracoes * sizeof(double)); // Aloca memória para armazenar frações (numerador, denominador, valor decimal)

        // Lê as frações e calcula seus valores decimais
        for (j = 0; j < n_fracoes * 3; j += 3)
        {
            scanf("%lf%*c%lf", &OP[j], &OP[j+1]); // Lê o numerador e o denominador, ignorando o caractere '/' entre eles
            OP[j+2] = OP[j] / OP[j+1]; // Calcula o valor decimal da fração
        }

        printf("Caso de teste %d\n", i + 1); // Imprime o identificador do caso de teste

        // Verifica equivalência entre as frações
        for (j = 0; j < n_fracoes * 3 - 3; j += 3)
        {
            for (k = j + 3; k < n_fracoes * 3; k += 3)
            {
                if (OP[j+2] == OP[k+2]) // Compara valores decimais das frações
                {
                    printf("%g/%g equivalente a %g/%g\n", OP[j], OP[j+1], OP[k], OP[k+1]); // Imprime as frações equivalentes
                    verificador = 1; // Atualiza o verificador indicando que há frações equivalentes
                }
            }
        }

        // Caso não haja frações equivalentes
        if (verificador == 0)
        {
            printf("Nao ha fracoes equivalentes na sequencia\n");
        }

        verificador = 0; // Reseta o verificador para o próximo caso de teste
        free(OP); // Libera a memória alocada para o caso de teste atual
    }

    return 0;
}

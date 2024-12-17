#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------------*/
// Função Principal
/*-----------------*/
int main()
{
    int ct, n_fracoes, verificador = 0; // Variáveis principais: ct (número de casos de teste), n_fracoes (número de frações em cada caso), verificador (indica se há frações equivalentes)
    int i, j, k; // Variáveis auxiliares para iteração nos loops
    char linha[1000]; // String para armazenar a linha de entrada
    double *OP = NULL; // Ponteiro para armazenar os valores das frações e seus resultados (numerador, denominador e valor decimal)

    scanf("%d%*c", &ct);

    // Loop principal para cada caso de teste
    for (i = 0; i < ct; i++)
    {
        scanf("%[^\n]%*c", linha); // Lê o número de frações no caso de teste atual
        char *token = strtok(linha, " "); // Separa o número de frações

        n_fracoes = 0; // Inicializa o número de frações
        OP = (double *) malloc(3000 * sizeof(double)); // Aloca memória para armazenar frações (numerador, denominador, valor decimal)

        // Processa cada fração na linha
        while (token != NULL)
        {
            double numerador, denominador;
            sscanf(token, "%lf/%lf", &numerador, &denominador); // Extrai numerador e denominador
            OP[n_fracoes * 3] = numerador;                     // Armazena numerador
            OP[n_fracoes * 3 + 1] = denominador;               // Armazena denominador
            OP[n_fracoes * 3 + 2] = numerador / denominador;   // Calcula valor decimal
            n_fracoes++;
            token = strtok(NULL, " "); // Próximo token
        }

        printf("Caso de teste %d\n", i + 1); // Imprime o identificador do caso de teste

        // Verifica frações equivalentes
        for (j = 0; j < n_fracoes; j++)
        {
            for (k = j + 1; k < n_fracoes; k++)
            {
                if (OP[j * 3 + 2] == OP[k * 3 + 2]) // Compara valores decimais
                {
                    printf("%g/%g equivalente a %g/%g\n",
                           OP[j * 3], OP[j * 3 + 1], OP[k * 3], OP[k * 3 + 1]);
                    verificador = 1;
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

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char **argv )
{
    if(argc != 3) // Se a quantidade de argumentos for diferente de 3
    {
        printf("Linha de comando invalida\n");
        return 0;
    }

    FILE *arq = NULL; // Ponteiro para o arquivo

    // Abre o arquivo para escrita
    arq = fopen("ex01.txt", "w");
    if(arq == NULL)
    {
        printf("Arquivo nao existe\n");
        return 0;
    }

    int A = atoi(argv[1]); // Converte o primeiro argumento para inteiro
    int B = atoi(argv[2]); // Converte o segundo argumento para inteiro

    int i;

    fprintf(arq, "("); // Abre o arquivo com um parenteses
    if (A <= B) {
        // Crescente
        for (i = A; i < B; i++) {
            fprintf(arq, "%d, ", i);
            // printf("%d\n", i);
        }
        fprintf(arq, "%d)\n", B); // Fecha o arquivo com um parenteses

    } else {
        // Decrescente
        for (i = A; i > B; i--) {
            fprintf(arq, "%d, ", i);
            // printf("%d\n", i);
        }
        fprintf(arq, "%d)\n", B); // Fecha o arquivo com um parenteses
    }

    // Fecha o arquivo
    if(arq)
    {
        fclose(arq);
    }

    return 0;
}
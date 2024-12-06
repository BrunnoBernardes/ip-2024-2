#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( int argc, char **argv)
{
    if(argc != 2) // Se a quantidade de argumentos for diferente de 3
    {
        printf("Linha de comando invalida\n");
        return 0;
    }

    int n;
    char valor;

    FILE *arq = NULL;
    arq = fopen("ex03.txt", "w");

    srand(time(NULL));
    n = atoi(argv[1]);

    for(int i = 0; i < n; i++)
    {
        valor = rand() % 26 + 'a';
        fprintf(arq, "%c\n", valor);
    }

    // Fecha o arquivo
    if(arq)
    {
        fclose(arq);
    }

    return 0;
}
#include <stdio.h>

int main ( int argc, char **argv )
{
    FILE *arq = NULL;
    char ch;
    if(argc != 2)
    {
        printf("Linha de comando inválida\n");
        return 0;
    }

    arq = fopen(argv[1], "r");
    if(arq == NULL)
    {
        printf("Arquivo nao existe\n");
        return 0;
    }

    while(1)
    {
        if( fscanf(arq, "%c", &ch) == EOF){
            break;
        }
        printf("%c", ch);
    }

    fclose(arq);
    printf("\n");

    return 0;
}
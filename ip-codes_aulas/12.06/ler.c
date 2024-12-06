#include <stdio.h>

int main(int argc, char **argv)
{
    char str[1024];

    FILE *arq = fopen( argv[1], "r");

    if(arq)
    {
        printf("Arquivo aberto com sucesso\n");
    }
    else
    {
        printf("O arquivo nao existe\n");
        return 0;
    }

    fscanf(arq, "%[^\n]", str);
    printf("Conteudo do arquivo: %s\n", str);

    return 0;
}

#include <stdio.h>

int main()
{
    FILE *arq = NULL;
    arq = fopen("arquivo.txt", "w");
    if(arq != NULL)
    {
        printf("Arquivo ja existente, mas foi sobrescrito\n");
    }
    else{
        printf("Arquivo nao existente, mas foi criado\n");
    }

    fprintf(arq, "Oi, tudo bem?\n");

    if(arq){
        fclose(arq);
    }
    return 0;
}
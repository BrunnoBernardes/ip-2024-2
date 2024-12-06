#include <stdio.h>
int main ()
{
    FILE *arq = NULL;
    arq = fopen("ex04.txt", "w");

    int i;

    for(i = 0; i < 100; i++)
    {
        fprintf(arq, "%d\n", i+1);
    }

    if(arq)
    {
        fclose(arq);
    }

    return 0;
}
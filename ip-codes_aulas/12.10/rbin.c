#include <stdio.h>

int main ()
{
    int A = 0;
    FILE *arq = fopen("out.bin", "rb");
    fread(&A, sizeof(int), 1, arq);
    fclose(arq);
    printf("A = %d\n", A);

    return 0;
}
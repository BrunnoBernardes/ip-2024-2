#include <stdio.h>

int main ()
{
    int a[2] = {100, 200};
    int b;
    int *pi;

    pi = &b;

    // Verificar endereco na memoria
    printf ("Endereco de a[0]: %p\n", &a[0]);
    printf ("Endereco de a[1]: %p\n", &a[1]);
    printf ("Endereco de b   : %p\n", &b);
    printf ("Endereco de pi  : %p\n", &pi);

    printf ("\n");

    printf ("Valor do vetor a[0] = %d\n", *(pi+1));
    printf ("Valor do vetor a[1] = %d\n", *(pi+2));

    /**pi = a[0];
    printf ("Valor do vetor a[0] = %d\n", b);

    *pi = a[1];
    printf ("Valor do vetor a[1] = %d\n", b);*/

    return 0;
}
#include <stdio.h>

int main ()
{
    int v [3];
    int *pi = &v[1];

    pi[0] = 8;
    pi[1] = 5;
    pi[-1] = 11; //Linguagem C nao permite indexacao negativa 

    return 0;
}
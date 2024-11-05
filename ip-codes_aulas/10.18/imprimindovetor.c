#include <stdio.h>

int main ()
{

    int *pi;
    int v[3] = {10,20,30};
    pi = v;

    printf("%d\n", *pi);
    printf("%d\n", *(pi+1));
    printf("%d\n", *(pi+2));

    //Automatizando
    printf("\n");
    //Automatizando

    int i;

    for (i=0; i<3; i++) printf("%d\n", *(pi+i));

    return 0;
}
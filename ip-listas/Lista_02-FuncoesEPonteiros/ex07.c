#include <stdio.h>

void print_byte(unsigned char byte)
{
    int nbits;
    int peso = 128;
    while (peso > 0)
    {
        printf("%d", byte / peso);
        byte %= peso;
        peso /= 2;
    }
}

void print_bytes(void *ptr, int nbytes)
{
    char *pc = ptr;
    int i;
    for (i = 0; i < nbytes; i++)
    {
        print_byte(*pc);
        pc++;
        printf(" ");
    }
}

int main()
{
    double x;
    unsigned char ch;
    unsigned short sh;
    unsigned int ui;
    float fl;
    scanf("%lf", &x);
    ch = sh = ui = fl = x;
    print_bytes(&ch, sizeof(char));
    printf("\n");
    print_bytes(&sh, sizeof(short));
    printf("\n");
    print_bytes(&ui, sizeof(int));
    printf("\n");
    print_bytes(&fl, sizeof(float));
    printf("\n");
    print_bytes(&x, sizeof(double));
    printf("\n");
    return 0;
}
#include <stdio.h>

int main()
{

    float a, b, c, m;

    scanf("%f%f%f", &a, &b, &c);

    m = (a + b + c) / 3;

    if (m >= 6)
        printf("MEDIA = %.2f\nAPROVADO", m);
    else
        printf("MEDIA = %.2f\nREPROVADO", m);

    return 0;
}
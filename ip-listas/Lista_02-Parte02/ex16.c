#include <stdio.h>

void scan_entrada(int *TA, int *TB)
{
    do scanf("%d", TA);
    while (*TA < 1 || *TA > 100);
    do scanf("%d", TB);
    while (*TB < 1 || *TB > 100);
}

void scan_conjunto(int *conjunto, int tamanho)
{
    int i = 0, j, valor;
    while(i < tamanho)
    {
        scanf("%d", &valor);
        for (j = 0; j < i; j++)
        {
            if (conjunto[j] == valor)
            {
                i--;
                break;
            }
        }
        conjunto[i++] = valor;
    }
}

void print_conjunto(int *conjunto, int tamanho)
{
    int i, j;
    printf("(");
    for (i = 0; i < tamanho; i++)
    {
        printf("%d", conjunto[i]);
        if (i != (tamanho - 1)) printf(",");
    }
    printf(") \n");
}

void subtracao_conjunto(int *A, int TA, int *B, int TB)
{
    int i, j, k, C[TA];
    for (i = 0, k = 0; i < TA; i++)
    {
        for (j = 0; j < TB; j++)
        {
            if (A[i] == B[j])
                break;
        }
        if (j == TB)
            C[k++] = A[i];
    }
    print_conjunto(C, k);
}

void multiplicacao_conjunto(int *A, int TA, int *B, int TB)
{
    int i, j;
    printf("(");
    for (i = 0; i < TA; i++)
    {
        for (j = 0; j < TB; j++)
        {
            if ((i != TA - 1 || j != TB - 1))
            {
                printf("(%dx%d)", A[i], B[j]);
                printf(",");
            }
            else printf("(%dx%d)", A[i], B[j]);
        }
    }
    printf(") \n");
}

int main()
{
    int TA, TB, i;
    int A[100], B[100];
    scan_entrada(&TA, &TB);
    scan_conjunto(A, TA);
    scan_conjunto(B, TB);
    print_conjunto(A, TA);
    print_conjunto(B, TB);
    subtracao_conjunto(A, TA, B, TB);
    multiplicacao_conjunto(A, TA, B, TB);
    return 0;
}
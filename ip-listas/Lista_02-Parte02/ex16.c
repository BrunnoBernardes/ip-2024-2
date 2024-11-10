#include <stdio.h>

/*-------------------------------------------------------------------*/
// Lê o tamanho dos conjuntos A e B com valores válidos entre 1 e 100.
/*-------------------------------------------------------------------*/

void scan_entrada(int *TA, int *TB)
{
    do scanf("%d", TA);
    while (*TA < 1 || *TA > 100);
    do scanf("%d", TB);
    while (*TB < 1 || *TB > 100);
}

/*------------------------------------------*/
// Lê os elementos do conjunto sem repetição
/*------------------------------------------*/

void scan_conjunto(int *conjunto, int tamanho)
{
    int i = 0, j, repetiu = 0, valor;
    while(i < tamanho)
    {
        scanf("%d", &valor);
        for (j = i - 1; j >= 0; j--) // Verifica se o valor já existe no conjunto
        {
            if (conjunto[j] == valor) 
            {
                repetiu = 1;
                break; // Interrompe o loop para econimizar processamento
            }
        }
        if (repetiu == 0) // Armazena valor se não for duplicado
        {
            conjunto[i] = valor;
            i++;
        }
        repetiu = 0; 
    }
}

/*-------------------------------------------------*/
// Imprime os elementos do conjunto entre parênteses
/*-------------------------------------------------*/

void print_conjunto(int *conjunto, int tamanho)
{
    int i, j;
    printf("(");
    for (i = 0; i < tamanho; i++) // Formata a impressão entre elementos
    {
        printf("%d", conjunto[i]);
        if (i != (tamanho - 1)) printf(",");
    }
    printf(")\n");
}

/*-----------------------------------------*/
// Realiza a subtração de conjuntos (A - B)
/*-----------------------------------------*/

void subtracao_conjunto(int *A, int TA, int *B, int TB)
{
    int i, j, k, C[TA];
    for (i = 0, k = 0; i < TA; i++)
    {
        for (j = 0; j < TB; j++)
        {
            if (A[i] == B[j]) // Interrompe se o elemento de A estiver em B
                break;
        }
        if (j == TB) // Se A[i] não estiver em B, adiciona a C
            C[k++] = A[i];
    }
    print_conjunto(C, k);
}

/*------------------------------------------------*/
// Realiza o produto cartesiano dos conjuntos A e B
/*------------------------------------------------*/

void multiplicacao_conjunto(int *A, int TA, int *B, int TB)
{
    int i, j;
    printf("(");
    for (i = 0; i < TA; i++)
    {
        for (j = 0; j < TB; j++) // Formata a impressão do produto cartesiano (AxB)
        {
            if ((i != TA - 1 || j != TB - 1))
            {
                printf("(%dx%d)", A[i], B[j]); 
                printf(",");
            }
            else printf("(%dx%d)", A[i], B[j]);
        }
    }
    printf(")\n");
}

/*------------*/
// Função main
/*------------*/

int main()
{
    int TA, TB, i;
    int A[100], B[100];

    scan_entrada(&TA, &TB); // Lê tamanhos dos conjuntos A e B
    scan_conjunto(A, TA);   // Lê elementos do conjunto A
    scan_conjunto(B, TB);   // Lê elementos do conjunto B
    
    print_conjunto(A, TA);  // Imprime conjunto A
    print_conjunto(B, TB);  // Imprime conjunto B
    
    subtracao_conjunto(A, TA, B, TB); // Realiza A - B
    multiplicacao_conjunto(A, TA, B, TB); // Realiza AxB
    return 0;
}
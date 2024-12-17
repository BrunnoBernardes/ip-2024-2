#include <stdio.h>
#include <math.h>

/* Estrutura para representar números complexos */
typedef struct {
    float real; // Parte real do número complexo
    float imag; // Parte imaginária do número complexo
} Complex;

/* Estrutura para armazenar as duas raízes da equação quadrática */
typedef struct {
    Complex raiz1; // Primeira raiz
    Complex raiz2; // Segunda raiz
} RaizEqu2;

/* 
 * Função para imprimir um número complexo no formato correto.
 * Ajusta a saída para:
 * - "i" em vez de "1.00i"
 * - "-i" em vez de "-1.00i"
 */
void complex_print(Complex c) {
    if (c.real != 0) { 
        printf("%.2f", c.real); // Imprime a parte real se for diferente de zero
    }
    if (c.imag > 0) {
        if (c.imag == 1.0) { // Ajuste para "i" quando imaginário for 1.00
            printf("%s", c.real != 0 ? "+i" : "i");
        } else {
            printf("%s%.2fi", c.real != 0 ? "+" : "", c.imag);
        }
    } else if (c.imag < 0) {
        if (c.imag == -1.0) { // Ajuste para "-i" quando imaginário for -1.00
            printf("-i");
        } else {
            printf("%.2fi", c.imag);
        }
    }
    if (c.real == 0 && c.imag == 0) { // Caso ambas as partes sejam zero
        printf("0");
    }
}

/* 
 * Função que calcula as raízes de uma equação quadrática.
 * Aceita coeficientes a, b e c.
 * Retorna as raízes como números complexos (para casos com delta < 0).
 */
RaizEqu2 calcula_raiz_equ_2(float a, float b, float c) {
    RaizEqu2 r; // Variável para armazenar as raízes
    float delta = b * b - 4 * a * c; // Calcula o delta

    if (delta >= 0) { // Caso de raízes reais
        r.raiz1.real = (-b + sqrt(delta)) / (2 * a);
        r.raiz1.imag = 0;
        r.raiz2.real = (-b - sqrt(delta)) / (2 * a);
        r.raiz2.imag = 0;
    } else { // Caso de raízes complexas
        r.raiz1.real = -b / (2 * a);                  // Parte real
        r.raiz1.imag = sqrt(-delta) / (2 * a);        // Parte imaginária positiva
        r.raiz2.real = -b / (2 * a);                  // Parte real
        r.raiz2.imag = -sqrt(-delta) / (2 * a);       // Parte imaginária negativa
    }
    return r;
}

int main() {
    float a, b, c;

    /* Leitura de coeficientes a, b e c até o fim do arquivo (EOF) */
    while (scanf("%f %f %f", &a, &b, &c) != EOF) {
        RaizEqu2 raizes = calcula_raiz_equ_2(a, b, c);

        printf("x1 = ");
        complex_print(raizes.raiz1); // Imprime a primeira raiz
        printf("\n");

        printf("x2 = ");
        complex_print(raizes.raiz2); // Imprime a segunda raiz
        printf("\n");
    }

    return 0;
}

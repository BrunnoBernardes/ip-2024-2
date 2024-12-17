#include <stdio.h>

/* Definição da estrutura tRacional para representar um número racional */
typedef struct {
    int numerador;   // Numerador do número racional
    int denominador; // Denominador do número racional
} tRacional;

/* 
 * Função para calcular o Máximo Divisor Comum (MDC) entre dois números inteiros.
 * Utiliza o algoritmo de Euclides.
 */
int MDC(int x, int y) {
    if (y == 0) return x;    // Se o divisor é zero, o MDC é o próprio número
    return MDC(y, x % y);    // Chama recursivamente até que o resto seja zero
}

/* 
 * Função para criar um número racional simplificado.
 * Divide o numerador e o denominador pelo MDC.
 * Garante que o denominador seja sempre positivo.
 */
tRacional racional(int a, int b) {
    tRacional r;
    int mdc = MDC(a, b);           // Calcula o MDC entre o numerador e o denominador
    r.numerador = a / mdc;         // Simplifica o numerador
    r.denominador = b / mdc;       // Simplifica o denominador

    // Garante que o denominador seja positivo
    if (r.denominador < 0) {
        r.numerador = -r.numerador;
        r.denominador = -r.denominador;
    }
    return r;
}

/* 
 * Função para retornar o negativo de um número racional.
 * Inverte o sinal do numerador.
 */
tRacional negativo(tRacional r) {
    r.numerador = -r.numerador; // Troca o sinal do numerador
    return r;
}

/* 
 * Função para somar dois números racionais.
 * Soma dois racionais utilizando o MMC (mínimo múltiplo comum) dos denominadores.
 */
tRacional soma(tRacional r1, tRacional r2) {
    int num = r1.numerador * r2.denominador + r2.numerador * r1.denominador; // Soma cruzada
    int den = r1.denominador * r2.denominador; // Produto dos denominadores
    return racional(num, den); // Simplifica e retorna o resultado
}

/* 
 * Função para multiplicar dois números racionais.
 * Multiplica os numeradores e os denominadores diretamente.
 */
tRacional mult(tRacional r1, tRacional r2) {
    return racional(r1.numerador * r2.numerador, r1.denominador * r2.denominador);
}

/* 
 * Função para dividir dois números racionais.
 * Multiplica o primeiro racional pelo inverso do segundo.
 */
tRacional div(tRacional r1, tRacional r2) {
    return racional(r1.numerador * r2.denominador, r1.denominador * r2.numerador);
}

int main() {
    int a1, b1, a2, b2;  // Numeradores e denominadores dos dois números racionais
    char operacao;       // Operador para definir a operação (+, -, *, /)

    /* Leitura de entrada até o final do arquivo (EOF) */
    while (scanf("%d %d %c %d %d", &a1, &b1, &operacao, &a2, &b2) != EOF) {
        tRacional r1 = racional(a1, b1); // Cria o primeiro racional simplificado
        tRacional r2 = racional(a2, b2); // Cria o segundo racional simplificado
        tRacional resultado;             // Armazena o resultado da operação

        /* Realiza a operação com base no operador */
        if (operacao == '+') {
            resultado = soma(r1, r2); // Soma dos dois racionais
        } else if (operacao == '-') {
            resultado = soma(r1, negativo(r2)); // Subtrai invertendo o sinal do segundo racional
        } else if (operacao == '*') {
            resultado = mult(r1, r2); // Multiplicação dos dois racionais
        } else if (operacao == '/') {
            resultado = div(r1, r2); // Divisão dos dois racionais
        }

        /* Imprime o resultado no formato "numerador denominador" */
        printf("%d %d\n", resultado.numerador, resultado.denominador);
    }

    return 0;
}

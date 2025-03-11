#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 50

typedef struct {
    double coeficiente;
    int expoente; 
} Termo;

/* Função para somar ou subtrair dois polinômios */
void somaOuSubtraiPolinomios(Termo p1[], int n1, Termo p2[], int n2, char operacao) {
    Termo resultado[MAX_TERMS];
    int i = 0, j = 0, k = 0, t;

    // Percorre os dois polinômios simultaneamente
    while (i < n1 && j < n2) {
        if (p1[i].expoente == p2[j].expoente) {
            // Caso os expoentes sejam iguais
            double coeficiente_resultante;
            if (operacao == '+') {
                coeficiente_resultante = p1[i].coeficiente + p2[j].coeficiente;
            } else { // Subtração
                coeficiente_resultante = p1[i].coeficiente - p2[j].coeficiente;
            }

            if (coeficiente_resultante != 0.0) { // Ignora termos com coeficiente zero
                resultado[k].expoente = p1[i].expoente;
                resultado[k].coeficiente = coeficiente_resultante;
                k++;
            }
            i++;
            j++;
        } else if (p1[i].expoente > p2[j].expoente) {
            // Caso o termo do primeiro polinômio tenha expoente maior
            resultado[k] = p1[i];
            k++;
            i++;
        } else {
            // Caso o termo do segundo polinômio tenha expoente maior
            resultado[k].expoente = p2[j].expoente;
            if (operacao == '+') {
                resultado[k].coeficiente = p2[j].coeficiente;
            } else { // Subtração
                resultado[k].coeficiente = -p2[j].coeficiente;
            }
            k++;
            j++;
        }
    }

    // Adiciona os termos restantes do primeiro polinômio
    while (i < n1) {
        resultado[k] = p1[i];
        k++;
        i++;
    }

    // Adiciona os termos restantes do segundo polinômio (ajustando sinal se for subtração)
    while (j < n2) {
        resultado[k].expoente = p2[j].expoente;
        if (operacao == '+') {
            resultado[k].coeficiente = p2[j].coeficiente;
        } else { // Subtração
            resultado[k].coeficiente = -p2[j].coeficiente;
        }
        k++;
        j++;
    }

    // Impressão do polinômio resultante com ajuste para o sinal explícito
    for (t = 0; t < k; t++) {
        if (resultado[t].coeficiente < 0) {
            printf("-"); // Imprime sinal de negativo explicitamente
            if (resultado[t].expoente == 0) {
                printf("%.2lf", -resultado[t].coeficiente);
            } else {
                printf("%.2lfX^%d", -resultado[t].coeficiente, resultado[t].expoente);
            }
        } else {
            if (t > 0) {
                printf("+"); // Adiciona o sinal de adição para coeficientes positivos
            }
            if (resultado[t].expoente == 0) {
                printf("%.2lf", resultado[t].coeficiente);
            } else {
                printf("%.2lfX^%d", resultado[t].coeficiente, resultado[t].expoente);
            }
        }
    }
    printf("\n");
}

int main() {
    int casos_teste, n1, n2;
    int i;
    char operacao;

    scanf("%d", &casos_teste);

    while (casos_teste--) {
        Termo p1[MAX_TERMS], p2[MAX_TERMS];
        scanf(" %c", &operacao);

        // Leitura do primeiro polinômio
        scanf("%d", &n1);
        for (i = 0; i < n1; i++) {
            scanf("%lf %d", &p1[i].coeficiente, &p1[i].expoente);
        }

        // Leitura do segundo polinômio
        scanf("%d", &n2);
        for (i = 0; i < n2; i++) {
            scanf("%lf %d", &p2[i].coeficiente, &p2[i].expoente);
        }

        // Soma ou subtração dos polinômios
        somaOuSubtraiPolinomios(p1, n1, p2, n2, operacao);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ID_SIZE 4

typedef struct {
    char code[ID_SIZE]; // Identificador do polinômio
    int p;              // Grau máximo do polinômio
    double* coef;       // Ponteiro para os coeficientes do polinômio
} Poly;

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Linha de comando inválida\n");
        return 1;
    }

    // Argumentos da linha de comando
    const char* poly_string = argv[1];
    const char* file_name = argv[2];

    // Inicializa a estrutura Poly
    Poly poly = { "poly", 0, NULL };

    // Determinar o grau máximo do polinômio
    int grau_max = 0;
    const char* ptr = poly_string;

    // Percorre a string para encontrar o maior expoente
    while (*ptr) {
        int pot;
        if (sscanf(ptr, "%*lfx^%d", &pot) == 1) {
            if (pot > grau_max) grau_max = pot;
        }
        // Avança para o próximo termo
        while (*ptr && *ptr != '+' && *ptr != '-') ptr++;
        if (*ptr) ptr++; // Avança o sinal
    }
    poly.p = grau_max;

    // Alocar memória para todos os coeficientes
    poly.coef = (double*)calloc(grau_max + 1, sizeof(double));
    if (poly.coef == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return 1;
    }

    // Processar a string para preencher os coeficientes
    ptr = poly_string;
    while (*ptr) {
        double coef;
        int pot;

        if (sscanf(ptr, "%lfx^%d", &coef, &pot) == 2) {
            poly.coef[pot] = coef; // Armazena o coeficiente na posição correspondente
        } else if (sscanf(ptr, "%lf", &coef) == 1) {
            poly.coef[0] = coef; // Termo independente
        }

        // Avança para o próximo termo
        while (*ptr && *ptr != '+' && *ptr != '-') ptr++;
        if (*ptr) ptr++; // Avança o sinal
    }

    // Escrever os dados no arquivo binário
    FILE* file = fopen(file_name, "wb");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        free(poly.coef);
        return 1;
    }

    fwrite(poly.code, sizeof(char), ID_SIZE, file);           // Escreve o identificador
    fwrite(&(poly.p), sizeof(int), 1, file);                 // Escreve o grau máximo
    fwrite(poly.coef, sizeof(double), poly.p + 1, file);     // Escreve os coeficientes

    fclose(file);
    printf("Polinômio salvo no arquivo '%s'.\n", file_name);

    // Libera memória
    free(poly.coef);

    return 0;
}

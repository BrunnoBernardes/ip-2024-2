#include <stdio.h>
#include <stdlib.h>

#define ID_SIZE 4

typedef struct {
    char code[ID_SIZE]; // Identificador do polinômio
    int p;              // Grau máximo do polinômio
    double* coef;       // Ponteiro para os coeficientes
} Poly;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Linha de comando inválida\n");
        return 1;
    }

    const char* file_name = argv[1];

    // Abrir o arquivo binário para leitura
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Estrutura para armazenar os dados do polinômio
    Poly poly;

    // Ler os dados do arquivo
    fread(poly.code, sizeof(char), ID_SIZE, file);  // Lê o identificador
    fread(&(poly.p), sizeof(int), 1, file);         // Lê o grau máximo

    // Alocar memória para os coeficientes
    poly.coef = (double*)malloc((poly.p + 1) * sizeof(double));
    if (poly.coef == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        fclose(file);
        return 1;
    }

    fread(poly.coef, sizeof(double), poly.p + 1, file); // Lê os coeficientes
    fclose(file);

    // Exibir o polinômio no formato desejado
    printf("\"");
    int first_term = 1; // Flag para evitar sinais desnecessários no primeiro termo
    for (int i = poly.p; i >= 0; i--) {
        if (poly.coef[i] != 0.0) {
            if (!first_term && poly.coef[i] > 0) {
                printf("+"); // Adiciona "+" entre termos
            }

            if (i == 0) {
                printf("%.1lf", poly.coef[i]); // Termo independente
            } else if (poly.coef[i] == 1.0) {
                printf("x^%d", i); // Termo com coeficiente 1 positivo
            } else if (poly.coef[i] == -1.0) {
                printf("-x^%d", i); // Termo com coeficiente -1
            } else {
                printf("%.1lfx^%d", poly.coef[i], i); // Termo geral
            }

            first_term = 0; // Atualiza a flag após o primeiro termo
        }
    }
    printf("\"\n");

    // Libera memória alocada
    free(poly.coef);

    return 0;
}

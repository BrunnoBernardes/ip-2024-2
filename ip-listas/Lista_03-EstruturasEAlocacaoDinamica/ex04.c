#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Estrutura para representar um vetor 4D
typedef struct {
    double au;      // Componente U do vetor
    double ax;      // Componente X do vetor
    double ay;      // Componente Y do vetor
    double az;      // Componente Z do vetor
    double norma;   // Norma (magnitude) do vetor
} vetor;

// Função para trocar dois vetores
void trocar(vetor* a, vetor* b) {
    vetor temp = *a;
    *a = *b;
    *b = temp;
}

int main() {

    int N;

    // Lê o número de vetores
    scanf("%d", &N);

    // Valida o número de vetores
    if (N < 1 || N > 1000) {
        return 0;
    }

    int i, j;
    vetor* lista = NULL;

     // Aloca memória para a lista de vetores
    lista = (vetor*)malloc(N * sizeof(vetor));
    if (!lista) {
        return 0; // Encerra o programa se a alocação falhar
    }

    for (i = 0; i < N; i++)
    {
        scanf("%lf %lf %lf %lf", &lista[i].au, &lista[i].ax, &lista[i].ay, &lista[i].az);
        
        // Verifica se os valores dos componentes estão dentro do intervalo válido
        if (lista[i].au < -1000 || lista[i].au > 1000 || 
            lista[i].ax < -1000 || lista[i].ax > 1000 || 
            lista[i].ay < -1000 || lista[i].ay > 1000 || 
            lista[i].az < -1000 || lista[i].az > 1000) {
            free(lista);
            return 0;    
        }

        // Calcula a norma do vetor
        lista[i].norma = sqrt(lista[i].au * lista[i].au + 
                              lista[i].ax * lista[i].ax + 
                              lista[i].ay * lista[i].ay + 
                              lista[i].az * lista[i].az);
    }

    // Ordenação manual (Bubble Sort) em ordem crescente
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - i - 1; j++) {
            if (lista[j].norma > lista[j + 1].norma) {
                trocar(&lista[j], &lista[j + 1]); // Troca os vetores se necessário
            }
        }
    }

    // Exibe os vetores e suas normas na ordem crescente
    for (i = 0; i < N; i++) {
        printf("Vetor: (%.2lf, %.2lf, %.2lf, %.2lf) Norma: %.2lf\n", 
               lista[i].au, lista[i].ax, lista[i].ay, lista[i].az, lista[i].norma);
    }

    free(lista);

    return 0;
}
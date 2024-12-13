#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Estrutura para representar um ponto 3D
typedef struct {
    double u;
    double x;
    double y;
    double z;
} Ponto;

int main () {

    int N;
    int i, j;
    double dist;
    Ponto *pontos = NULL;

    // Lê o número de pontos
    scanf("%d", &N);
    if (N < 2 || N > 1000) { // Valida o número de pontos
        return 0;
    }

    // Aloca memória para a lista de pontos
    pontos = (Ponto*)malloc(N * sizeof(Ponto));
    if (!pontos) { // Encerra o programa se a alocação falhar
        return 0;
    }

    // Lê os dados dos pontos
    for (i = 0; i < N; i++) {
        scanf("%lf %lf %lf %lf", &pontos[i].u, &pontos[i].x, &pontos[i].y, &pontos[i].z);
        if (pontos[i].u < -1000 || pontos[i].u > 1000 || 
            pontos[i].x < -1000 || pontos[i].x > 1000 || 
            pontos[i].y < -1000 || pontos[i].y > 1000 || 
            pontos[i].z < -1000 || pontos[i].z > 1000) { // Valida os valores dos componentes
            free(pontos);
            return 0;
        }
    }

    // Calcula a distância entre os pontos
    for (i = 0; i < N - 1; i++) {
        dist = sqrt((pontos[i].u - pontos[i + 1].u) * (pontos[i].u - pontos[i + 1].u) +
                        (pontos[i].x - pontos[i + 1].x) * (pontos[i].x - pontos[i + 1].x) +
                        (pontos[i].y - pontos[i + 1].y) * (pontos[i].y - pontos[i + 1].y) +
                        (pontos[i].z - pontos[i + 1].z) * (pontos[i].z - pontos[i + 1].z));
            printf("%.2lf\n", dist); // Imprime a distância entre os pontos
        
    }

    // Libera a memória alocada
    free(pontos);

    return 0;
}
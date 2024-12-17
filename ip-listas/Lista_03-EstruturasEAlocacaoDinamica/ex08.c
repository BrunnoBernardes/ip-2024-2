#include <stdio.h>
#include <stdlib.h>

#define MAX1 100
#define MAX2 500

typedef struct {
    int codigo;
    float valor_por_credito;
    char nome[MAX1];
} Curso;

typedef struct {
    char nome[MAX2];
    int codigo_curso;
    int num_creditos;
} Aluno;

int main() {
    int num_cursos, num_alunos, i, j;
    Curso* cursos = NULL;
    Aluno* alunos = NULL; 

    // Lê o número de cursos
    scanf("%d", &num_cursos);

    // Valida o número de cursos
    if (num_cursos < 1 || num_cursos > 30) {
        return 0; // Encerra o programa se o número de cursos for inválido
    }

    // Aloca memória para a lista de cursos
    cursos = (Curso*)malloc(num_cursos * sizeof(Curso));
    if (!cursos) {
        return 0; // Encerra o programa se a alocação falhar
    }

    // Lê os dados dos cursos
    for (i = 0; i < num_cursos; i++) {
        scanf("%d %f %[^\n]%*c", &cursos[i].codigo, &cursos[i].valor_por_credito, cursos[i].nome);
    }

    // Lê o número de alunos
    scanf("%d", &num_alunos);

    // Valida o número de alunos
    if (num_alunos < 1 || num_alunos > 1000) {
        free(cursos);
        return 0; // Encerra o programa se o número de alunos for inválido
    }

    // Aloca memória para a lista de alunos
    alunos = (Aluno*)malloc(num_alunos * sizeof(Aluno));
    if (!alunos) {
        free(cursos);
        return 0; // Encerra o programa se a alocação falhar
    }

    // Lê os dados dos alunos
    for (i = 0; i < num_alunos; i++) {
        scanf("%*c%[^\n] %d %d", alunos[i].nome, &alunos[i].codigo_curso, &alunos[i].num_creditos);
    }

    // Imprime os dados dos alunos
    for (i = 0; i < num_alunos; i++) {
        for (j = 0; j < num_cursos; j++) {
            if (alunos[i].codigo_curso == cursos[j].codigo) {
                printf("Aluno(a): %s ", alunos[i].nome);
                printf("Curso: %s ", cursos[j].nome);
                printf("Num. Creditos: %d ", alunos[i].num_creditos);
                printf("Valor Credito: %.2f ", cursos[j].valor_por_credito);
                printf("Mensalidade: %.2f\n", cursos[j].valor_por_credito * alunos[i].num_creditos);
                break;
            }
        }

    } 

    free(cursos);
    free(alunos);

    return 0;
}
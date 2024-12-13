#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um aluno
typedef struct {
    int mat;
    int dia_n;
    int mes_n;
    int ano_n;
    char nome[200];
} Aluno;

// Função para comparar a data de nascimento de dois alunos
int ComparaDataNasc (Aluno *aluno1, Aluno *aluno2) {
    if (aluno1->ano_n < aluno2->ano_n) {
        return 0; // aluno2 é mais novo
    } else if (aluno1->ano_n > aluno2->ano_n) {
        return 1; // aluno1 é mais novo
    } else {
        if (aluno1->mes_n < aluno2->mes_n) {
            return 0; // aluno2 é mais novo
        } else if (aluno1->mes_n > aluno2->mes_n) {
            return 1; // aluno1 é mais novo
        } else {
            if (aluno1->dia_n < aluno2->dia_n) {
                return 0; // aluno2 é mais novo
            } else if (aluno1->dia_n > aluno2->dia_n) {
                return 1; // aluno1 é mais novo
            } else {
                return 1; // alunos têm a mesma data de nascimento
            }
        }
    }
}

int main () {
    
    int n;
    int i, j;
    Aluno *alunos = NULL;

    // Lê o número de alunos
    scanf("%d", &n);
    if (n < 1 || n > 30) { // Valida o número de alunos
        return 0;
    }

    // Aloca memória para a lista de alunos
    alunos = (Aluno*)malloc(n * sizeof(Aluno));
    if (!alunos) { // Encerra o programa se a alocação falhar
        return 0;
    }

    // Lê os dados dos alunos
    for (i = 0; i < n; i++) {
        scanf("%d %d %d %d %[^\n]%*c", &alunos[i].mat, &alunos[i].dia_n, &alunos[i].mes_n, &alunos[i].ano_n, alunos[i].nome);
    }

    // Ordena os alunos por data de nascimento
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (!ComparaDataNasc(&alunos[i], &alunos[j])) {
                Aluno tmp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = tmp;
            }
        }
    }

    // Imprime os alunos ordenados
    for (i = 0; i < n; i++) {
        printf("Matric.: %d Nome: %s Data Nasc: %d/%d/%d\n", alunos[i].mat, alunos[i].nome, alunos[i].dia_n, alunos[i].mes_n, alunos[i].ano_n);
    }

    // Libera a memória alocada
    free(alunos);

    return 0;
}
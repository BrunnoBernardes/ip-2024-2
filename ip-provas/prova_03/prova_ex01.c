#include <stdio.h>
#include <stdlib.h>
 
#define SALARIO_MINIMO 1200.00
 
typedef struct {
    int matricula;
    int idade;
    int numFilhos;
    char sexo;
    double salario;
} Funcionario;
 
int idadeSuperior_salarioSuperior (Funcionario *lista, int N) {
 
    int i;
    double mediaIdades = 0;
    int numFuncionarios = 0;
 
    // Soma as idades dos funcionários
    for (i = 0; i < N; i++) {
        mediaIdades += lista[i].idade;
    }
 
    // Faz a média das idades
    mediaIdades = mediaIdades/N;
 
    // Verifica a quantidade de funcionários que atende ao requisito
    for (i = 0; i < N; i++) {
        if (lista[i].idade > mediaIdades && lista[i].salario > 3*SALARIO_MINIMO) {
            numFuncionarios += 1; // Adiciona +1 à quantidade de funcionários
        }
    }
 
    return numFuncionarios;
}
 
int mulherFilhos (Funcionario *lista, int N) {
 
    int i;
    double mediaFilhos = 0;
    int numFuncionarios = 0;
 
    // Soma os filhos dos funcionários
    for (i = 0; i < N; i++) {
        mediaFilhos += lista[i].numFilhos;
    }
 
    // Faz a média dos filhos
    mediaFilhos = mediaFilhos/N;
 
    // Verifica a quantidade de funcionários que atende ao requisito
    for (i = 0; i < N; i++) {
        if (lista[i].sexo == 'F') {
            if (lista[i].numFilhos > mediaFilhos) {
                numFuncionarios += 1; // Adiciona +1 à quantidade de funcionários
            }
        }
    }
 
    return numFuncionarios;
}
 
int homemFilhos (Funcionario *lista, int N) {
 
    int i;
    double mediaFilhos = 0;
    int numFuncionarios = 0;
 
    // Soma os filhos dos funcionários
    for (i = 0; i < N; i++) {
        mediaFilhos += lista[i].numFilhos;
    }
 
    // Faz a média dos filhos
    mediaFilhos = mediaFilhos/N;
 
    // Verifica a quantidade de funcionários que atende ao requisito
    for (i = 0; i < N; i++) {
        if (lista[i].sexo == 'M') {
            if (lista[i].numFilhos > mediaFilhos) {
                numFuncionarios += 1; // Adiciona +1 à quantidade de funcionários
            }
        }
    }
 
    return numFuncionarios;
}
 
int anosRenda (Funcionario *lista, int N) {
 
    int i;
    int numFuncionarios = 0;
 
    // Verifica a quantidade de funcionários que atende ao requisito
    for (i = 0; i < N; i++) {
        if (lista[i].idade > 47 && lista[i].salario/(lista[i].numFilhos + 1) < 2*SALARIO_MINIMO) {  
            numFuncionarios += 1; // Adiciona +1 à quantidade de funcionários
        }
    }
 
    return numFuncionarios;
}
 
int main () {
 
    int N;
 
    // Lê o número de funcionários
    scanf("%d", &N);
 
    // Valida o número de funcionários
    if (N <= 1 || N >= 500) {
        return 0;
    }
 
    int i;
    Funcionario *lista = NULL;
 
    // Aloca memória para a lista de funcionários
    lista = (Funcionario*)malloc(N * sizeof(Funcionario));
    if (!lista) {
        return 0; // Encerra o programa se a alocação falhar
    }
 
    // Lê os dados de cada funcionário
    for (i = 0; i < N; i++) {
 
        scanf("%d %d %d%*c%c %lf", &lista[i].matricula,
                                   &lista[i].idade,
                                   &lista[i].numFilhos,
                                   &lista[i].sexo,
                                   &lista[i].salario);
 
    }
 
    // Quantidade de funcionários com idade superior a média de idades E salário superior a 3 salários mínimos
    int saida1 = idadeSuperior_salarioSuperior (lista, N);
    
    // Quantidade de mulheres que possuem quantidade de filhos acima da média geral.
    int saida2 = mulherFilhos (lista, N);
    
    // Quantidade de homens que possuem quantidade de filhos acima da média geral.
    int saida3 = homemFilhos (lista, N);
    
    // Quantidade de funcionários maiores de 47 anos com renda per-capita (por pessoa) abaixo de 2 salários mínimos.
    int saida4 = anosRenda (lista, N);
 
    // Imprime a saida desejada
    printf ("%d %d %d %d\n", saida1, saida2, saida3, saida4);
 
    // Libera memória alocada
    free(lista);
 
    return 0;
}
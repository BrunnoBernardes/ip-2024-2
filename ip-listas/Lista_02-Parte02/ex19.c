#include <stdio.h>
#include <string.h>

#define MAX 1001 // Tamanho máximo 1 ≤ |A| ≤ 10e4

/*--------------------------------------------------------------*/
// Função que avança a stringA até que ela seja igual a stringB
/*--------------------------------------------------------------*/

void avance(char *stringA, char *stringB)
{
    int i, count = 0;
    int tamanho = strlen(stringA);
    for (i = 0; i < tamanho; i++){
        while (stringA[i] != stringB[i]){
            stringA[i]++; 
            if (stringA[i] > 'z') stringA[i] = 'a'; // Se o caractere em stringA ultrapassar 'z', volta para 'a' (ciclo alfabético)
            count++;
        }
    }
    printf("%d\n", count); // Total de operações necessárias
}

/*-------------*/
// Função main
/*-------------*/

int main ()
{
    int i, T;
    char stringA[MAX], stringB[MAX];

    scanf("%d", &T); // Número de casos de teste

    if (T <= 0 || T > 100) return 1; // Limite válido para T

    for (i = 0; i < T; i++){
        scanf("%s %s", stringA, stringB);
        avance(stringA, stringB);
    }
    return 0;
}
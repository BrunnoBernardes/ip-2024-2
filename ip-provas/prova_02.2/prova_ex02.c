#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 2050

// Função para verificar quantas vezes a palavra aparece no texto
void verifica(const char txt[MAX], const char pal[MAX]) {
    int i = 0, count = 0, k = 0, vf = 0;
    int tam2 = strlen(pal); // Tamanho da palavra

    // Percorre a string texto
    while (txt[i] != '\0') {
        // Verifica se há correspondência com a palavra (considerando o caso)
        if (txt[i] == pal[k]) {
            k++;
            count++;

            if (count == tam2) { // Palavras coincidem
                if (tam2 == 1) { // Caso a palavra tenha tamanho 1
                    // Verifica se está isolada
                    if ((i == 0 || !isalnum(txt[i - 1])) && (!isalnum(txt[i + 1]))) {
                        vf++;
                    }
                } else { // Palavras maiores que 1
                    // Verifica se não faz parte de outra palavra
                    if (!isalnum(txt[i + 1])) {
                        vf++;
                    }
                }
                k = 0;
                count = 0;
            }
        } else {
            k = 0;
            count = 0;
        }

        i++;
    }

    // Imprime a palavra e sua contagem
    if (vf > 0) {
        printf("(%s) %d\n", pal, vf);
    }
}

int main() {
    char txt[MAX], pal[MAX];
    int i = 0, k = 0;

    // Leitura do texto
    scanf("%[^\n]", txt);

    // Processa cada palavra do texto
    while (txt[i] != '\0') {
        if (isalnum(txt[i])) { // Adiciona apenas caracteres válidos
            pal[k++] = txt[i];
        } else if (k > 0) { // Finaliza uma palavra ao encontrar separador
            pal[k] = '\0'; // Fecha a string da palavra
            verifica(txt, pal); // Verifica a ocorrência da palavra
            k = 0; // Reseta índice da palavra
        }

        i++;
    }

    // Verifica a última palavra
    if (k > 0) {
        pal[k] = '\0';
        verifica(txt, pal);
    }

    return 0;
}

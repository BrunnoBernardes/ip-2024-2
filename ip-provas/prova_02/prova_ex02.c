#include <stdio.h>

#define MAX 257 // Tamanho máximo da string

/*---------------------------------------------------------------------------*/
// Função remove_vogais
// Conta e remove as vogais de uma string, imprimindo os caracteres restantes.
// A função também atualiza o array de contagem de vogais.
/*---------------------------------------------------------------------------*/
void remove_vogais(char str[MAX], int vogais[5])
{
    int i = 0;
    
    while (str[i] != '\0')
    {
        // Conta cada vogal encontrada
        if (str[i] == 'a' || str[i] == 'A')
        {
            vogais[0]++;
        }
        else if (str[i] == 'e' || str[i] == 'E')
        {
            vogais[1]++;
        }
        else if (str[i] == 'i' || str[i] == 'I')
        {
            vogais[2]++;
        }
        else if (str[i] == 'o' || str[i] == 'O')
        {
            vogais[3]++;
        }
        else if (str[i] == 'u' || str[i] == 'U')
        {
            vogais[4]++;
        }
        else
        {
            printf("%c", str[i]); // Imprime caracteres que não são vogais
        }
        i++;
    }
    printf("\n"); // Nova linha após a string sem vogais
}

/*--------------------------------------------------*/
// Função principal
// Lê uma string, remove suas vogais e imprime
// o número de ocorrências de cada vogal encontrada.
/*--------------------------------------------------*/
int main()
{
    char str[MAX];
    int vogais[5] = {0, 0, 0, 0, 0}; // Array para contar vogais: a, e, i, o, u

    // Lê a string de entrada
    scanf("%[^\n]", str);

    // Remove vogais e atualiza a contagem
    remove_vogais(str, vogais);

    // Imprime a contagem de cada vogal
    printf("a: %d\n", vogais[0]);
    printf("e: %d\n", vogais[1]);
    printf("i: %d\n", vogais[2]);
    printf("o: %d\n", vogais[3]);
    printf("u: %d\n", vogais[4]);

    return 0;
}

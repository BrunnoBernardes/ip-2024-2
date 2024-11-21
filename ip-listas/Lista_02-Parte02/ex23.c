#include <stdio.h>
#include <ctype.h>

#define MAX 51 // Tamanho máximo da string

/*----------------------------------------------------------------------------------------------------*/
// Função principal
// Alterna entre letras maiúsculas e minúsculas em uma string, ignorando caracteres que não são letras.
/*----------------------------------------------------------------------------------------------------*/
int main()
{
    int i, upper;
    char str[MAX];

    // Processa múltiplas entradas enquanto não atingir o final do arquivo
    while (scanf("%50[^\n]%*c", str) != EOF)
    {
        upper = 1; // Define que a primeira letra deve ser maiúscula
        for (i = 0; str[i] != '\0'; i++)
        {
            // Verifica se o caractere atual é uma letra
            if (isalpha(str[i]))
            {
                if (upper)
                {
                    str[i] = toupper(str[i]); // Converte para maiúscula
                    upper = 0; // Alterna para minúscula na próxima letra
                }
                else
                {
                    str[i] = tolower(str[i]); // Converte para minúscula
                    upper = 1; // Alterna para maiúscula na próxima letra
                }
            }
        }
        printf("%s\n", str); // Imprime a string processada
    }

    return 0;
}

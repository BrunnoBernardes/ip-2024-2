#include <stdio.h>

#define N 256+1 // Definição de tamanho máximo para as strings

/*-------------------------------------------------------------*/
// Função str_clean
// Remove todos os caracteres de "clr" presentes na string "str"
/*-------------------------------------------------------------*/
void str_clean(char *str, char *clr)
{
    int i, j, k;
    for (i = 0; str[i] != '\0'; i++)
    {
        for (j = 0; clr[j] != '\0'; j++)
        {
            if (str[i] == clr[j]) // Verifica se o caractere atual de "str" está em "clr"
            {
                // Realiza o deslocamento dos caracteres para remover o caractere indesejado
                for (k = i; str[k] != '\0'; k++)
                {
                    str[k] = str[k + 1];
                }
                i--; // Ajusta o índice para verificar novamente a posição atual
                break; // Sai do loop interno após encontrar um caractere indesejado
            }
        }
    }
}

/*-----------------*/
// Função Principal
/*-----------------*/
int main()
{
    char str[N];
    char clr[N];

    scanf("%[^\n]%*c", str);

    scanf("%[^\n]%*c", clr);

    str_clean(str, clr);

    printf("%s\n", str);

    return 0;
}

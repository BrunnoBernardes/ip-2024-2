#include <stdio.h>

#define MAX_WORDS 200 // Número máximo de palavras
#define MAX_LEN 64+1 // Tamanho máximo de cada palavra

int str_split(char *string, char words[MAX_WORDS][MAX_LEN], char *sep)
{
    int i = 0, j = 0, k = 0;

    while (string[i] != '\0')
    {
        if (string[i] == sep[0])
        {
            words[j][k] = '\0';
            j++;
            k = 0;
        }
        else
        {
            words[j][k] = string[i];
            k++;
        }
        i++;
    }

    words[j][k] = '\0';

    for (i = 0; i <= j; i++)
    {
        printf("%s\n", words[i]);
    }

    return j;
}

int main ()
{
    char string; // String que armazena todas as palavras
    char sep; // Separador de palavras
    char words[MAX_WORDS][MAX_LEN]; // Matriz de palavras

    scanf("%[^\n]%*c", string);
    scanf("%[^\n]%*c", sep);

    str_split(&string, words, &sep);


    return 0;
}
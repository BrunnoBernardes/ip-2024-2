#include <stdio.h>
 
 /*---------------------------------------------------------------------*/
// Extrai as iniciais das palavras em um texto e armazena no array 'pal'.
/*----------------------------------------------------------------------*/

void verifica_iniciais(char *txt, char *pal)
{
    int i = 0, c = 0;
    while(txt[i] != '\0')
    {
        if (txt[i] == ' ') // Armazena a primeira letra da palavra após um espaço
        {
            pal[c] = txt[i+1];
            c++;
        }
        else if(i == 0) // Armazena a primeira letra do texto (primeira palavra)
        {
            pal[c] = txt[i];
            c++;
        }
        i++;
    }
    pal[c] = '\0'; // Finaliza a string de iniciais
}

/*-------------------------------------------------------------*/
// Converte todas as letras maiúsculas de 'pal' para minúsculas.
/*-------------------------------------------------------------*/

void tudo_minusculo(char *pal)
{
    int i = 0;
    while(pal[i] != '\0')
    {
        if (pal[i] >= 'A' && pal[i] <= 'Z')
            pal[i] += 32;
        i++;
    }
}

/*----------------------------------------------------------------------------------------------*/
// Verifica a quantidade de aliterações em um conjunto de iniciais de palavras e imprime o total.
/*----------------------------------------------------------------------------------------------*/

void verifica_aliteracao(char *pal)
{
    int i = 0, al = 0;
    char ultimo = '0';
    while(pal[i] != '\0')
    {
        if (pal[i] == pal[i+1] && pal[i] != ultimo) // Conta uma aliteração se a letra atual for igual à próxima e não for igual à última contada
            {
            al++;
            }
        ultimo = pal[i]; // Atualiza o último caractere considerado para evitar duplicações
        i++;
    }
    printf("%d\n", al); // Imprime o total de aliterações encontradas
}

/*------------*/
// Função main	
/*------------*/

int main ()
{
    char txt [5000], pal[100];
    while(scanf("%[^\n]%*c", txt) != EOF)
    {
        verifica_iniciais(txt, pal);
        tudo_minusculo(pal);
        verifica_aliteracao(pal);
    }
    return 0;
}
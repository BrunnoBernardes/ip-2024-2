#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 201 // Número máximo de caracteres para cada linha de entrada

/* ----------------------------------------------------------
   Função: minusculas
   Converte todos os caracteres de uma string para minúsculas.
   ---------------------------------------------------------- */
void minusculas(char *txt)
{
    int i;
    for (i = 0; txt[i] != '\0'; i++)
    {
        txt[i] = tolower(txt[i]);
    }
}

/* -------------------------------------------------------
   Função: print_maior_frequencia
   Imprime as letras com a maior frequência de ocorrência.
   ------------------------------------------------------- */
void print_maior_frequencia(int *ch)
{
    int i, freq_max = 0;

    // Encontrar a maior frequência entre as letras
    for (i = 0; i < 26; i++)
    {
        if (ch[i] > freq_max)
        {
            freq_max = ch[i];
        }
    }

    // Imprimir todas as letras que possuem a maior frequência
    for (i = 0; i < 26; i++)
    {
        if (ch[i] == freq_max)
        {
            printf("%c", i + 'a'); // Converte o índice para a letra correspondente
        }
    }
    printf("\n"); // Nova linha após imprimir as letras
}

/* --------------------------------------------------------
   Função: maior_frequencia
   Identifica as letras com maior frequência em uma string.
   -------------------------------------------------------- */
void maior_frequencia(char *txt)
{
    int i;
    int ch[26] = {0}; // Vetor para armazenar a frequência de cada letra (a-z)

    // Contabilizar as ocorrências de cada letra
    for (i = 0; txt[i] != '\0'; i++)
    {
        if (isalpha(txt[i])) // Considerar apenas caracteres alfabéticos
        {
            ch[txt[i] - 'a']++; // Incrementar a posição correspondente à letra
        }
    }

    // Imprimir as letras com maior frequência
    print_maior_frequencia(ch);
}

/* ---------------------------------------
   Função: main
   Controla o fluxo principal do programa.
   --------------------------------------- */
int main()
{
    int n, i;
    char txt[N];

    // Ler o número de linhas de entrada
    scanf("%d%*c", &n);

    // Processar cada linha
    for (i = 0; i < n; i++)
    {
        // Ler uma linha inteira ignorando o caractere de nova linha
        scanf("%[^\n]%*c", txt);

        // Converter o texto para letras minúsculas
        minusculas(txt);

        // Encontrar e imprimir as letras de maior frequência
        maior_frequencia(txt);
    }

    return 0;
}
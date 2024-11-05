#include <stdio.h>
#include <ctype.h>
#define N 10000

int main()
{
    int n, i, j = 0, count_letras = 0, count_vogais = 0, count_consoantes = 0, count_espacos = 0;
    char linha[N];
    scanf("%d", &n);
    getchar();

    for (i = 0; i < n; i++)
    {
        count_consoantes = 0;
        count_letras = 0;
        count_vogais = 0;
        j = 0;
        scanf("%[^\n]%*c", linha);
        while (linha[j] != '\0')
        {

            if (linha[j] == 'a' || linha[j] == 'e' || linha[j] == 'i' || linha[j] == 'o' || linha[j] == 'u' || linha[j] == 'A' || linha[j] == 'E' || linha[j] == 'I' || linha[j] == 'O' || linha[j] == 'U')
            {
                count_vogais++;
                count_letras++;
            }
            else if (isalpha(linha[j])) // Verifica se é uma letra
            {
                count_consoantes++;
                count_letras++;
            }

            j++;
        }
        printf("Letras = %d\nVogais = %d\nConsoantes = %d\n", count_letras, count_vogais, count_consoantes);
    }
    return 0;
}
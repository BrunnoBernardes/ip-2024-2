#include <stdio.h>


void verifica_iniciais(char *txt, char *pal)
{
    int i = 0, c = 0;
    while(txt[i] != '\0')
    {
        if (txt[i] == ' ')
        {
            pal[c] = txt[i+1];
            c++;
        }
        else if(i == 0)
        {
            pal[c] = txt[i];
            c++;
        }

        i++;
    }
}

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

void verifica_aliteracao(char *pal)
{
    int i = 0, al = 0;
    char ultimo = '0';
    while(pal[i] != '\0')
    {
        if (pal[i] == pal[i+1] && pal[i] != ultimo)
            {
            al++;
            }
        ultimo = pal[i];
        i++;
    }
    printf("%d\n", al);
}

void print_vetor(char *pal)
{
    int i = 0;
    while(pal[i] != '\0')
    {
        printf("%c", pal[i]);
        i++;
    }
    printf("\n");
}

int main ()
{
    char txt [5000], pal[100];
    int i;
    while(scanf("%[^\n]%*c", txt) != EOF)
    {
        verifica_iniciais(txt, pal);
        tudo_minusculo(pal);
        verifica_aliteracao(pal);
        print_vetor(pal);
        for(i = 0; i < 100; i++){
            pal[i] = '\0';
        }
    }
    
    return 0;
}
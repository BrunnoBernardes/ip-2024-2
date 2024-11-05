#include <stdio.h>

int tamanho_palavra ( char *palavra)
{
    int tamanho = 0;
    while(*palavra != '\0')
    {
        tamanho++;
        palavra++;
    }
    return tamanho;
}

int verificacao_palavra ( char *txt, char *palavra)
{
    int i, ocorrencias = 0;
    while(*txt != '\0')
    {
        if(*txt == *palavra){
            if(*(txt-1) == ' ')
            {
                for(i=0; i<tamanho_palavra(palavra); i++)
                {
                    if(*(txt+i) != *(palavra+i)) break;
                }
                if(i==tamanho_palavra(palavra))
                {
                    ocorrencias++;
                    txt += i - 1;
                }
            } 
        }
        
        txt++;
    }
    return ocorrencias;
}

int main ()
{
    char txt[1024];
    char palavra[32];
    scanf("%[^\n]%*c", txt );
    scanf("%s", palavra );
    printf("%d\n", tamanho_palavra(palavra));
    printf("%s (%d)\n", palavra, verificacao_palavra( txt, palavra ));
    return 0;
}
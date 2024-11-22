#include <stdio.h>
#include <stdlib.h>

#define N 128+1  // Define o tamanho máximo da string a ser lida

/*-------------------------------------------*/ 
// Função que converte uma string para inteiro
/*-------------------------------------------*/
long int string2int(const char *s)
{
    long int num = 0;  
    int i = 0;         

    // Verifica se o número é negativo
    int is_negative = (s[0] == '-');

    if (is_negative)
    {
        i++;  // Avança para o próximo caractere, ignorando o sinal '-'
    }

    // Converte a string para um inteiro, caractere por caractere
    while (s[i] != '\0')
    {
        num = num * 10 + (s[i] - '0');  // Atualiza o valor numérico acumulado
        i++;
    }

    // Ajusta o sinal do número se for negativo
    if (is_negative)
    {
        num = -num;
    }
    
    return num;  // Retorna o número convertido
}

/*-----------------*/ 
// Função Principal
/*-----------------*/
int main()
{
    char string[N];
    long int num;

    // Loop para processar cada entrada até o final do arquivo
    while (scanf("%s", string) != EOF)
    {
        num = string2int(string);  // Converte a string para inteiro
        printf("%ld %ld\n", num, num * 2);  // Imprime o número e seu dobro
    }

    return 0;
}
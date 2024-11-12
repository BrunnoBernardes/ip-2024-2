#include <stdio.h>
#include <math.h>

#define MAX 2002 // Tamanho máximo do texto

/*------------------------------------------------------------------------*/
// Função verificador_formato
// Conta o número de caracteres ';' em uma string para verificar o formato.
// Retorna o número de ocorrências encontradas.
/*------------------------------------------------------------------------*/
int verificador_formato(char txt[MAX])
{
    int i = 0, verificador = 0;

    while (txt[i] != '\0')
    {
        if (txt[i] == ';')
        {
            verificador += 1;
        }
        i++;
    }

    return verificador;
}

/*--------------------------------------------------------------------*/
// Função distancia_vogais
// Conta as vogais em duas partes separadas de uma string, calculando
// a distância euclidiana entre as contagens das vogais nas duas partes.
// Imprime as contagens de vogais e a distância euclidiana entre elas.
/*--------------------------------------------------------------------*/
void distancia_vogais(char txt[MAX], int vogais1[5], int vogais2[5])
{
    int i = 0, distancia_total;
    float distancia_euclidiana;

    // Conta as vogais na primeira parte da string (antes de ';')
    while (txt[i] != ';')
    {
        if (txt[i] == 'a' || txt[i] == 'A')
        {
            vogais1[0]++;
        }
        else if (txt[i] == 'e' || txt[i] == 'E')
        {
            vogais1[1]++;
        }
        else if (txt[i] == 'i' || txt[i] == 'I')
        {
            vogais1[2]++;
        }
        else if (txt[i] == 'o' || txt[i] == 'O')
        {
            vogais1[3]++;
        }
        else if (txt[i] == 'u' || txt[i] == 'U')
        {
            vogais1[4]++;
        }
        i++;
    }

    // Conta as vogais na segunda parte da string (após ';')
    while (txt[i] != '\0')
    {
        if (txt[i] == 'a' || txt[i] == 'A')
        {
            vogais2[0]++;
        }
        else if (txt[i] == 'e' || txt[i] == 'E')
        {
            vogais2[1]++;
        }
        else if (txt[i] == 'i' || txt[i] == 'I')
        {
            vogais2[2]++;
        }
        else if (txt[i] == 'o' || txt[i] == 'O')
        {
            vogais2[3]++;
        }
        else if (txt[i] == 'u' || txt[i] == 'U')
        {
            vogais2[4]++;
        }
        i++;
    }

    // Calcula a distância euclidiana entre as contagens de vogais
    distancia_total = pow(vogais1[0] - vogais2[0], 2) +
                      pow(vogais1[1] - vogais2[1], 2) +
                      pow(vogais1[2] - vogais2[2], 2) +
                      pow(vogais1[3] - vogais2[3], 2) +
                      pow(vogais1[4] - vogais2[4], 2);

    distancia_euclidiana = sqrt(distancia_total);

    // Imprime as contagens de vogais e a distância euclidiana
    printf("(%d,%d,%d,%d,%d)\n", vogais1[0], vogais1[1], vogais1[2], vogais1[3], vogais1[4]);
    printf("(%d,%d,%d,%d,%d)\n", vogais2[0], vogais2[1], vogais2[2], vogais2[3], vogais2[4]);
    printf("%.2f", distancia_euclidiana);
}

/*----------------------------------------------------------------------------------*/
// Função principal
// Lê uma string e verifica se está no formato correto com apenas um ';'.
// Se o formato for válido, calcula e imprime a distância das vogais nas duas partes.
/*----------------------------------------------------------------------------------*/
int main()
{
    char txt[MAX];
    int vogais1[5] = {0, 0, 0, 0, 0};
    int vogais2[5] = {0, 0, 0, 0, 0};

    // Lê a string de entrada
    scanf("%[^\n]", txt);

    // Verifica o formato da string
    if (verificador_formato(txt) != 1)
    {
        printf("FORMATO INVALIDO!\n");
        return 0;
    }

    // Calcula e imprime a distância das vogais
    distancia_vogais(txt, vogais1, vogais2);

    return 0;
}
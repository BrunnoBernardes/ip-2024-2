#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X 'X'
#define O '0'
#define V ' '

void gera_jogada (int *i, int *j)
{
    *i = rand() % 3;
    *j = rand() % 3;
}

int check_jogada (char M[][3], int i, int j)
{
    if (M[i][j] == V) return 1;
    return 0;
}

int check_fim (char M[][3])
{
    int i;
    for (i = 0; i < 3; i++)
    {
        if (M[i][0] == M[i][1] && M[i][1] == M[i][2] && M[i][0] != V) return 1;
        if (M[0][i] == M[1][i] && M[1][i] == M[2][i] && M[0][i] != V) return 1;
    }
    if (M[0][0] == M[1][1] && M[1][1] == M[2][2] && M[0][0] != V) return 1;
    if (M[0][2] == M[1][1] && M[1][1] == M[2][0] && M[0][2] != V) return 1;
    return 0;
}

void check_vencedor (char M[][3])
{
    int i;
    for (i = 0; i < 3; i++)
    {
        if (M[i][0] == M[i][1] && M[i][1] == M[i][2] && M[i][0] != V)
        {
            if (M[i][0] == X) printf("Voce venceu!\n");
            else printf("Voce perdeu!\n");
            return;
        }
        if (M[0][i] == M[1][i] && M[1][i] == M[2][i] && M[0][i] != V)
        {
            if (M[0][i] == X) printf("Voce venceu!\n");
            else printf("Voce perdeu!\n");
            return;
        }
    }
    if (M[0][0] == M[1][1] && M[1][1] == M[2][2] && M[0][0] != V)
    {
        if (M[0][0] == X) printf("Voce venceu!\n");
        else printf("Voce perdeu!\n");
        return;
    }
    if (M[0][2] == M[1][1] && M[1][1] == M[2][0] && M[0][2] != V)
    {
        if (M[0][2] == X) printf("Voce venceu!\n");
        else printf("Voce perdeu!\n");
        return;
    }
    printf("Empate!\n");
}

void print_velha (char M[][3])
{
    printf (" %c | %c | %c\n", M[0][0], M[0][1], M[0][2]);
    printf ("---+---+---\n");
    printf (" %c | %c | %c\n", M[1][0], M[1][1], M[1][2]);
    printf ("---+---+---\n");
    printf (" %c | %c | %c\n", M[2][0], M[2][1], M[2][2]);
}

int main ()
{
    char M[3][3] = { {V, V, V}, {V, V, V}, {V, V, V} };
    int i, j;
    srand(time(NULL));
    
    while(1)
    {
        print_velha(M);
        printf("Digite a linha e a coluna: ");
        do
        {
            scanf("%d %d", &i, &j);
            i--; j--;
        } while (!check_jogada(M, i, j));
        M[i][j] = X;
        do
        {
            gera_jogada(&i, &j);
        } while (!check_jogada(M, i, j));
        M[i][j] = O;
        
        if (check_fim(M))
        {
            print_velha(M);
            check_vencedor(M);
            printf("Fim de jogo!\n");
            break;
        }
    }
    return 0;
}
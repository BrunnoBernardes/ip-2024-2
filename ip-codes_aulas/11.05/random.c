#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_VIDAS 5
#define MIN_VALUE 0
#define MAX_VALUE 20

int main ()
{
    int vidas = N_VIDAS;
    int aposta;
    int NUMERO_SORTEADO;
    srand(time(NULL));

    NUMERO_SORTEADO = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;

    for (int i = 0; i < N_VIDAS; i++)
    {
        printf("Chute um numero (%d ... %d): ", MIN_VALUE, MAX_VALUE);
        scanf("%d", &aposta);

        if (aposta == NUMERO_SORTEADO)
        {
            printf("Voce acertou!\n");
            break;
        }
        else if (aposta < NUMERO_SORTEADO)
        {
            vidas--;
            printf("Numero muito pequeno. Restam %d vida(s).\n", vidas);
        }
        else if (aposta > NUMERO_SORTEADO)
        {
            vidas--;
            printf("Numero muito grande. Restam %d vida(s).\n", vidas);
        }
    }

    if (vidas == 0) printf("Voce perdeu!\n");

    return 0;
}
#include <stdio.h>

/*------------*/
// Função main
/*------------*/

int main ()
{
    float mat[2][2], M[2][2];
    
    scanf("%f %f %f %f", &mat[0][0], &mat[0][1], &mat[1][0], &mat[1][1]);

    // printf("%.3lf %.3lf\n%.3lf %.3lf\n", mat[0][0], mat[0][1], mat[1][0], mat[1][1]);

    // Calcula o quadrado da matriz mat
    M[0][0] = mat[0][0] * mat[0][0] + mat[0][1] * mat[1][0];
    M[0][1] = mat[0][0] * mat[0][1] + mat[0][1] * mat[1][1];
    M[1][0] = mat[1][0] * mat[0][0] + mat[1][1] * mat[1][0];
    M[1][1] = mat[1][0] * mat[0][1] + mat[1][1] * mat[1][1];

    // Imprime os elementos da matriz quadrada com 3 casas decimais
    printf("%.3f %.3f\n%.3f %.3f\n", M[0][0], M[0][1], M[1][0], M[1][1]);

    return 0;
}
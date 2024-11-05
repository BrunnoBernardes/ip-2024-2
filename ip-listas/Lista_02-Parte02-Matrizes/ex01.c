#include <stdio.h>
#define N 2

int main ()
{
    double det;
    double mat [N][N];
    scanf("%lf", &mat[0][0]);
    scanf("%lf", &mat[0][1]);
    scanf("%lf", &mat[1][0]);
    scanf("%lf", &mat[1][1]);
    det = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    printf("%.2lf\n", det);
    return 0;
}
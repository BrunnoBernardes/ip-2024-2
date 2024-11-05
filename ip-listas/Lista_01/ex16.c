#include <stdio.h>
#include <math.h>
 
int main () {
    
    double a, b, c;
    double delta, x1, x2;
 
    scanf("%lf %lf %lf", &a, &b, &c);
 
    delta = (b*b) - (4.0*a*c);
 
    if (delta == 0.0) {
        x1 = -1.0*b/(2.0*a);
        printf("RAIZ UNICA\n");
        printf("X1 = %.2lf\n", x1);
 
    } else if (delta < 0.0) {
        printf("RAIZES IMAGINARIAS\n");
 
    } else {
        delta = sqrt(delta);
        x1 = (-b-delta)/(2.0*a);
        x2 = (-b+delta)/(2.0*a);
        printf("RAIZES DISTINTAS\n");
        if (x1<x2){
            printf("X1 = %.2lf\nX2 = %.2lf\n", x1, x2);/* code */
        } else {
            printf("X1 = %.2lf\nX2 = %.2lf\n", x2, x1);
        }
    }
 
    return 0;
}
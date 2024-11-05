#include <stdio.h>
 
int main() {
    double n1, n2, n3, n4, x;

    scanf("%lf %lf %lf %lf", &n1, &n2, &n3, &n4);
 
    if (n1 > n2) {
        x = n1;
        n1 = n2;
        n2 = x;
    }
    if (n1 > n3) {
        x = n1;
        n1 = n3;
        n3 = x;
    }
    if (n1 > n4) {
        x = n1;
        n1 = n4;
        n4 = x;
    }
    if (n2 > n3) {
        x = n2;
        n2 = n3;
        n3 = x;
    }
    if (n2 > n4) {
        x = n2;
        n2 = n4;
        n4 = x;
    }
    if (n3 > n4) {
        x = n3;
        n3 = n4;
        n4 = x;
    }

    printf("%.2f, %.2f, %.2f, %.2f\n", n1, n2, n3, n4);

    return 0;
}
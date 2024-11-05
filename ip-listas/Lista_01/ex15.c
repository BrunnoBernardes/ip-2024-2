#include <stdio.h>
 
int main () {
    
    double n, p1, p2, p3;
 
    scanf("%lf", &n);
    p3 = n;
 
    scanf("%lf", &n);
    if (n<p3) {
        p2 = p3;
        p3 = n;
    } else {
        p2 = n;
    }
 
    scanf("%lf", &n);
    if (n<p3) {
        p1 = p2;
        p2 = p3;
        p3 = n;
    } else if (n<p2) {
        p1 = p2;
        p2 = n;
    } else {
        p1 = n;
    }
 
    printf("%.2lf, %.2lf, %.2lf\n", p3, p2, p1);
 
    return 0;
}
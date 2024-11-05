#include <stdio.h>

int main () {

    int n;
    double fa, ce;
    scanf("%d", &n);

    while (n >= 1){

        scanf("%lf", &fa);

        ce = 5*(fa-32)/9;

        printf("%.2lf FAHRENHEIT EQUIVALE A %.2lf CELSIUS\n", fa, ce);
        
        n--;
    }

    return 0;
}
#include <stdio.h>
 
int main () {
    int n, cp = 0, ci = 0;
    double mp = 0.0, mi = 0.0;
    
    scanf("%d", &n);
 
    while (n != 0) {
        if (n%2 == 0){
            mp += n;
            cp++;
        } else {
            mi += n;
            ci++;
        }
        scanf("%d", &n);
    }
 
    if (cp > 0) {
        mp = mp/cp;
    } else {
        mp = 0;
    }
 
    if (ci > 0) {
        mi = mi/ci;
    } else {
        mi = 0;
    }
    printf("MEDIA PAR: %.6lf\n", mp);
    printf("MEDIA IMPAR: %.6lf\n", mi);
    return 0;
}
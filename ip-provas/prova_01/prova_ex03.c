#include <stdio.h>
 
int main (){
 
    double n, r = 1, e, modulo;
 
    scanf("%lf", &n);
    scanf("%lf", &e);
 
    modulo = (n - (r*r));
    if (modulo<0) modulo *= -1;
    
    while (modulo > e){
        r = (r + (n/r))/2;
        modulo = (n - (r*r));
        if (modulo<0) modulo *= -1;
 
        printf("r: %.9lf, err: %.9lf\n", r, modulo);
 
        }
 
    return 0;
}
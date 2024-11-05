#include <stdio.h>
 
int main () {
    
    int n, c = 0, div;
 
    scanf("%d", &n);
 
    if (n<0) {
        printf("Numero invalido!\n");
        return 0;
    } else if (n < 2) {
        printf ("NAO PRIMO");
        return 0;
    }
 
    for(div=2;div<=n/2;div++) {
        if (n%div==0){
            c++;
            break;
        }
    }
    if (c==0){
        printf("PRIMO\n");
    } else {
        printf("NAO PRIMO\n");
    }
    return 0;
}
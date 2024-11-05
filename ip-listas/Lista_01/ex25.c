#include <stdio.h>
 
int main () {
    int n, i = 1, j, impar = 1;
 
    scanf("%d", &n);
 
    printf("%d*%d*%d = %d", i, i, i, impar);
 
    impar += 2;
 
    for(i = 2; i <= n; i++) {
 
        printf("\n%d*%d*%d = %d", i, i, i, impar);
 
        impar += 2;
 
        for(j = 1; j < i; j++){
 
            printf("+%d", impar);
 
            impar += 2;
        }
    }
 
    printf("\n");
    
    return 0;
}
#include <stdio.h>
 
int main (){
 
    int n, i, a, b, final = 0;
 
    scanf("%d", &n);
 
    if (n<2){
 
        printf("Campeonato invalido!\n");
 
    } else {
 
        /*for (i = 1; i < n; i++){
            finais += i;
        }*/
 
        for (a = 1; a < n; a++)
            for (b = a + 1; b <= n; b++){
                final += 1;
                printf("Final %d: Time%d X Time%d\n", final, a, b);
            } 
        }
 
    return 0;
}
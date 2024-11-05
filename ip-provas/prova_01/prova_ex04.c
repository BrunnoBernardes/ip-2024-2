#include <stdio.h>
 
int main (){
 
    int m, n, i = 2, j = 1;
 
    scanf("%d %d", &m, &n);
 
    printf("(%d,%d)", i, j);
 
    for (i = 3; i <= m; i++){
 
        j = 1;
 
        printf("\n(%d,%d)", i, j);
 
        for (j = 2; j <= n; j++){
 
            if (i > j){
                printf("-(%d,%d)", i, j);
            }
        }
    }
 
    printf("\n");
 
    return 0;
}
#include <stdio.h>

int main () {
    int n, fat = 1, i;
    scanf("%d", &n);

    for (i=n; i>0; i--){
        fat = fat * i;
    }

    printf("%d! = %d", n, fat);
    return 0;
}
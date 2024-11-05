#include <stdio.h>

int main () {
    int n, d1, d2, c=0;
    scanf("%d", &n);
    for (d1=1; d1<=6; d1++){
        for (d2=1; d2<=6; d2++){
            if (d1!=d2 && d1+d2 == n){
                printf("D1: %d, D2: %d\n", d1, d2);
                c++;
            }
        }
    }
    if (c==0){
        printf("Combinacao impossivel\n");
    } else {
        printf("Ha %d possibilidades\n", c);
    }
    return 0;
}
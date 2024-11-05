#include <stdio.h>

int main () {
    int a, b, c=0;
    scanf("%d%d", &a, &b);

    while(b>a){
        a = a*1.03;
        b = b*1.015;
        c++;
    }
    
    printf("ANOS = %d", c);
    return 0;
}
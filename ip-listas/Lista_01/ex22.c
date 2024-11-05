#include <stdio.h>
 
void lista_hipotenusa(int h){
    int c1, c2;
    for (c1=1;c1<h;c1++) {
        for (c2=c1;c2<h;c2++){
            if (c1*c1+c2*c2 == h*h) {
                printf("hipotenusa = %d, catetos %d e %d\n", h, c1, c2);
            }
        }
    }
}
 
int main () {
    int n, i;
 
    scanf("%d", &n);
 
    for(i=1;i<=n;i++) {
        lista_hipotenusa(i);
    }
 
    return 0;
}
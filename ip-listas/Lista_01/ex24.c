#include <stdio.h>

int proximoPrimo (int p) {
    int i;
    p++; 
    while (1) {
        for (i = 2; i * i <= p; i++){
            if (p % i == 0){
                p++;
                break;
            }
        }
        if (i * i > p){
            return p;
        }
    }
}

int main () {

    int n1, n2, n3, i=2, mmc=1;

    scanf ("%d %d %d", &n1, &n2, &n3);

    while (n1>1 || n2>1 || n3>1){

        if (n1 % i == 0 || n2 % i == 0 || n3 % i == 0){
        
            printf("%d %d %d :%d\n", n1, n2, n3, i);

            if (n1%i==0) n1 /= i;
            if (n2%i==0) n2 /= i;
            if (n3%i==0) n3 /= i;
        
            mmc *= i;
        
        } else {

            i = proximoPrimo(i);

        }

    }

    printf("MMC: %d\n", mmc);

    return 0;
}
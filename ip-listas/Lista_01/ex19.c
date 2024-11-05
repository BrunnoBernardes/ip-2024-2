#include <stdio.h>

int main () {
    
    int n1, n2, n3;

    scanf("%d %d %d", &n1, &n2, &n3);

    if (n1 < 7 && n2 > 50 && n3 > 80000){
        printf("ACO DE GRAU = 10\n");   
    } else if (n1 < 7 && n2 > 50 && n3 <= 80000) {
        printf("ACO DE GRAU = 9\n");
    } else if (n1 < 7 && n2 <= 50 && n3 <= 80000) {
        printf("ACO DE GRAU = 8\n");
    } else {
        printf("ACO DE GRAU = 7\n");
    }

    return 0;
}
#include <stdio.h>

int main() {
    int n, F1, F2, F3, verificador;

    scanf("%d %d %d", &n, &F1, &F2);

    scanf("%d", &verificador);
    if (verificador != F1) {
        printf("Nao e Fibonacci\n");
        return 0;
    } else {
        printf("OK\n");
    }
    scanf("%d", &verificador);
    if (verificador != F2) {
        printf("Nao e Fibonacci\n");
        return 0;
    } else {
        printf("OK\n");
    }

    for (int i = 3; i <= n; i++) {
        scanf("%d", &verificador);
        F3 = F1 + F2;

        if (verificador != F3) {
            printf("Nao e Fibonacci\n");
            return 0;
        } else {
            printf("OK\n");
        }

        F1 = F2;
        F2 = verificador;
    }
    printf("A serie informada e de Fibonacci\n");

    return 0;
}
#include <stdio.h>

int inverso(int normal){

    int u, d, c, invertido;

    u = normal % 10;
    d = (normal % 100) / 10;
    c = normal / 100;

    invertido = (u * 100) + (d * 10) + c;

    return invertido;
}

int main () {
    
    int n, i, a, b;

    scanf("%d", &n);

    for (i = 0; i < n; i++ ) {
        scanf("%d %d", &a, &b);

            if (inverso(a) > inverso(b)) printf("%d\n", inverso(a));
            else printf("%d\n", inverso(b));
    }

    return 0;
}
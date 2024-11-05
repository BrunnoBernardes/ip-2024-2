#include <stdio.h>
 
int main() {
    int n1, n2, n3, a, b, c;
    char x, y, z;
 
    scanf("%d %d %d\n", &n1, &n2, &n3);
 
    if (n1 < n2 && n1 < n3) {
        a = n1;
        if (n2 < n3) {
            b = n2;
            c = n3;
        } else {
            b = n3;
            c = n2;
        }
    } else if (n2 < n1 && n2 < n3) {
        a = n2;
        if (n1 < n3) {
            b = n1;
            c = n3;
        } else {
            b = n3;
            c = n1;
        }
    } else {
        a = n3;
        if (n1 < n2) {
            b = n1;
            c = n2;
        } else {
            b = n2;
            c = n1;
        }
    }
 
    scanf("%c%c%c", &x, &y, &z);
 
    if (x == 'A') printf("%d ", a);
    else if (x == 'B') printf("%d ", b);
    else if (x == 'C') printf("%d ", c);
 
    if (y == 'A') printf("%d ", a);
    else if (y == 'B') printf("%d ", b);
    else if (y == 'C') printf("%d ", c);
 
    if (z == 'A') printf("%d\n", a);
    else if (z == 'B') printf("%d\n", b);
    else if (z == 'C') printf("%d\n", c);
 
    return 0;
}
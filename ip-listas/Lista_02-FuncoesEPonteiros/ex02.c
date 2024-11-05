#include <stdio.h>

int fibonacci(int t1, int t2, int n)
{
    int tf;
    if (n == 1)
        tf = t1;
    else if (n == 2)
        tf = t2;
    while (n > 2)
    {
        tf = t1 + t2;
        t1 = t2;
        t2 = tf;
        n -= 1;
    }
    return tf;
}

int main()
{
    int t1, t2, n;
    scanf("%d%d%d", &t1, &t2, &n);
    printf("%d\n", fibonacci(t1, t2, n));
    return 0;
}
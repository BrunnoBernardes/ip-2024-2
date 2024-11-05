#include <stdio.h>
#include <string.h>
#define N 1000

int main()
{
    int n, i, j, count = 0;
    char V[N];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", V);
        for (j = 0; V[j] != '\0'; j++)
        {
            switch (V[j])
            {
            case '0':
                count += 6;
                break;
            case '1':
                count += 2;
                break;
            case '2':
                count += 5;
                break;
            case '3':
                count += 5;
                break;
            case '4':
                count += 4;
                break;
            case '5':
                count += 5;
                break;
            case '6':
                count += 6;
                break;
            case '7':
                count += 3;
                break;
            case '8':
                count += 7;
                break;
            case '9':
                count += 6;
                break;
            default:
                break;
            }
        }
        printf("%d leds\n", count);
        count = 0;
    }
    return 0;
}
#include <stdio.h>
#include <string.h>

int count_error(const char *pal, const char *num)
{
    int i, count = 0;
    for (i = 0; pal[i] != '\0' && num[i] != '\0'; i++)
    {
        if (pal[i] != num[i])
        {
            count++;
        }
    }
    return count;
}

int main ()
{
    int n, i;
    char pal[6];

    scanf ("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf ("%s", pal);
        if (strlen(pal) == 3 && count_error(pal, "one") <= 1) {
            printf("1\n");
        }
        else if (strlen(pal) == 3 && count_error(pal, "two") <= 1) {
            printf("2\n");
        }
        else if (strlen(pal) == 5 && count_error(pal, "three") <= 1) {
            printf("3\n");
        }
    }
    return 0;
}
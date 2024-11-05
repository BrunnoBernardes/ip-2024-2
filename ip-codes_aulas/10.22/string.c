#include <stdio.h>

#define NCH 128

void str2upper ( char *str)
{
    while (*str != '\0')
    {
        if (*str >= 'A' && *str <= 'z')
        {
            *str -= ('a' - 'A');
        }
    }
}

int main ()
{
    char str[NCH+1];
    scanf ("%[^\n]%*c", str);

    str2upper (str);
    printf ("%s\n", str);
    return 0;
}
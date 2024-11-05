#include <stdio.h>

#define NCH 128

#define ch2upper(x) if( (x)>='a' && (x)<='z' ) (x)=( (x) - 32)

void str2upper ( char *str)
{
    while (*str != '\0')
    {
        ch2upper(*str);
        str++;
    }
}

int main ()
{
    char str[NCH+1];
    scanf("%[^\n]%*c", str);

    str2upper (str);
    printf ("%s\n", str);
    return 0;
}
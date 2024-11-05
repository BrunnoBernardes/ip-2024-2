#include <stdio.h>
#include <string.h>

char * my_strcpy( char *dest, char *src)
{
    char *inicio = dest;
    while( &src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return inicio;
}

int main ()
{
    char str[128];
    char txt[32] = "1234";

    strcpy( str, txt );
    //strcpy( strcpy( str, txt ), "Ola mundo");
    printf("%s\n", str);

    return 0;
}
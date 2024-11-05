#include <stdio.h>
#include <string.h>

char * my_strcat( char *dest, char *src)
{
    char *inicio = dest;
    while( *dest != '\0') dest++;
    while( *src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return inicio;
}

int main()
{
    char str[128] = "Ola mundo";
    char str2 [128] = " cruel";

    my_strcat( str, str2 );
    printf( "%s\n", str);
    return 0;
}
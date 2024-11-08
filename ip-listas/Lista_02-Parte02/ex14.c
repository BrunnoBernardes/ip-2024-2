#include <stdio.h>
#define N 499

int procura_caracter( char ch, char * str ) {
	int i = 0;
	while(str[i] != '\0') {
		if(str[i] == ch ) return i;
		i++;
	}
	return -1;
}

/*int __findch( char ch, char * str ) {
	int i = 0;
	while( str[i] && str[i] != ch) i++;
	if( !str[i] ) return -1;
	return i;
}*/

int main() {
	int n;
	char x;
	char str[N+1];
	int i;
	scanf("%d%*c", &n);
	while(n--) {
		scanf("%c%*c%[^\n]%*c", &x, str);
		i = procura_caracter(x, str);
		if(i==-1) {
			printf("Caractere %c nao encontrado.\n", x);
		} else {
			printf("Caractere %c encontrado no indice %d da string.\n", x, i);
		}
	}
	return 0;
}
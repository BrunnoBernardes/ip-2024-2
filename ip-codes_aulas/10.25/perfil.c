#include <stdio.h>

#define PERFIL_N 5
char simbols[PERFIL_N+1] = "aeiou";

void gera_perfil( char * txt, int v[] ) {
	int i;
	// zerar contador
	for(i=0;i<PERFIL_N;i++) v[i] = 0;

	// calcular o perfil
	while(*txt!='\0') {  // txt = computador
		for(i=0;i<PERFIL_N;i++) {
			if(*txt==simbols[i]) {
				v[i]++;
				break;
			}
		}
		txt++;
	}
}
void print_perfil(int v[]) {
	int i;
	for(i=0;i<PERFIL_N;i++) {
		printf("%c(%d):", simbols[i], v[i]);
	}
	printf( "\n");
}

double d_perfil(int * p1, int * p2) {
	
}

int main() {
	int n, i;
	char txt[128];
	char word[128];
	int v[PERFIL_N];
	double d, p1[PERFIL_N], p2[PERFIL_N];
	scanf("%d%*c", &n);
	scanf("%s%*c", word);
	for(i=0;i<n;i++) {
		scanf("%[^\n]%*c", txt);
		gera_perfil(txt, v);
		d = d_perfil(p1, p2);
		printf("dperfil: %.2lf | %20s -- ", d, txt);
		print_perfil(v);
	}
	return 0;
}
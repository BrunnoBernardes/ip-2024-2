#include <stdio.h>
#define N 500
int main() {

	int n_casos = 0;
	int n_ch;
	char txt[N];
	int i, j;

	scanf("%d%*c", &n_casos);
	for(i=0;i<n_casos;i++) {
		scanf("%d%*c%[^\n]%*c", &n_ch, txt);
		txt[n_ch]='\0';
		printf("%s\n", txt);
	}
	return 0;
}
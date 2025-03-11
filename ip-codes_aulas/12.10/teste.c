#include <stdio.h>

int main() {
	int n;
	FILE * arq = fopen("input", "r");
	while(1) {
		if(fscanf(arq,"%d", &n)==EOF) break;
		printf("%d,", n);
	}
	printf("\n");
	fclose(arq);
	return 0;
}
#include <stdio.h>

int main() {
	int A = 0;
	FILE * arq = fopen("out.bin", "rb+");
	fseek(arq, -4, SEEK_END);
	fread(&A, sizeof(int), 1, arq);
	fseek(arq, -8, SEEK_CUR);
	fread(&A, sizeof(int), 1, arq);
	fclose(arq);
	printf("%d\n", A);
	return 0;
}
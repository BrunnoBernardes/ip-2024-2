#include <stdio.h>

int main() {
	int A = 10;
	FILE * arq = fopen("out.bin", "wb");
	fwrite(&A, sizeof(int), 1, arq);
	A = 20;
	fwrite(&A, sizeof(int), 1, arq);
	fclose(arq);
	return 0;
}
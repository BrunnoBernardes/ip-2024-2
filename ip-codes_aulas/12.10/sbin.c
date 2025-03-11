#include <stdio.h>

typedef struct {
	char nome[4];
	int code;
	double valor;
} Produto;

int main(int argc, char ** argv) {
	Produto A = {"CUP", 5, 1.5 };
	FILE * arq = fopen( argv[1], "wb");

	fwrite( &A, sizeof(Produto), 1, arq);

	fclose(arq);
	return 0;
}

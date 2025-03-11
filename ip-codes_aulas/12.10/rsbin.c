#include <stdio.h>

typedef struct {
	char nome[4];
	int code;
	double valor;
} Produto;

int main(int argc, char ** argv) {
	Produto A;
	FILE * arq = fopen( argv[1], "rb");

	fread( &A, sizeof(Produto), 1, arq);

	printf("Nome: %s\n", A.nome);
	printf("Codigo: %d\n", A.code);
	printf("Valor: %.2lf\n", A.valor);

	fclose(arq);
	return 0;
}

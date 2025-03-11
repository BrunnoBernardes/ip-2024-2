#include <stdio.h>

#define ID_SIZE 4
typedef struct {
	char code[ID_SIZE];
	int p;
	double* coef;
} Poly;

int main( int argc, char ** argv ) {
	Poly p = { "poly", 0, NULL };
	FILE * arq = fopen(argv[2], "wb");
	double coef;
	int pot;

	sscanf( argv[1], "%lf%*c%*c%d", &coef, &pot);

	printf("Coeficiente: %lf\nPotencia: %d\n", coef, pot);

	fclose(arq);
	return 0;
}
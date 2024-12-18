#include <stdio.h>
#define N 3

int main(int argc, char ** argv) {
	int A, r;
	FILE * arq = fopen( argv[1], "rb");

	while(1) {
		r = fread(&A, sizeof(int), 1, arq);
		// printf("codigo %d\n", r);
		if( feof(arq) != 0 ) {
			break;
		}
		printf("%d, ", A);
	}

	
	printf("\n");

	fclose(arq);

	return 0;
}

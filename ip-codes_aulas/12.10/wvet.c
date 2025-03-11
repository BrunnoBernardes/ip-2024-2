#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

int main(int argc, char ** argv) {
	int v[N], i;
	srand( time(NULL) );
	for(i=0;i<N;i++)
		v[i] = rand()%11;

	FILE * arq = fopen( argv[1], "wb");

	fwrite(v, sizeof(int), N, arq);
	
	printf("\n");

	fclose(arq);

	return 0;
}

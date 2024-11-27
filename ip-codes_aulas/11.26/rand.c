#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * @brief Gerador de numeros inteiros aleatorios
 * 
 * Usage:
 *  ./randi <number of values> <min limit> <max limit>
 */
int main(int argc, char ** argv ) {
	int x;
	int n, min, max;
	srand( time(NULL) );
	if(argc != 4) {
		printf(
		"Usage:\n"
		"  ./randi #values min max\n"
		);
		return 0;
	}
	n = atoi( argv[1] );
	min = atoi( argv[2] );
	max = atoi( argv[3] );
	while(n--) {
		x = rand()%(max-min+1) + min;
		printf("%d, ", x);
	}
	printf("\n");
	return 0;
}
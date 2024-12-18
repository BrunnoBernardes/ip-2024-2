#include <stdio.h>

int main(int argc, char ** argv) {
	int n, A;
	FILE * arq = fopen( argv[1], "rb");
	fseek(arq, 0, SEEK_END);
	n = ftell(arq);
	printf("%s possui %d bytes\n", argv[1], n);

	fclose(arq);

	return 0;
}

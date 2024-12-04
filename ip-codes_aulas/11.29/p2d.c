#include <stdio.h>
#include <math.h>

#define N 10

typedef struct {
	double x, y;
} p2d;

void p2d_read( p2d * p ) {
	scanf("%lf%lf", &(p->x), &(p->y) );
	// scanf("%lf%lf", &(*p).x), &((*p).y) );
}
p2d p2d_vread(void) {
	p2d p;
	scanf("%lf%lf", &(p.x), &p.y );
	return p;
}
void p2d_print(const p2d * p) {
	printf("(%.0lf,%.0lf)", p->x, p->y);
}
void p2d_vprint(p2d p) {
	printf("(%.2lf,%.2lf)", p.x, p.y);
}

double p2d_dist( const p2d * A, const p2d * B) {
	double dx, dy;
	dx = A->x - B->x;
	dy = A->y - B->y;
	return sqrt( dx*dx + dy*dy );
}

/**
 * Escreva um programa que lê uma sequencia de 10 pontos 2d e
 * apresente o par de ponto(s) mais próximo(s) e os mais
 * distante(s).
 */
int main() {
	p2d A[N];
	double d_tmp, d_min, d_max;
	int i_min, j_min, i_max, j_max;
	int i, j;
	// Leitura de N pontos 2D
	for(i=0;i<N;i++) {
		p2d_read(&A[i]);
	}
	// Impressão de N pontos 2D
	printf("[ ");
	for(i=0;i<N;i++) {
		p2d_print(&A[i]);
		printf(", ");
	}
	printf("]\n");

	d_max = d_min = p2d_dist( &A[0], &A[1] );
	i_max = i_min = 0;
	j_max = j_min = 1;
	for(i=0;i<N-1;i++) {
		for(j=i+1;j<N;j++) {
			d_tmp = p2d_dist( &A[i], &A[j] );
			if( d_tmp < d_min ) {
				d_min  = d_tmp;
				i_min = i;
				j_min = j;
			}
			if( d_tmp > d_max ) {
				d_max  = d_tmp;
				i_max = i;
				j_max = j;
			}
		}
	}
	printf("Pontos mais próximos: ");
	p2d_print( &A[i_min] );
	printf(" -- ");
	p2d_print( &A[j_min] );
	printf("\n");
	printf("Pontos mais distantes: ");
	p2d_print( &A[i_max] );
	printf(" -- ");
	p2d_print( &A[j_max] );
	printf("\n");
	
	return 0;
}
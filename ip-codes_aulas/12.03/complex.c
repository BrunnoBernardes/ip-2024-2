#include <stdio.h>
#include <math.h>

typedef struct {
	double r, i;
} Complex;

void complex_read( Complex * n ) {
	scanf("%lf%lf", &(n->r), &(n->i) );
}

void complex_print( const Complex * n ) {
	printf("%g%+gi", n->r, n->i);
}

void complex_print_polar( const Complex * n ) {
	double rho, theta;
	rho = sqrt( n->r*n->r + n->i*n->i );
	theta = atan2( n->i, n->r ) * 180; ///M_PI;
    printf("%.1lfL%.1lf°", rho, theta);
}
Complex complex_vsum( Complex A, Complex B ) {
	Complex S;
	S.r = A.r + B.r;
	S.i = A.i + B.i;
	return S;
}
Complex complex_vsub( Complex A, Complex B ) {
	Complex S;
	S.r = A.r - B.r;
	S.i = A.i - B.i;
	return S;
}
Complex complex_vprod( Complex A, Complex B) {
	Complex P;
	P.r = A.r*B.r - A.i*B.i;
	P.i = A.r*B.i + A.i*B.r;
	return P;
}
Complex complex_vconj( Complex A ) {
	A.i = -A.i;
	return A;
}
double complex_vnorm2( Complex A ) {
	return A.r*A.r + A.i*A.i;
}
Complex complex_vdiv( Complex A, Complex B) {
	Complex Bconj = complex_vconj(B);
	Complex N = complex_vprod(A,Bconj);
	double rho = complex_vnorm2(B);
    if (rho == 0) {
    printf("Erro: Divisão por zero.\n");
    exit(1);
    }
	N.r /= rho;
	N.i /= rho;
	return N;
}

int main() {
	Complex A, B, X;
	complex_read(&A);
	complex_read(&B);
	complex_print(&A);
	printf("\n");
	complex_print(&B);
	printf("\n");

	printf("Soma:\n");
	X = complex_vsum(A,B);
	complex_print(&X);
	printf("\n");

	printf("Subtração:\n");
	X = complex_vsub(A,B);
	complex_print(&X);
	printf("\n");

	printf("Multiplicacao:\n");
	X = complex_vprod(A,B);
	complex_print(&X);
	printf("\n");

	printf("Divisao:\n");
	X = complex_vdiv(A,B);
	complex_print(&X);
	printf("\n");

	complex_print_polar(&A);
    printf("\n");
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <math.h>

struct point2d {
	char name[32];
	double x, y;
};
typedef struct point2d p2d;

void p2d_print( p2d p ) {
	printf("(\"%s\",%.2lf,%.2lf)", p.name, p.x, p.y);
}

p2d p2d_sum( p2d A, p2d B, char * name) {
	p2d s;
	s.x = A.x + B.x;
	s.y = A.y + B.y;
	strcpy(s.name, name);
	return s;
}
p2d p2d_sub( p2d A, p2d B, char * name) {
	p2d s;
	s.x = A.x - B.x;
	s.y = A.y - B.y;
	strcpy(s.name, name);
	return s;
}
double p2d_norm( p2d X ) {
	return sqrt(X.x*X.x + X.y*X.y);
}
double inner_prod( p2d A, p2d B) {
	return A.x*B.x + A.y*B.y;
}

// TODO:
/**
 * 1) funcao que retorna o vetor projecao de A em B
 * 2) funcao que imprime o produto misto de A, B e C
 * 3) funcao que imprime a equacao do plano entre A, B e C
 * 4) funcao que imprime a equacao da reta entre A e B
 * 5) funcao que imprime a equacao da conica que passa pelos pontos A, B e C
 * 6) funcao que indica se um ponto A está à esquerda ou direita de uma reta
 * 7) funcao que retorna a distancia de um ponto a reta
 */

int main() {
	struct point2d p = {"p", 2, 3};
	p2d A;
	p2d_print(p);
	A = p2d_sum(p, p, "A");
	p2d_print(A);
	return 0;
}
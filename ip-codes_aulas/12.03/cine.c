#include <stdio.h>

// Inicializar as regioes vip e preferencial
// Aprimorar a reserva
// Implementar a liberacao
// Valor instantaneo das reservas


typedef unsigned char bool;
typedef struct {
	bool livre;
	char tipo_poltrona;
	char tipo_cliente;
	double valor;
} Poltrona;

#define N_FILAS 4
#define N_COLS 6
#define FALSE 0
#define TRUE 1

typedef struct {
	Poltrona P[N_FILAS][N_COLS];
} Cine;
void cine_init( Cine * cine ) {
	int i, j;
	for(i=0;i<N_FILAS;i++)
		for(j=0;j<N_COLS;j++) {
			cine->P[i][j].livre = TRUE;
			cine->P[i][j].tipo_cliente = 'N';
			cine->P[i][j].tipo_poltrona = 'N';
			(*cine).P[i][j].valor = 0;
		}
}

void cine_print( const Cine * cine ) {
	printf("--- TELA ---\n");
	int i, j;
	for(i=0;i<N_FILAS;i++) {
		for(j=0;j<N_COLS;j++) {
			if(cine->P[i][j].livre) printf("o ");
			else printf("x ");
		}
		printf("\n");
	}
}

void cine_define_vip( Cine * cine, char fila, int col) {
	// setar o atributo tipo_poltrona para 'V'
}
void cine_define_preferencial( Cine * cine, char fila, int col) {
	// setar o atributo tipo_cliente para 'P'
}
#define RESERVAR	1
#define LIBERAR		2
#define VISUALIZAR	3
#define VALOR_RESERVA	4
#define SAIR		5

int cine_menu(void) {
	int op;
	printf(" -- MENU --\n");
	printf(" %d. Reservar poltrona\n", RESERVAR);
	printf(" %d. Liberar poltrona\n", LIBERAR);
	printf(" %d. Visualizar sala\n", VISUALIZAR);
	printf(" %d. Valor total das reservas\n", VALOR_RESERVA);
	printf(" %d. Sair\n", SAIR);
	scanf("%d%*c", &op);
	return op;
}

// Aprimorar a reserva
void cine_reservar(Cine * cine, char fila, int col) {
	int l, c;
	if(fila==10) {
		printf("Hahah vc digitou um ENTER\n\n");
	}
	l = fila-'A';
	if(l<0||l>3) {
		printf("Fileira invalida!!!\n");
		return;
	}
	if(col<0||col>5) {
		printf("Coluna invalida!!!\n");
		return;
	}
	cine->P[l][col].livre = FALSE;
}

int main() {
	char fila;
	int col;
	int op;
	Cine Kinoplex;
	cine_init(&Kinoplex);

	while(1) {
		op = cine_menu();
		switch (op) {
			case RESERVAR:
				printf("Entre com a fila [A-D] e a coluna [0-5]:");
				scanf("%c%*c%d", &fila, &col);
				cine_reservar(&Kinoplex, fila, col);
				break;
			case VISUALIZAR:
				cine_print(&Kinoplex);
				break;
			
			case SAIR:
				return 0;
				break;
			
			default:
				printf("Opcao invalida ou nao implementada!!!\n");
				break;
		}

	}



	
	return 0;
}
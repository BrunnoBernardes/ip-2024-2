#include <stdio.h>

// Inicializar as regioes vip e preferencial
// Aprimorar a reserva
// Implementar a liberacao
// Valor instantaneo das reservas


typedef unsigned char bool;
typedef struct {
	bool livre;
    char tipo_poltrona; // 'N' = Normal, 'V' = VIP
    char tipo_cliente;  // 'N' = Normal, 'P' = Preferencial
	double valor;
} Poltrona;

#define N_FILAS 4
#define N_COLS 6
#define FALSE 0
#define TRUE 1

typedef struct {
	Poltrona P[N_FILAS][N_COLS];
} Cine;

void cine_define_vip(Cine *cine) {
    char fila_inicio, fila_fim;
    int col_inicio, col_fim;
    int l, c;
    double valor;

    printf("\n--- Inicializando Poltronas VIP ---\n");
    printf("\nEscolha o intervalo de filas (ex: A D): ");
    scanf(" %c %c", &fila_inicio, &fila_fim);

    fila_inicio = fila_inicio - 'A';
    fila_fim = fila_fim - 'A';

    // Verifica se as filas são válidas
    if (fila_inicio < 0 || fila_inicio >= N_FILAS || fila_fim < 0 || fila_fim >= N_FILAS || fila_inicio > fila_fim) {
        printf("Filas inválidas!\n");
        return;
    }

    printf("\nEscolha o intervalo de colunas (ex: 2 4): ");
    scanf("%d %d", &col_inicio, &col_fim);

    // Verifica se as colunas são válidas
    if (col_inicio < 0 || col_fim >= N_COLS || col_inicio > col_fim) {
        printf("Colunas inválidas!\n");
        return;
    }

    printf("\nEntre com o valor do ingresso VIP: ");
    scanf("%lf", &valor);

    // Define as poltronas no intervalo fornecido
    for (l = fila_inicio; l <= fila_fim; l++) {
        for (c = col_inicio; c <= col_fim; c++) {
            cine->P[l][c].livre = TRUE;
            cine->P[l][c].tipo_cliente = 'N';
            cine->P[l][c].tipo_poltrona = 'V';
            cine->P[l][c].valor = valor;
        }
    }

    printf("\nPoltronas VIP definidas com sucesso!\n");
}


void cine_define_preferencial( Cine *cine) {
    char fila_inicio, fila_fim;
    int col_inicio, col_fim;
    int l, c;
    double valor;

    printf("\n--- Inicializando Poltronas Preferenciais ---\n");
    printf("\nEscolha o intervalo de filas (ex: A D): ");
    scanf(" %c %c", &fila_inicio, &fila_fim);

    fila_inicio = fila_inicio - 'A';
    fila_fim = fila_fim - 'A';

    // Verifica se as filas são válidas
    if (fila_inicio < 0 || fila_inicio >= N_FILAS || fila_fim < 0 || fila_fim >= N_FILAS || fila_inicio > fila_fim) {
        printf("Filas inválidas!\n");
        return;
    }

    printf("\nEscolha o intervalo de colunas (ex: 2 4): ");
    scanf("%d %d", &col_inicio, &col_fim);

    // Verifica se as colunas são válidas
    if (col_inicio < 0 || col_fim >= N_COLS || col_inicio > col_fim) {
        printf("Colunas inválidas!\n");
        return;
    }

    printf("\nEntre com o valor do ingresso preferencial: ");
    scanf("%lf", &valor);

    // Define as poltronas no intervalo fornecido
    for (l = fila_inicio; l <= fila_fim; l++) {
        for (c = col_inicio; c <= col_fim; c++) {
            cine->P[l][c].livre = TRUE;
            cine->P[l][c].tipo_cliente = 'P';
            cine->P[l][c].tipo_poltrona = 'N';
            cine->P[l][c].valor = valor;
        }
    }

    printf("\nPoltronas VIP definidas com sucesso!\n");
}

void cine_init( Cine * cine ) {
	int i, j;
	double valor;

	printf("\n--- Inicializando Cinema ---\n");
	printf("\nEntre com o valor do ingresso normal: ");
	scanf("%lf", &valor);

	for(i=0;i<N_FILAS;i++) {
		for(j=0;j<N_COLS;j++) {
			cine->P[i][j].livre = TRUE;
			cine->P[i][j].tipo_cliente = 'N';
			cine->P[i][j].tipo_poltrona = 'N';
			(*cine).P[i][j].valor = valor;
		}
	}

	cine_define_vip(cine);
    cine_define_preferencial(cine);
}

void cine_mostrar_especiais( const Cine *cine) {
    printf("\n--- Poltronas Especiais ---\n");
    printf("\nPreferenciais (P):\n");
    int i, j;
    for (i = 0; i < N_FILAS; i++) {
        for (j = 0; j < N_COLS; j++) {
            if (cine->P[i][j].tipo_cliente == 'P') {
                printf("Fila %c, Coluna %d\n", 'A' + i, j);
            }
        }
    }

    printf("\nVIPs (V):\n");
    for (i = 0; i < N_FILAS; i++) {
        for (j = 0; j < N_COLS; j++) {
            if (cine->P[i][j].tipo_poltrona == 'V') {
                printf("Fila %c, Coluna %d\n", 'A' + i, j);
            }
        }
    }
}

void cine_print( const Cine * cine ) {
	printf("\n--- TELA ---\n\n");
	int i, j;
	for(i=0;i<N_FILAS;i++) {
		for(j=0;j<N_COLS;j++) {
			if(cine->P[i][j].livre) printf("o ");
			else printf("x ");
		}
		printf("\n");
	}

}

#define RESERVAR	1
#define LIBERAR		2
#define VISUALIZAR	3
#define VALOR_RESERVA	4
#define SAIR		5

int cine_menu(void) {
	int op;
	printf("\n  ---- MENU ----\n\n");
	printf("  %d. Reservar poltrona\n", RESERVAR);
	printf("  %d. Liberar poltrona\n", LIBERAR);
	printf("  %d. Visualizar sala\n", VISUALIZAR);
	printf("  %d. Valor total das reservas\n", VALOR_RESERVA);
	printf("  %d. Sair\n\n", SAIR);
	printf("Escolha uma opcao: ");
	scanf("%d%*c", &op);
	return op;
}

// Aprimorar a reserva
void cine_reservar(Cine * cine, char fila, int col) {
	int l, c;
	if(fila==10) {
		printf("\nHahah vc digitou um ENTER\n\n");
	}
	l = fila-'A';
	if(l<0||l>3) {
		printf("\nFileira invalida!!!\n");
		return;
	}
	if(col<0||col>5) {
		printf("\nColuna invalida!!!\n");
		return;
	}
	if(cine->P[l][col].livre==FALSE) {
		printf("\nPoltrona ja ocupada!!!\n");
		return;
	}
	else {
		cine->P[l][col].livre = FALSE;
		printf("\nPoltrona reservada com sucesso!!!\n");
	}
}

void cine_liberar( Cine * cine, char fila, int col) {
    int l = fila - 'A';
    if (l < 0 || l >= N_FILAS || col < 0 || col >= N_COLS) {
        printf("\nPosição inválida!\n");
        return;
    }
    if (cine->P[l][col].livre) {
        printf("\nA poltrona já está livre!\n");
    } else {
        cine->P[l][col].livre = TRUE;
        printf("\nPoltrona liberada com sucesso!\n");
    }
}

void cine_valor_total( const Cine * cine) {
    double total = 0.0;
    for (int i = 0; i < N_FILAS; i++) {
        for (int j = 0; j < N_COLS; j++) {
            if (!cine->P[i][j].livre) {
                total += cine->P[i][j].valor;
            }
        }
    }
    printf("\nValor total das reservas: R$ %.2lf\n", total);
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
				printf("\nEntre com a fila [A-D] e a coluna [1-6]: ");
				scanf("%c%*c%d", &fila, &col);
				col--;
				cine_reservar(&Kinoplex, fila, col);
				break;

			case LIBERAR:
				printf("\nEntre com a fila [A-D] e a coluna [1-6]: ");
				scanf("%c%*c%d", &fila, &col);
				col--;
				cine_liberar(&Kinoplex, fila, col);
				break;

			case VISUALIZAR:
				cine_mostrar_especiais(&Kinoplex);
				cine_print(&Kinoplex);
				break;

			case VALOR_RESERVA:
				printf("\nValores fixos: Normal = R$ 35.00, VIP = R$ 45.00, Preferencial = R$ 30.00\n");
				cine_valor_total(&Kinoplex);
				break;

			case SAIR:
				printf("\n");
				return 0;
				break;
			
			default:
				printf("\nOpcao invalida ou nao implementada!!!\n");
				break;
		}

	}



	
	return 0;
}
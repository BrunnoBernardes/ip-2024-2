#include <stdio.h>

typedef unsigned char bool;

typedef struct
{
	bool livre;
	char tipo_poltrona; // 'N' = Normal, 'V' = VIP
	char tipo_cliente;	// 'N' = Normal, 'P' = Preferencial
	double valor;
} Poltrona;

#define N_FILAS 6			 // Defina o número de filas da sala
#define N_COLS 6			 // Defina o número de colunas da sala
#define PREF_FILA_INICIO 'A' // Defina a fila de início das poltronas preferenciais
#define PREF_FILA_FIM 'A'	 // Defina a fila de fim das poltronas preferenciais
#define PREF_COL_INICIO 2	 // Defina a coluna de início das poltronas preferenciais
#define PREF_COL_FIM 4		 // Defina a coluna de fim das poltronas preferenciais
#define VIP_FILA_INICIO 'B'	 // Defina a fila de início das poltronas VIP
#define VIP_FILA_FIM 'D'	 // Defina a fila de fim das poltronas VIP
#define VIP_COL_INICIO 2	 // Defina a coluna de início das poltronas VIP
#define VIP_COL_FIM 5		 // Defina a coluna de fim das poltronas VIP
#define FALSE 0
#define TRUE 1

typedef struct
{
	Poltrona P[N_FILAS][N_COLS];
} Cine;

void cine_define_vip(Cine *cine)
{
	int i, j;
	double valor;

	printf("\nEntre com o valor do ingresso VIP: ");
	scanf("%lf", &valor);

	for (i = VIP_FILA_INICIO - 'A'; i <= VIP_FILA_FIM - 'A'; i++)
	{
		for (j = VIP_COL_INICIO; j <= VIP_COL_FIM; j++)
		{
			cine->P[i][j].livre = TRUE;
			cine->P[i][j].tipo_cliente = 'N';
			cine->P[i][j].tipo_poltrona = 'V';
			cine->P[i][j].valor = valor;
		}
	}
}

void cine_define_preferencial(Cine *cine)
{
	int i, j;
	double valor;

	printf("\nEntre com o valor do ingresso preferencial: ");
	scanf("%lf", &valor);

	for (i = PREF_FILA_INICIO - 'A'; i <= PREF_FILA_FIM - 'A'; i++)
	{
		for (j = PREF_COL_INICIO; j <= PREF_COL_FIM; j++)
		{
			cine->P[i][j].livre = TRUE;
			cine->P[i][j].tipo_cliente = 'P';
			cine->P[i][j].tipo_poltrona = 'N';
			cine->P[i][j].valor = valor;
		}
	}
}

void cine_init(Cine *cine)
{
	int i, j;
	double valor;

	printf("\n--- Inicializando Cinema ---\n");

	// Validações dos limites
	if (VIP_FILA_INICIO - 'A' < 0 || VIP_FILA_FIM - 'A' >= N_FILAS || VIP_FILA_INICIO > VIP_FILA_FIM ||
		VIP_COL_INICIO < 0 || VIP_COL_FIM >= N_COLS || VIP_COL_INICIO > VIP_COL_FIM)
	{
		printf("\nErro: Definições de VIP fora dos limites da sala.\n");
		return;
	}
	if (PREF_FILA_INICIO - 'A' < 0 || PREF_FILA_FIM - 'A' >= N_FILAS || PREF_FILA_INICIO > PREF_FILA_FIM ||
		PREF_COL_INICIO < 0 || PREF_COL_FIM >= N_COLS || PREF_COL_INICIO > PREF_COL_FIM)
	{
		printf("\nErro: Definições preferenciais fora dos limites da sala.\n");
		return;
	}

	printf("\nPoltronas definidas com sucesso!\n");

	printf("\nEntre com o valor do ingresso normal: ");
	scanf("%lf", &valor);

	for (i = 0; i < N_FILAS; i++)
	{
		for (j = 0; j < N_COLS; j++)
		{
			cine->P[i][j].livre = TRUE;
			cine->P[i][j].tipo_cliente = 'N';
			cine->P[i][j].tipo_poltrona = 'N';
			(*cine).P[i][j].valor = valor;
		}
	}

	cine_define_vip(cine);
	cine_define_preferencial(cine);
}

void cine_mostrar_especiais(const Cine *cine)
{
	int i, j;

	printf("\n--- Poltronas Especiais ---\n");
	printf("\nPreferenciais (P):\n");

	for (i = 0; i < N_FILAS; i++)
	{
		for (j = 0; j < N_COLS; j++)
		{
			if (cine->P[i][j].tipo_cliente == 'P')
			{
				printf("Fila %c, Coluna %d\n", 'A' + i, j);
			}
		}
	}

	printf("\nVIPs (V):\n");

	for (i = 0; i < N_FILAS; i++)
	{
		for (j = 0; j < N_COLS; j++)
		{
			if (cine->P[i][j].tipo_poltrona == 'V')
			{
				printf("Fila %c, Coluna %d\n", 'A' + i, j);
			}
		}
	}
}

void cine_print(const Cine *cine)
{
	int i, j;

	printf("\n--- TELA ---\n\n");
	
	for (i = 0; i < N_FILAS; i++)
	{
		for (j = 0; j < N_COLS; j++)
		{
			if (cine->P[i][j].livre)
				printf("o ");
			else
				printf("x ");
		}
		printf("\n");
	}
}

#define RESERVAR 1
#define LIBERAR 2
#define VISUALIZAR 3
#define VALOR_RESERVA 4
#define SAIR 5

int cine_menu(void)
{
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
void cine_reservar(Cine *cine, char fila, int col)
{
	int l, c;

	if (fila == 10)
	{
		printf("\nHahah vc digitou um ENTER\n\n");
	}

	l = fila - 'A';

	if (l < 0 || l > 3)
	{
		printf("\nFileira invalida!!!\n");
		return;
	}
	if (col < 0 || col > 5)
	{
		printf("\nColuna invalida!!!\n");
		return;
	}
	if (cine->P[l][col].livre == FALSE)
	{
		printf("\nPoltrona ja ocupada!!!\n");
		return;
	}
	else
	{
		cine->P[l][col].livre = FALSE;
		printf("\nPoltrona reservada com sucesso!!!\n");
	}
}

void cine_liberar(Cine *cine, char fila, int col)
{
	int l = fila - 'A';

	if (l < 0 || l >= N_FILAS || col < 0 || col >= N_COLS)
	{
		printf("\nPosição inválida!\n");
		return;
	}
	if (cine->P[l][col].livre)
	{
		printf("\nA poltrona já está livre!\n");
	}
	else
	{
		cine->P[l][col].livre = TRUE;
		printf("\nPoltrona liberada com sucesso!\n");
	}
}

void cine_valor_total(const Cine *cine)
{
	double total = 0.0;
	
	for (int i = 0; i < N_FILAS; i++)
	{
		for (int j = 0; j < N_COLS; j++)
		{
			if (!cine->P[i][j].livre)
			{
				total += cine->P[i][j].valor;
			}
		}
	}
	printf("\nValor total das reservas: R$ %.2lf\n", total);
}

int main()
{
	char fila;
	int col;
	int op;
	Cine Kinoplex;
	cine_init(&Kinoplex);

	while (1)
	{
		op = cine_menu();

		switch (op)
		{
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------------*/
// Função Principal
/*-----------------*/
int main() {
    int N, M, P;        // Variáveis para número de casos, número de produtos e itens na lista de compras
    double total = 0.0; // Variável para acumular o valor total das compras
    int i, j;           // Variáveis auxiliares para loops

    char **produto = NULL;           // Array de strings para armazenar os nomes dos produtos
    char **lista_compras = NULL;     // Array de strings para armazenar os nomes dos itens na lista de compras
    double *valor = NULL;            // Array para armazenar os preços dos produtos
    int *quantidade = NULL;          // Array para armazenar as quantidades dos itens da lista de compras

    scanf("%d", &N);

    while (N--) {
        
        // Lê o número de produtos
        scanf("%d", &M);

        // Aloca memória para os arrays de produtos e preços
        produto = (char **) malloc(M * sizeof(char *));
        valor = (double *) malloc(M * sizeof(double));
        for (i = 0; i < M; i++) {
            produto[i] = (char *) malloc(50 * sizeof(char)); // Cada produto pode ter até 50 caracteres
        }

        // Lê os nomes dos produtos e seus preços
        for (i = 0; i < M; i++) {
            scanf("%s %lf", produto[i], &valor[i]);
        }

        // Lê o número de itens na lista de compras
        scanf("%d", &P);
        if (P < 1 || P > M) return 0; // Validação para evitar entradas inválidas

        // Aloca memória para os arrays da lista de compras
        lista_compras = (char **) malloc(P * sizeof(char *));
        quantidade = (int *) malloc(P * sizeof(int));
        for (i = 0; i < P; i++) {
            lista_compras[i] = (char *) malloc(50 * sizeof(char)); // Cada item pode ter até 50 caracteres
        }

        // Lê os nomes dos itens da lista de compras e suas quantidades
        for (i = 0; i < P; i++) {
            scanf("%s %d", lista_compras[i], &quantidade[i]);
        }

        // Calcula o total da compra comparando os itens da lista de compras com os produtos disponíveis
        for (i = 0; i < P; i++) {
            for (j = 0; j < M; j++) {
                if (strcmp(lista_compras[i], produto[j]) == 0) { // Compara os nomes
                    total += valor[j] * quantidade[i];          // Atualiza o total
                    break;                                     // Encerra o loop interno ao encontrar o item
                }
            }
        }

        // Exibe o valor total formatado
        printf("R$ %.2lf\n", total);
        total = 0.0; // Reseta o total para o próximo caso de teste

        // Libera a memória alocada dinamicamente para os produtos
        for (i = 0; i < M; i++) {
            free(produto[i]);
        }
        free(produto);
        free(valor);

        // Libera a memória alocada dinamicamente para a lista de compras
        for (i = 0; i < P; i++) {
            free(lista_compras[i]);
        }
        free(lista_compras);
        free(quantidade);
    }

    return 0;
}

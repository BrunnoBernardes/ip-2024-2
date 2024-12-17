#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_IMOVEIS 1000000 // Limite máximo de imóveis (conforme a especificação)

typedef struct {
    int habitantes; // Quantidade de pessoas em um imóvel
    int consumo;    // Consumo médio (arredondado para baixo) de água em m³ por pessoa
} Imovel;

typedef struct {
    int habitantes_total; // Total de habitantes na cidade
    int consumo_total;    // Total de consumo de água na cidade
} Cidade;

/* 
 * Função de comparação usada pelo qsort para ordenar os imóveis:
 * - Ordena por consumo em ordem crescente.
 * - Em caso de empate no consumo, ordena pelo número de habitantes em ordem crescente.
 */
int compara(const void *a, const void *b) {
    Imovel *ia = (Imovel *)a;
    Imovel *ib = (Imovel *)b;

    if (ia->consumo == ib->consumo) {
        return ia->habitantes - ib->habitantes; // desempate por quantidade de habitantes
    }
    return ia->consumo - ib->consumo; // ordenação principal por consumo
}

int main() {
    int n, cidade_count = 1; // n: número de imóveis; cidade_count: contador para numerar as cidades
    int i;

    // Enquanto o número de imóveis for diferente de zero
    while (scanf("%d", &n) && n != 0) {
        Cidade cidade = {0, 0};       // Inicializa a cidade com zero habitantes e consumo total
        Imovel imoveis[n];            // Vetor para armazenar os imóveis da cidade atual

        // Leitura dos imóveis: número de habitantes e consumo total de cada imóvel
        for (i = 0; i < n; i++) {
            int habitantes, consumo;
            scanf("%d %d", &habitantes, &consumo);
            imoveis[i].habitantes = habitantes; // Armazena o número de habitantes
            imoveis[i].consumo = consumo / habitantes; // Consumo médio por pessoa (arredondado para baixo)

            cidade.habitantes_total += habitantes; // Soma ao total de habitantes da cidade
            cidade.consumo_total += consumo;       // Soma ao consumo total da cidade
        }

        // Ordena os imóveis pelo consumo médio (e número de habitantes em caso de empate)
        qsort(imoveis, n, sizeof(Imovel), compara);

        // Saída: imprime o número da cidade
        if (cidade_count > 1) {
            printf("\n"); // Adiciona uma linha em branco entre os casos de teste
        }
        printf("Cidade# %d:\n", cidade_count++);

        // Agrupa imóveis com o mesmo consumo médio e soma os habitantes
        for (i = 0; i < n;) {
            int consumo = imoveis[i].consumo; // Consumo médio atual
            int soma_habitantes = 0;

            // Soma os habitantes dos imóveis com o mesmo consumo
            while (i < n && imoveis[i].consumo == consumo) {
                soma_habitantes += imoveis[i].habitantes;
                i++;
            }
            // Imprime o agrupamento no formato "quantidade_habitantes-consumo"
            printf("%d-%d ", soma_habitantes, consumo);
        }

        printf("\n");

        // Calcula o consumo médio total por pessoa (com duas casas decimais)
        double consumo_medio = (double)cidade.consumo_total / cidade.habitantes_total;

        // Trunca o valor para duas casas decimais usando floor
        printf("Consumo medio: %.2lf m3.\n", floor(consumo_medio * 100) / 100);
    }

    return 0;
}

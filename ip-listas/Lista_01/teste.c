#include <stdio.h>

float lucro(int c, int v)
{

    float lucro;
    lucro = (v - c) * 100.00 / c;

    return lucro;
}

int main()
{

    unsigned long int codigo, cml, cmv;
    float preco_compra, preco_venda, total_compras = 0, total_vendas = 0, ltotal;
    int n_vendas, l1 = 0, l2 = 0, l3 = 0, ml = 0, mv = 0, i;

    for (i = 0; i < 4; i++)
    {

        scanf("%u %f %f %d", &codigo, &preco_compra, &preco_venda, &n_vendas);

        if (lucro(preco_compra, preco_venda) < 10)
            l1 += 1;
        if (lucro(preco_compra, preco_venda) >= 10 && lucro(preco_compra, preco_venda) <= 20)
            l2 += 1;
        if (lucro(preco_compra, preco_venda) > 20)
            l3 += 1;
        if (preco_venda - preco_compra > ml)
        {
            ml = preco_venda - preco_compra;
            cml = codigo;
        }
        if (n_vendas > mv)
        {
            mv = n_vendas;
            cmv = codigo;
        }
        total_compras += preco_compra * n_vendas;
        total_vendas += preco_venda * n_vendas;
    }

    ltotal = lucro(total_compras, total_vendas);

    printf("Quantidade de mercadorias que geraram lucro menor que 10%%: %d\n", l1);
    printf("Quantidade de mercadorias que geraram lucro maior ou igual a 10%% e menor ou igual a 20%%: %d\n", l2);
    printf("Quantidade de mercadorias que geraram lucro maior do que 20%%: %d\n", l3);
    printf("Codigo da mercadoria que gerou maior lucro: %u\n", cml);
    printf("Codigo da mercadoria mais vendida: %u\n", cmv);
    printf("Valor total de compras: %.2f, valor total de vendas: %.2f e percentual de lucro total: %.2f%%\n", total_compras, total_vendas, ltotal);

    return 0;
}
#include <stdio.h>

int main () {
    int n, i, x, y, c1, c2; //X equivale ao último valor lido e C é o contador do segmento
    scanf("%d", &n);
    c1 = c2 = 1;

    if (n <= 0){
        printf("O comprimento do segmento crescente maximo e: 0\n");//Não há segmento crescente com valor de n = 0
        return 0;
    }

    scanf("%d", &y);//Y equivale a primeira leitura

    for (i=1; i<n; i++){
        scanf("%d", &x);

        if (x>=y){
            c1++;
        
        } else {
            if (c1>c2){
                c2 = c1;//Nova contagem para o máximo
            }
            c1 = 1;//Reinicia a contagem
        }
        y = x;//Posicionamento do anterior e atual
    }

    if (c1>c2){
        c2 = c1;//Última verificação
    }
    printf("O comprimento do segmento crescente maximo e: %d\n", c2);
    return 0;
}
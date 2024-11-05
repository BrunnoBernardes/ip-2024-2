#include <stdio.h>

int main () {

    int conta;
    float m, v;
    char tipo, lixo1, lixo2;

    scanf("%d%c%f%c%c", &conta, &lixo1, &m, &lixo2, &tipo);

    if (tipo == 'C'){
        if(m <= 80){
            v = 500;
        } else {
            m = m - 80;
            v = (m * 0.25) + 500;
        }
    } else if (tipo == 'I'){
        if(m <= 100){
            v = 800;
        } else {
            m = m - 100;
            v = (m * 0.04) + 800;
        }
    } else if (tipo == 'R') {
        v = (m * 0.05) + 5;
    }
    
    printf("CONTA = %d\n", conta);
    printf("VALOR DA CONTA = %.2f\n", v);

    return 0;
}
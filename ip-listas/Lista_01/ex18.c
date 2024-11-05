#include <stdio.h>
 
int validade(int dia, int mes, int ano) {
    
    if (mes < 1 || mes > 12) return 0;
    if (dia < 1) return 0;
    if (mes == 2) {
        if (dia > 28) return 0;
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if (dia > 30) return 0;
    } else {
        if (dia > 31) return 0;
    }

    return 1;
}

int main () {
    
    int data, dia, mes, ano;

    scanf("%d", &data);

    dia = data / 1000000;
    mes = (data / 10000) % 100;
    ano = data % 10000;

    if (validade(dia, mes, ano)==0) {

        printf("Data invalida!\n");

        } else {

            if (mes == 1) printf("%d de janeiro de %d\n", dia, ano);
            if (mes == 2) printf("%d de fevereiro de %d\n", dia, ano);
            if (mes == 3) printf("%d de março de %d\n", dia, ano);
            if (mes == 4) printf("%d de abril de %d\n", dia, ano);
            if (mes == 5) printf("%d de maio de %d\n", dia, ano);
            if (mes == 6) printf("%d de junho de %d\n", dia, ano);
            if (mes == 7) printf("%d de julho de %d\n", dia, ano);
            if (mes == 8) printf("%d de agosto de %d\n", dia, ano);
            if (mes == 9) printf("%d de setembro de %d\n", dia, ano);
            if (mes == 10) printf("%d de outubro de %d\n", dia, ano);
            if (mes == 11) printf("%d de novembro de %d\n", dia, ano);
            if (mes == 12) printf("%d de dezembro de %d\n", dia, ano);

        }
 
    return 0;
}
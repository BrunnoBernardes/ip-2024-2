#include <stdio.h>

int main () {

    int matricula;
    double p1, p2, p3, p4, p5, p6, p7, p8;
    double l1, l2, l3, l4, l5;
    double trabalho, nota_final;
    int presenca;

    while (1){
        scanf("%d", &matricula);

        if (matricula == -1){
            break;
            
        } else {
            scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%d", &p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, &l1, &l2, &l3, &l4, &l5, &trabalho, &presenca);
            nota_final = (0.7*(p1+p2+p3+p4+p5+p6+p7+p8)/8)+(0.15*(l1+l2+l3+l4+l5)/5)+(0.15*trabalho);

            if (matricula < 0){
                matricula = matricula * (-1);
            }

            if (presenca >= 96 && nota_final >= 6){
                printf("Matricula: %d, Nota Final: %.2lf, Situacao Final: APROVADO\n", matricula, nota_final);
            } else if (presenca < 96 && nota_final >= 6) {
                printf("Matricula: %d, Nota Final: %.2lf, Situacao Final: REPROVADO POR FREQUENCIA\n", matricula, nota_final);
            } else if (presenca >= 96 && nota_final < 6) {
                printf("Matricula: %d, Nota Final: %.2lf, Situacao Final: REPROVADO POR NOTA\n", matricula, nota_final);
            } else if (presenca < 96 && nota_final < 6) {
                printf("Matricula: %d, Nota Final: %.2lf, Situacao Final: REPROVADO POR NOTA E POR FREQUENCIA\n", matricula, nota_final);
            }
        }
    }

    return 0;
}
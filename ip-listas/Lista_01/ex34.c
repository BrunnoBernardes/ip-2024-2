#include <stdio.h>
#include <math.h>
 
int calcula_limite(int num, int den) {
    if(num<den) return sqrt(num);
    else return sqrt(den);
    }
 
int e_inteiro(double x) {
    int k = x;
    if (k==x) return 1;
    else return 0;
}
 
//atenção para 14.05601
int main () {
    double x;
    unsigned long long int num, den=1;
    int div, limite;
    scanf("%lf", &x);
 
    while(1){
        if(e_inteiro(x)==1) break;
        x = x*10;
        den = den*10;
    }
    num = x;
    div = 2;
    limite = calcula_limite(num, den);
 
    while(1){
        if(div>limite) break;
        if(num%div==0 && den%div==0){
            num =num/div;
            den = den/div;
            div = 2;
            limite = calcula_limite(num, den);
        } else {
            div++;
        }
    }
    printf("%llu/%llu\n", num, den);
    return 0;
}
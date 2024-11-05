#include <stdio.h>
 
int main (){
 
    int hi, mi, hf, mf, ht, mt;
 
    scanf("%d %d %d %d", &hi, &mi, &hf, &mf);
 
    ht = hf - hi;
    mt = mf - mi;
 
    if (mi==hi && mi==mf && mi==hf){
        printf("O JOGO DUROU 24 HORA(S) E 00 MINUTO(S)\n");
    } else {
        if (mt < 0) {
            ht -= 1;
            mt += 60;
        }
        if (ht < 0) {
            ht += 24;
        }
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", ht, mt);
    }
    /*if (hi<hf){
        if(mi<=mf){
            ht = hf - hi;
            mt = mf - mi;
        } else {
            ht = hf - hi - 1;
            mt = mf - mi + 60;
        }
    } else if (hi>hf){
        if(mi<=mf){
            ht = hf - hi;
            mt = mf - mi;
        } else {
            ht = hf - hi - 1;
            mt = mf - mi + 60;
        }
    }*/
    return 0;
}
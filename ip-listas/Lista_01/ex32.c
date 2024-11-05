#include <stdio.h>
 
int main () {
    int n, atual, anterior;
    int ordem, intercalada;
    int i;
 
    while (1){
        scanf("%d", &n);
        if (n==0) break;
 
        scanf("%d", &anterior);
        scanf("%d", &atual);
 
        if (atual>anterior) ordem = +1; //cresce
        else if (atual<anterior) ordem = -1; //decresce
        else ordem = 0;
 
        if (ordem==0) intercalada = 0;
        else intercalada = 1;
 
        for (i=2;i<n;i++){
            anterior = atual;
            scanf("%d", &atual);
 
            if(atual>anterior && ordem==-1){
                ordem = +1;
            } else if (atual<anterior && ordem==+1){
                ordem = -1;
            } else {
                intercalada = 0;
            }
        }
        if(intercalada==1){
            printf("Intercalada\n");
        } else {
            printf("Nao intercalada\n");
        }
    }
 
    return 0;
}
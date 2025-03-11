#include <stdio.h>
#include <stdlib.h>
 
typedef struct {
    int likes;
    int retweets;
    int mencoes;
} Usuario;
 
 
int main () {
 
    int N;
 
    // Lê o número de linhas e colunas da matriz quadrada
    scanf("%d", &N);
 
    // Valida o número fornecido
    if (N > 1000) {
        return 0;
    }
 
    int M;
 
    // Lê o número de pares não nulos
    scanf("%d", &M);
 
    // Valida o número fornecido
    if (M < 1 || M > N*N) {
        return 0;
    }
 
    // Número de slots não preenchidos da matriz
    int slotsVazios = (N*N) - M;
 
    int i;
    Usuario *lista = NULL;
 
    // Aloca memória para a lista de funcionários
    lista = (Usuario*)malloc(N*N * sizeof(Usuario));
    if (!lista) {
        return 0; // Encerra o programa se a alocação falhar
    }
 
    int usuario1, usuario2, likes, retweets, mencoes;
    int num_usuarios = 0;
    int total_likes = 0, total_retweets = 0, total_mencoes = 0;
 
    for (i = 0; i < M; i++) {
        scanf("%d %d %d %d %d", &usuario1, 
                                &usuario2, 
                                &likes, 
                                &retweets, 
                                &mencoes);
 
        lista[usuario1].likes += likes;
        lista[usuario1].retweets += retweets;
        lista[usuario1].mencoes += mencoes;
 
        total_likes += likes;
        total_retweets += retweets;
        total_mencoes += mencoes;
    }
 
    for (i = 0; i < M; i++) {
        if (lista[i].likes != 0 || lista[i].retweets != 0 || lista[i].mencoes != 0) {
            num_usuarios += 1;
        }
    }
 
    double mediaLikes = (double)total_likes/(double)num_usuarios;
    double mediaRetweets = (double)total_retweets/(double)num_usuarios;
    double mediaMencoes = (double)total_mencoes/(double)num_usuarios;
 
    // printf("Numero de usuarios: %d\n", num_usuarios);
 
    for (i = 0; i < N; i++) {
        if (lista[i].likes != 0 || lista[i].retweets != 0 || lista[i].mencoes != 0) 
            printf("Usuario %d - num. likes: %d, num. retweets: %d e num. mencoes: %d\n", i, lista[i].likes, lista[i].retweets, lista[i].mencoes);
    }
 
    printf("Slots vazios: %d\n", slotsVazios);
    printf("Media de likes por usuario: %.2lf\n", mediaLikes);
    printf("Media de retweets por usuario: %.2lf\n", mediaRetweets);
    printf("Media de mencoes por usuario: %.2lf\n", mediaMencoes);
 
    free(lista);
 
    return 0;
}
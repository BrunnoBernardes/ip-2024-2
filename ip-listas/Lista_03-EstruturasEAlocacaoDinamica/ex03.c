#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Estrutura para armazenar um país e sua saudação
typedef struct {
    char pais[50];
    char saudacao[50];
} PaisSaudacao;

int main() {
    int i, numPaises = 24;
    char entrada[50];
    int found;
    PaisSaudacao* lista = NULL;

    // Alocação dinâmica para a lista de países e saudações
    lista = (PaisSaudacao*)malloc(numPaises * sizeof(PaisSaudacao));
    if (!lista) {
        return 1;
    }

    // Inicializa os valores numa variavel temporária para não precisar fazer manualmente
    PaisSaudacao temp[] = {
        {"brasil", "Feliz Natal!"},
        {"alemanha", "Frohliche Weihnachten!"},
        {"austria", "Frohe Weihnacht!"},
        {"coreia", "Chuk Sung Tan!"},
        {"espanha", "Feliz Navidad!"},
        {"grecia", "Kala Christougena!"},
        {"estados-unidos", "Merry Christmas!"},
        {"inglaterra", "Merry Christmas!"},
        {"australia", "Merry Christmas!"},
        {"portugal", "Feliz Natal!"},
        {"suecia", "God Jul!"},
        {"turquia", "Mutlu Noeller"},
        {"argentina", "Feliz Navidad!"},
        {"chile", "Feliz Navidad!"},
        {"mexico", "Feliz Navidad!"},
        {"antartida", "Merry Christmas!"},
        {"canada", "Merry Christmas!"},
        {"irlanda", "Nollaig Shona Dhuit!"},
        {"belgica", "Zalig Kerstfeest!"},
        {"italia", "Buon Natale!"},
        {"libia", "Buon Natale!"},
        {"siria", "Milad Mubarak!"},
        {"marrocos", "Milad Mubarak!"},
        {"japao", "Merii Kurisumasu!"}
    };

    // Copia os valores iniciais para a lista dinâmica usando um loop
    for (i = 0; i < numPaises; i++) {
        strcpy(lista[i].pais, temp[i].pais);
        strcpy(lista[i].saudacao, temp[i].saudacao);
    }

    // Leitura do nome do país
    while (scanf("%s", entrada) != EOF) {
        found = 0;
        for (i = 0; i < numPaises; i++) {
            if (strcasecmp(entrada, lista[i].pais) == 0) { // Ignora maiúsculas e minúsculas
                printf("%s\n", lista[i].saudacao);
                found = 1;
                break;
            }
        }
        if (!found) { // Se não encontrar o país
            printf("-- NOT FOUND --\n");
        }
    }

    // Liberação da memória alocada dinamicamente
    free(lista);

    return 0;
}

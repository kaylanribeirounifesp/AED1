#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produtos {
    float valor;
    char id[51];
};
typedef struct Produtos produto;

void precheervalor(produto *m, int M) {
    for(int i = 0; i < M; i++) {
        scanf("%50s", m[i].id);
        scanf("%f", &m[i].valor); 
    }
}

float calcula(produto *m, int TAM) {
    char teste[51];
    int q;
    float valorfinal = 0.0;

    scanf("%50s", teste);
    scanf("%d", &q);

    for(int i = 0; i < TAM; i++) {
        if(strcmp(m[i].id, teste) == 0) { // Correção na comparação
            valorfinal = q * m[i].valor;
            return valorfinal;
        }
    }
    return -1;
}

int main() {
    int n, TAM, p;
    float r;

    scanf("%d", &n);
    getchar();

    for(int i = 0; i < n; i++) {
        scanf("%d", &TAM);
        produto* m = (produto*)malloc(TAM * sizeof(produto));

        precheervalor(m, TAM);

        scanf("%d", &p);
        getchar();

        r = 0; // Inicializa `r` antes da soma

        for(int j = 0; j < p; j++) { // Corrigido `j++` no loop
            r += calcula(m, TAM);
        }

        printf("R$ %.2f\n", r); // Exibe o resultado final

        free(m);
    }

    return 0;
}

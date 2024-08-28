#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cel {
    char nome[51];
    struct cel *seg;
};
typedef struct cel celula;

void insere(celula *lst, char *palavra) {
    celula *nova = (celula *)malloc(sizeof(celula));
    strcpy(nova->nome, palavra);
    nova->seg = NULL;

    celula *p = lst->seg;
    celula *ant = NULL;

    // Percorre a lista e encontra a posição correta para inserir
    while (p != NULL && strlen(p->nome) >= strlen(nova->nome)) {
        ant = p;
        p = p->seg;
    }

    // Se a lista estiver vazia ou nova célula for a primeira
    if (ant == NULL) {
        nova->seg = lst->seg;
        lst->seg = nova;
    } else {
        nova->seg = ant->seg;
        ant->seg = nova;
    }
}

void imprima(celula *lst) {
    celula *p = lst->seg;
    while (p != NULL) {
        printf("%s", p->nome);
        if (p->seg != NULL) printf(" ");
        p = p->seg;
    }
    printf("\n");
}

void limpar(celula *l) {
    celula *p = l->seg;
    while (l->seg != NULL) {
        l->seg = p->seg;
        free(p);
        p = l->seg;
    }
}

int main() {
    char frase[252];
    int n;
    celula *lista = (celula *)malloc(sizeof(celula));
    lista->seg = NULL;
    char *item;

    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        fgets(frase, sizeof(frase), stdin);
        frase[strcspn(frase, "\n")] = '\0'; // Remove o '\n'

        item = strtok(frase, " ");
        while (item) {
            insere(lista, item);
            item = strtok(NULL, " ");
        }

        imprima(lista); // Imprime a lista após inserções
        limpar(lista);  // Limpa a lista para a próxima iteração
    }

    free(lista); // Libera a memória da lista principal
    return 0;
}

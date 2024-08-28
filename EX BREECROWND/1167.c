#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura da lista duplamente encadeada
struct lista2 {
    char nome[31];
    int valor;
    struct lista2* ant;
    struct lista2* prox;
};
typedef struct lista2 Clista;

// Função para criar um novo nó na lista
Clista* insere(Clista* l, char *nome, int valor) {
    Clista* novo = (Clista*) malloc(sizeof(Clista));
    strcpy(novo->nome, nome);
    novo->valor = valor;
    novo->prox = l;
    novo->ant = NULL;
    if (l != NULL) {
        l->ant = novo;
    }
    return novo;
}

// Função para remover um elemento da lista e retorna o próximo nó
Clista* remove_e_retorna_proximo(Clista* atual) {
    Clista* proximo = atual->prox;
    if (atual->ant != NULL) {
        atual->ant->prox = atual->prox;
    }
    if (atual->prox != NULL) {
        atual->prox->ant = atual->ant;
    }
    free(atual);
    return proximo;
}

// Função para determinar o vencedor
void determinar_vencedor(int n, Clista* lista) {
    Clista* atual = lista->ant;  // Inicia ao lado da primeira criança
    while (n > 1) {
        int passos = atual->valor;
        if (passos % 2 == 0) {  // Sentido horário
            for (int i = 0; i < passos; i++) {
                atual = atual->prox;
                if (atual == NULL) atual = lista; // Circular
            }
        } else {  // Sentido anti-horário
            for (int i = 0; i < passos; i++) {
                atual = atual->ant;
                if (atual == NULL) atual = lista->ant; // Circular
            }
        }

        // Remove a criança atual e ajusta a lista
        Clista* temp = atual;
        atual = (passos % 2 == 0) { atual->prox : atual->ant;
        }
        if (temp == lista) {
            lista = remove_e_retorna_proximo(temp);
        } else {
            remove_e_retorna_proximo(temp);
        }
        n--;
    }
    printf("Vencedor(a): %s\n", lista->nome);
}


int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        Clista* lista = NULL;
        Clista* ultimo = NULL;
        for (int i = 0; i < n; i++) {
            char nome[31];
            int valor;
            scanf("%s %d", nome, &valor);
            lista = insere(lista, nome, valor);
            if (i == 0) {
                ultimo = lista;
            }
        }
        // Tornar a lista circular
        lista->ant = ultimo;
        ultimo->prox = lista;
        
        // Determina o vencedor
        determinar_vencedor(n, lista);
        
        // Libera a memória
        while (lista != NULL) {
            lista = remove_e_retorna_proximo(lista);
        }
    }
    return 0;
}

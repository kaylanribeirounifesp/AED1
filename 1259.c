#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da lista ligada
struct LISTA {
    int val;              // Valor armazenado no nó
    struct LISTA *seg;    // Ponteiro para o próximo nó na lista
};

typedef struct LISTA lst;  // Definindo um alias para a estrutura

// Função para inserir um valor na lista de números pares em ordem crescente
void insere(lst *p, int x) {
    lst *q, *ant;
    ant = NULL;
    q = p->seg;  // Inicia a busca a partir do primeiro elemento
    lst *novo = (lst *) malloc(sizeof(lst));  // Aloca memória para o novo nó
    if (novo == NULL) {
        printf("não foi possível alocar memória");
    }
    novo->val = x;  // Atribui o valor ao novo nó

    // Caso a lista esteja vazia, insere o primeiro elemento
    if (p->seg == NULL) {
        p->seg = novo;  // O novo nó se torna o primeiro elemento da lista
        novo->seg = NULL;  // Define o próximo nó como NULL, já que é o único nó
    } else {
        // Percorre a lista para encontrar a posição correta para inserir o novo nó
        while (q != NULL && x > q->val) {  // Mantém a ordem crescente
            ant = q;
            q = q->seg;
        }

        // Insere no início da lista se for o menor valor
        if (ant == NULL) {
            novo->seg = p->seg;  // O novo nó aponta para o atual primeiro nó
            p->seg = novo;       // O novo nó se torna o primeiro da lista
        } else {
            // Insere no meio ou no final da lista
            ant->seg = novo;  // O nó anterior aponta para o novo nó
            novo->seg = q;    // O novo nó aponta para o próximo nó na lista
        }
    }
}

// Função para inserir um valor na lista de números ímpares em ordem decrescente
void insereimpar(lst *p, int x) {
    lst *q, *ant;
    ant = NULL;
    q = p->seg;  // Inicia a busca a partir do primeiro elemento
    lst *novo = (lst *) malloc(sizeof(lst));  // Aloca memória para o novo nó
    if (novo == NULL) {
        printf("não foi possível alocar memória");
    }
    novo->val = x;  // Atribui o valor ao novo nó

    // Caso a lista esteja vazia, insere o primeiro elemento
    if (p->seg == NULL) {
        p->seg = novo;  // O novo nó se torna o primeiro elemento da lista
        novo->seg = NULL;  // Define o próximo nó como NULL, já que é o único nó
    } else {
        // Percorre a lista para encontrar a posição correta para inserir o novo nó
        while (q != NULL && x < q->val) {  // Mantém a ordem decrescente
            ant = q;
            q = q->seg;
        }

        // Insere no início da lista se for o maior valor
        if (ant == NULL) {
            novo->seg = p->seg;  // O novo nó aponta para o atual primeiro nó
            p->seg = novo;       // O novo nó se torna o primeiro da lista
        } else {
            // Insere no meio ou no final da lista
            ant->seg = novo;  // O nó anterior aponta para o novo nó
            novo->seg = q;    // O novo nó aponta para o próximo nó na lista
        }
    }
}

// Função para imprimir os valores de uma lista
void imprime(lst *p) {
    lst *q = p->seg;  // Inicia a partir do primeiro elemento válido da lista

    // Percorre toda a lista imprimindo os valores
    while (q != NULL) {
        printf("%d\n", q->val);
        q = q->seg;  // Avança para o próximo nó
    }
}

int main() {
    int n, x;
    lst *par = (lst*)malloc(sizeof(lst));  // Cria a lista para números pares
    lst *impar = (lst*)malloc(sizeof(lst));  // Cria a lista para números ímpares
    par->seg = NULL;  // Inicializa a lista de pares vazia
    impar->seg = NULL;  // Inicializa a lista de ímpares vazia
    scanf("%d", &n);  // Lê o número de elementos a serem inseridos

    // Loop para inserir todos os elementos
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);  // Lê o próximo valor
        if (x % 2 == 0) {
            insere(par, x);  // Insere o valor na lista de pares
        } else {
            insereimpar(impar, x);  // Insere o valor na lista de ímpares
        }
    }

    printf("\n");
    imprime(par);  // Imprime os números pares em ordem crescente
    imprime(impar);  // Imprime os números ímpares em ordem decrescente

    return 0;
}

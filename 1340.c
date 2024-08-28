#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10000 // Define o tamanho máximo das estruturas de dados

// Estrutura para a fila
typedef struct {
    int itens[MAX];
    int frente, tras;
} Fila;

// Inicializa a fila
void inicializarFila(Fila *f) {
    f->frente = 0;
    f->tras = -1;
}

// Verifica se a fila está vazia
bool filaVazia(Fila *f) {
    return f->frente > f->tras;
}

// Adiciona um item à fila
void enfileirar(Fila *f, int item) {
    f->itens[++(f->tras)] = item;
}

// Remove e retorna o item da frente da fila
int desenfileirar(Fila *f) {
    return f->itens[(f->frente)++];
}

// Estrutura para a pilha
typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

// Inicializa a pilha
void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

// Verifica se a pilha está vazia
bool pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

// Adiciona um item à pilha
void empilhar(Pilha *p, int item) {
    p->itens[++(p->topo)] = item;
}

// Remove e retorna o item do topo da pilha
int desempilhar(Pilha *p) {
    return p->itens[(p->topo)--];
}

// Estrutura para a fila de prioridade (max heap)
typedef struct {
    int itens[MAX];
    int tamanho;
} FilaPrioridade;

// Inicializa a fila de prioridade
void inicializarFilaPrioridade(FilaPrioridade *fp) {
    fp->tamanho = 0;
}

// Verifica se a fila de prioridade está vazia
bool filaPrioridadeVazia(FilaPrioridade *fp) {
    return fp->tamanho == 0;
}

// Ajusta a estrutura do heap para manter a propriedade do max heap
void heapify(FilaPrioridade *fp, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;
    int temp;

    // Verifica se o filho da esquerda é maior
    if (esquerda < fp->tamanho && fp->itens[esquerda] > fp->itens[maior])
        maior = esquerda;

    // Verifica se o filho da direita é maior
    if (direita < fp->tamanho && fp->itens[direita] > fp->itens[maior])
        maior = direita;

    // Se o maior não for o nó atual, troca e continua ajustando
    if (maior != i) {
        temp = fp->itens[i];
        fp->itens[i] = fp->itens[maior];
        fp->itens[maior] = temp;
        heapify(fp, maior);
    }
}

// Adiciona um item à fila de prioridade
void inserirFilaPrioridade(FilaPrioridade *fp, int item) {
    int i = fp->tamanho++;
    fp->itens[i] = item;

    // Ajusta a posição do item para manter a propriedade do heap
    while (i != 0 && fp->itens[(i - 1) / 2] < fp->itens[i]) {
        int temp = fp->itens[i];
        fp->itens[i] = fp->itens[(i - 1) / 2];
        fp->itens[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Remove e retorna o maior item da fila de prioridade
int removerFilaPrioridade(FilaPrioridade *fp) {
    int raiz = fp->itens[0];
    fp->itens[0] = fp->itens[--(fp->tamanho)];
    heapify(fp, 0);
    return raiz;
}

int main() {
    int n, operacao, numero;

    // Lê a quantidade de operações e processa até o final da entrada
    while (scanf("%d", &n) == 1) {
        Pilha pilha;
        Fila fila;
        FilaPrioridade filaPrioridade;

        // Inicializa as estruturas de dados
        inicializarPilha(&pilha);
        inicializarFila(&fila);
        inicializarFilaPrioridade(&filaPrioridade);

        bool podeSerPilha = true, podeSerFila = true, podeSerFilaPrioridade = true;

        // Processa cada operação
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &operacao, &numero);

            if (operacao == 1) { // Inserção
                if (podeSerPilha) empilhar(&pilha, numero);
                if (podeSerFila) enfileirar(&fila, numero);
                if (podeSerFilaPrioridade) inserirFilaPrioridade(&filaPrioridade, numero);
            } else { // Remoção
                if (podeSerPilha) {
                    if (pilhaVazia(&pilha) || desempilhar(&pilha) != numero) {
                        podeSerPilha = false;
                    }
                }

                if (podeSerFila) {
                    if (filaVazia(&fila) || desenfileirar(&fila) != numero) {
                        podeSerFila = false;
                    }
                }

                if (podeSerFilaPrioridade) {
                    if (filaPrioridadeVazia(&filaPrioridade) || removerFilaPrioridade(&filaPrioridade) != numero) {
                        podeSerFilaPrioridade = false;
                    }
                }
            }
        }

        // Determina e imprime o tipo de estrutura de dados
        if (podeSerPilha && !podeSerFila && !podeSerFilaPrioridade)
            printf("stack\n");
        else if (!podeSerPilha && podeSerFila && !podeSerFilaPrioridade)
            printf("queue\n");
        else if (!podeSerPilha && !podeSerFila && podeSerFilaPrioridade)
            printf("priority queue\n");
        else if (!podeSerPilha && !podeSerFila && !podeSerFilaPrioridade)
            printf("impossible\n");
        else
            printf("not sure\n");
    }

    return 0;
}

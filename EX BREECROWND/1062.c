#include <stdlib.h>
#include <stdio.h>

// Estrutura para representar um nó da pilha
struct pilhaNo {
    int valor;                // Valor armazenado no nó
    struct pilhaNo* abaixo;   // Ponteiro para o nó abaixo na pilha
};

// Estrutura para representar a pilha
struct pilha {
    int tamanho;              // Tamanho da pilha (número de elementos)
    struct pilhaNo* topo;     // Ponteiro para o topo da pilha
};

// Função para empilhar um valor na pilha
void push(struct pilha* p, int valor) {
    p->tamanho += 1;  // Incrementa o tamanho da pilha
    struct pilhaNo* novoTopo = (struct pilhaNo*) malloc(sizeof(struct pilhaNo));  // Aloca memória para o novo nó

    novoTopo->valor = valor;  // Define o valor do novo nó
    novoTopo->abaixo = p->topo;  // O nó abaixo do novo topo é o antigo topo
    p->topo = novoTopo;  // Atualiza o topo da pilha
}

// Função para desempilhar um valor da pilha
void pop(struct pilha* p) {
    if (p->tamanho > 0) {  // Verifica se a pilha não está vazia
        p->tamanho -= 1;  // Decrementa o tamanho da pilha
        struct pilhaNo* velhoTopo = p->topo;  // Armazena o topo atual
        p->topo = p->topo->abaixo;  // Atualiza o topo para o nó abaixo
        free(velhoTopo);  // Libera a memória do nó removido
    }
}

// Função para obter o valor no topo da pilha
int top(struct pilha* p) {
    return p->topo->valor;  // Retorna o valor armazenado no topo da pilha
}

// Função para obter o tamanho da pilha
int size(struct pilha* p) {
    return p->tamanho;  // Retorna o tamanho da pilha
}

// Função para verificar se a pilha está vazia
int empty(struct pilha* p) {
    return p->tamanho == 0;  // Retorna 1 se a pilha estiver vazia, caso contrário, retorna 0
}

// Função para inicializar a pilha
void inicializa(struct pilha* p) {
    p->tamanho = 0;  // Define o tamanho da pilha como 0
    p->topo = NULL;  // Define o topo da pilha como NULL
}

// Função para destruir a pilha (liberar todos os nós)
void destroi(struct pilha* p) {
    while (!empty(p)) {  // Enquanto a pilha não estiver vazia
        pop(p);  // Desempilha o topo
    }
}

// Função principal
int main() {
    int N, x;
    struct pilha A, estacao, B;

    // Loop para ler a entrada até EOF
    while (scanf("%d", &N) != EOF) {
        if (!N) break;  // Se N for 0, termina o programa

        // Loop para processar cada sequência de entrada
        while (scanf("%d", &x)) {
            if (!x) {
                printf("\n");  // Se x for 0, imprime uma linha em branco e termina a sequência
                break;
            }

            inicializa(&A);  // Inicializa a pilha A
            inicializa(&estacao);  // Inicializa a pilha estação
            inicializa(&B);  // Inicializa a pilha B

            push(&A, x);  // Empilha o primeiro valor em A
            push(&B, 1);  // Empilha 1 em B (representa o primeiro valor esperado)
            for (int i = 2; i <= N; ++i) {  // Loop para os valores restantes
                scanf("%d", &x);  // Lê o próximo valor
                push(&A, x);  // Empilha em A
                push(&B, i);  // Empilha o próximo valor esperado em B
            }

            // Loop para simular o processo de reorganização
            while (!empty(&A) || !empty(&estacao) || !empty(&B)) {
                if (!empty(&A) && !empty(&B) && top(&A) == top(&B)) {
                    // Se o topo de A e B forem iguais, desempilha ambos
                    pop(&A);
                    pop(&B);
                } else if (!empty(&estacao) && !empty(&B) && top(&estacao) == top(&B)) {
                    // Se o topo da estação e de B forem iguais, desempilha ambos
                    pop(&estacao);
                    pop(&B);
                } else if (!empty(&A)) {
                    // Se A não estiver vazia, empilha o topo de A na estação
                    push(&estacao, top(&A));
                    pop(&A);
                } else {
                    // Se não for possível continuar, sai do loop
                    break;
                }
            }

            // Verifica se todas as pilhas estão vazias, indicando sucesso
            if (empty(&A) && empty(&estacao) && empty(&B)) {
                printf("Yes\n");  // Se todas as pilhas estiverem vazias, imprime "Yes"
            } else {
                printf("No\n");  // Caso contrário, imprime "No"
            }

            // Destroi as pilhas para liberar memória
            destroi(&A);
            destroi(&estacao);
            destroi(&B);
        }
    }

    return 0;
}

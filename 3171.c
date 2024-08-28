#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

// Lista de adjacência para o grafo
typedef struct Celula {
    int vertex;
    struct Celula *next;
} Celula;

Celula *adjList[MAX_N];
int visited[MAX_N];

// Função para adicionar uma aresta ao grafo
void addEdge(int u, int v) {
    Celula *cell = (Celula *)malloc(sizeof(Celula));
    cell->vertex = v;
    cell->next = adjList[u];
    adjList[u] = cell;
    
    cell = (Celula *)malloc(sizeof(Celula));
    cell->vertex = u;
    cell->next = adjList[v];
    adjList[v] = cell;
}

// Função de DFS para marcar os vértices visitados
void dfs(int v) {
    visited[v] = 1;
    Celula *cell = adjList[v];
    while (cell != NULL) {
        if (!visited[cell->vertex]) {
            dfs(cell->vertex);
        }
        cell = cell->next;
    }
}

int main() {
    int N, L;
    
    // Leitura do número de segmentos e conexões
    scanf("%d %d", &N, &L);
    
    // Inicializa a lista de adjacência e o vetor de visitados
    for (int i = 1; i <= N; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }
    
    // Leitura das conexões e construção do grafo
    for (int i = 0; i < L; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    
    // Inicia a DFS a partir do primeiro segmento
    dfs(1);
    
    // Verifica se todos os segmentos foram visitados
    int completo = 1;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            completo = 0;
            break;
        }
    }
    
    // Imprime o resultado
    if (completo) {
        printf("COMPLETO\n");
    } else {
        printf("INCOMPLETO\n");
    }
    
    // Libera a memória alocada
    for (int i = 1; i <= N; i++) {
        Celula *cell = adjList[i];
        while (cell != NULL) {
            Celula *temp = cell;
            cell = cell->next;
            free(temp);
        }
    }
    
    return 0;
}

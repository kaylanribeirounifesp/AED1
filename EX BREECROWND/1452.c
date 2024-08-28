#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPS 101
#define MAX_CLIENTES 200
#define MAX_SERVIDORES 200

// Estruturas para armazenar as aplicações dos servidores e clientes
typedef struct {
    char apps[MAX_APPS][21];
    int count;
} Servidor;

typedef struct {
    char apps[MAX_APPS][21];
    int count;
} Cliente;

// Função para verificar se uma aplicação está no conjunto de aplicações
int contem(char arr[][21], int size, const char *app) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(arr[i], app) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int N, M;
    
    while (scanf("%d %d", &N, &M) == 2 && (N != 0 || M != 0)) {
        Servidor servidores[MAX_SERVIDORES];
        Cliente clientes[MAX_CLIENTES];

        // Ler dados dos servidores
        for (int i = 0; i < N; ++i) {
            int Qi;
            scanf("%d", &Qi);
            servidores[i].count = Qi;
            for (int j = 0; j < Qi; ++j) {
                scanf("%s", servidores[i].apps[j]);
            }
        }

        // Ler dados dos clientes
        for (int i = 0; i < M; ++i) {
            int Pj;
            scanf("%d", &Pj);
            clientes[i].count = Pj;
            for (int j = 0; j < Pj; ++j) {
                scanf("%s", clientes[i].apps[j]);
            }
        }

        // Contar conexões únicas
        int conexoes = 0;
        int conectado[MAX_CLIENTES][MAX_SERVIDORES] = {0}; // Matriz para rastrear conexões
        
        for (int i = 0; i < M; ++i) { // Para cada cliente
            for (int j = 0; j < N; ++j) { // Para cada servidor
                int conectou = 0;
                for (int k = 0; k < clientes[i].count; ++k) {
                    if (contem(servidores[j].apps, servidores[j].count, clientes[i].apps[k])) {
                        conectou = 1;
                        break;
                    }
                }
                if (conectou) {
                    if (!conectado[i][j]) { // Se ainda não contou essa conexão
                        conectado[i][j] = 1;
                        conexoes++;
                    }
                }
            }
        }
        
        printf("%d\n", conexoes);
    }

    return 0;
}

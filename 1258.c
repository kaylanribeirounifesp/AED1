#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 60
#define MAX_NAME 100

typedef struct {
    char nome[MAX_NAME];
    char cor[10];
    char tamanho;
} Camiseta;

// Função para comparar camisetas
int compararCamisetas(const void *a, const void *b) {
    const Camiseta *cam1 = (const Camiseta *)a;
    const Camiseta *cam2 = (const Camiseta *)b;

    // Comparar pela cor (branco < vermelho)
    int corComparacao = strcmp(cam1->cor, cam2->cor);
    if (corComparacao != 0) {
        return corComparacao;
    }

    // Comparar pelo tamanho (G > M > P)
    if (cam1->tamanho != cam2->tamanho) {
        return (cam2->tamanho - cam1->tamanho); // Ordem decrescente
    }

    // Comparar pelo nome
    return strcmp(cam1->nome, cam2->nome);
}

int main() {
    int N;
    Camiseta camisetas[MAX_N];
    int primeiroCaso = 1;
    
    while (scanf("%d", &N) && N != 0) {
        getchar();  // Consome o '\n' após o número
        
        for (int i = 0; i < N; ++i) {
            fgets(camisetas[i].nome, MAX_NAME, stdin);
            camisetas[i].nome[strcspn(camisetas[i].nome, "\n")] = '\0';  // Remove o '\n'
            
            char corTamanho[20];
            fgets(corTamanho, sizeof(corTamanho), stdin);
            sscanf(corTamanho, "%s %c", camisetas[i].cor, &camisetas[i].tamanho);
        }
        
        // Ordenar camisetas
        qsort(camisetas, N, sizeof(Camiseta), compararCamisetas);
        
        // Imprimir camisetas no formato correto
        if (!primeiroCaso) {
            printf("\n");  // Linha em branco entre casos de teste
        }
        primeiroCaso = 0;
        
        for (int i = 0; i < N; ++i) {
            printf("%s %c %s\n", camisetas[i].cor, camisetas[i].tamanho, camisetas[i].nome);
        }
    }
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função de comparação para qsort
int cmp(const void *a, const void *b) {
    char *problemaA = (char *)a;
    char *problemaB = (char *)b;
    
    // Primeiro critério: vida ('V') antes de disciplina ('D')
    if (problemaA[1] != problemaB[1]) {
        return problemaA[1] == 'V' ? -1 : 1;
    }
    
    // Segundo critério: maior criticidade primeiro
    return problemaB[0] - problemaA[0];
}

int main() {
    int N, M;
    
    // Lendo as dimensões da matriz
    scanf("%d %d", &N, &M);
    
    char problemas[N * M][3];  // Vetor para armazenar todos os problemas
    
    // Lendo a matriz de problemas
    for (int i = 0; i < N * M; i++) {
        scanf("%s", problemas[i]);
    }
    
    // Ordenando os problemas conforme os critérios
    qsort(problemas, N * M, sizeof(problemas[0]), cmp);
    
    // Imprimindo o relatório ordenado
    for (int i = 0; i < N * M; i++) {
        printf("%s\n", problemas[i]);
    }
    
    return 0;
}

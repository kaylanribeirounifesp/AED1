#include <stdio.h>
#include <stdlib.h>

int main() {
    int N; // Número de casos de teste
    scanf("%d", &N);
    
    while (N--) {
        int M; // Número de alunos
        scanf("%d", &M);
        
        int notas[M]; // Notas dos alunos
        int notasOrdenadas[M]; // Notas dos alunos após ordenação
        int i;
        
        // Leitura das notas
        for (i = 0; i < M; i++) {
            scanf("%d", &notas[i]);
            notasOrdenadas[i] = notas[i];
        }
        
        // Ordenação das notas em ordem decrescente usando o método de ordenação simples
        for (i = 0; i < M - 1; i++) {
            for (int j = i + 1; j < M; j++) {
                if (notasOrdenadas[j] > notasOrdenadas[i]) {
                    int temp = notasOrdenadas[i];
                    notasOrdenadas[i] = notasOrdenadas[j];
                    notasOrdenadas[j] = temp;
                }
            }
        }
        
        // Contagem dos alunos que não trocaram de lugar
        int naoTrocou = 0;
        for (i = 0; i < M; i++) {
            if (notas[i] == notasOrdenadas[i]) {
                naoTrocou++;
            }
        }
        
        // Imprime o resultado para o caso atual
        printf("%d\n", naoTrocou);
    }
    
    return 0;
}

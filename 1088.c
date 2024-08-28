#include <stdio.h>
#include <stdlib.h>

int inversoes;  // Variável global para contar o número de inversões

// Função que compara dois valores e retorna a diferença entre eles
int comparar(int a, int b) {
    return a - b;
}

// Função que realiza a intercalação de duas metades de um vetor
void intercalar(int *vetor, int inicio, int meio, int fim) {
    int *temporario = (int *)malloc((fim - inicio) * sizeof(int));  // Vetor temporário para armazenar o resultado da intercalação
    int i = 0, esq = inicio, dir = meio;  // Variáveis para percorrer as duas metades do vetor
    int limiteEsq = meio, limiteDir = fim;  // Limites das duas metades

    // Intercalação das duas metades em ordem crescente
    while (esq < limiteEsq && dir < limiteDir) {
        if (comparar(vetor[esq], vetor[dir]) <= 0) {
            temporario[i++] = vetor[esq++];
        } else {
            temporario[i++] = vetor[dir++];
            inversoes += (limiteEsq - esq);  // Incrementa o número de inversões
        }
    }

    // Copia os elementos restantes da primeira metade, se houver
    while (esq < limiteEsq) {
        temporario[i++] = vetor[esq++];
    }

    // Copia os elementos restantes da segunda metade, se houver
    while (dir < limiteDir) {
        temporario[i++] = vetor[dir++];
    }

    // Copia o vetor temporário de volta para o vetor original
    for (int j = inicio; j < fim; j++) {
        vetor[j] = temporario[j - inicio];
    }

    free(temporario);  // Libera a memória alocada para o vetor temporário
}

// Função que implementa o algoritmo Merge Sort
void ordenar(int *vetor, int inicio, int fim) {
    if (fim - inicio > 1) {
        int meio = (inicio + fim) / 2;  // Calcula o ponto médio do vetor

        ordenar(vetor, inicio, meio);  // Ordena a primeira metade
        ordenar(vetor, meio, fim);     // Ordena a segunda metade
        intercalar(vetor, inicio, meio, fim);  // Intercala as duas metades
    }
}

int main() {
    int tamanho, *vetor;

    // Loop para ler o tamanho do vetor e os elementos do vetor
    while (scanf("%d", &tamanho)) {
        if (tamanho == 0) break;  // Encerra o loop se o tamanho do vetor for 0

        vetor = (int *)malloc(tamanho * sizeof(int));  // Aloca memória para o vetor

        // Lê os elementos do vetor
        for (int i = 0; i < tamanho; i++) {
            scanf("%d", &vetor[i]);
        }

        inversoes = 0;  // Reseta o contador de inversões
        ordenar(vetor, 0, tamanho);  // Ordena o vetor e conta as inversões

        // Imprime o vencedor com base no número de inversões
        printf("%s\n", (inversoes % 2 == 0) ? "Carlos" : "Marcelo");

        free(vetor);  // Libera a memória alocada para o vetor
    }

    return 0;
}

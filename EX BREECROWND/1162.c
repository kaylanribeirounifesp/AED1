#include <stdio.h>

// Função para comparar dois inteiros
int comparar(int a, int b)
{
    return a - b;
}

// Função para trocar o valor de duas variáveis
void trocar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para realizar a ordenação por inserção e contar o número de trocas
int ordenacaoPorInsercao(int *vetor, int tamanho)
{
    int contadorTrocas = 0;

    // Itera sobre cada elemento do vetor, começando do segundo
    for (int i = 1; i < tamanho; ++i)
    {
        int atual = i;
        int anterior = atual - 1;

        // Move o elemento atual para a posição correta no vetor
        while (anterior >= 0 && comparar(vetor[atual], vetor[anterior]) < 0)
        {
            trocar(&vetor[atual], &vetor[anterior]);
            ++contadorTrocas;
            --atual;
            --anterior;
        }
    }

    return contadorTrocas;
}

int main()
{
    int quantidadeCasos, tamanhoVetor, vagões[50];

    // Lê o número de casos de teste
    scanf("%d", &quantidadeCasos);

    // Processa cada caso de teste
    for (int i = 0; i < quantidadeCasos; ++i)
    {
        // Lê o tamanho do vetor para o caso de teste
        scanf("%d", &tamanhoVetor);

        // Lê os elementos do vetor
        for (int j = 0; j < tamanhoVetor; ++j)
        {
            scanf("%d", &vagões[j]);
        }

        // Realiza a ordenação e imprime o número de trocas
        printf("Optimal train swapping takes %d swaps.\n", ordenacaoPorInsercao(vagões, tamanhoVetor));
    }

    return 0;
}

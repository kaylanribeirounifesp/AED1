#include <stdlib.h> 
#include <stdio.h>   

// Função de comparação para usar com qsort
int comp(const void *a, const void *b)
{
    // Converte os ponteiros para int e retorna a diferença
    return *(int *)a - *(int *)b;
}

// Função para realizar busca binária em um vetor ordenado
int pesquisaBinaria(int *V, int n, int valor)
{
    int inicio = 0, fim = n;

    // Enquanto o intervalo de busca for válido
    while (inicio < fim)
    {
        int meio = (inicio + fim) / 2;

        if (V[meio] < valor)
        {
            inicio = meio + 1; // Busca na metade direita
        }
        else
        {
            fim = meio; // Busca na metade esquerda
        }
    }

    // Verifica se o valor foi encontrado e retorna a posição (base 1) ou -1 se não encontrado
    return V[inicio] == valor ? inicio + 1 : -1;
}

int main()
{
    int *marmores;   // Ponteiro para armazenar o vetor de mármores
    int T, N, Q, consulta, r;

    T = 0; // Inicializa o contador de casos de teste
    // Loop para processar múltiplos casos de teste
    while (scanf("%d %d", &N, &Q))
    {
        // Condição de parada: quando N e Q são 0
        if (N == 0 && Q == 0)
            break;

        // Aloca memória para armazenar o vetor de mármores
        marmores = (int *)malloc(sizeof(int) * N);
        // Lê os valores dos mármores
        for (int i = 0; i < N; ++i)
        {
            scanf("%d", &marmores[i]);
        }

        // Ordena o vetor de mármores usando a função de comparação
        qsort(marmores, N, sizeof(int), comp);

        // Imprime o cabeçalho do caso de teste
        printf("CASE# %d:\n", ++T);
        // Processa cada consulta
        for (int i = 0; i < Q; ++i)
        {
            scanf("%d", &consulta);

            // Executa a busca binária para encontrar a consulta
            r = pesquisaBinaria(marmores, N, consulta);
            // Imprime o resultado da busca
            if (r == -1)
            {
                printf("%d not found\n", consulta);
            }
            else
            {
                printf("%d found at %d\n", consulta, r);
            }
        }

        // Libera a memória alocada para o vetor de mármores
        free(marmores);
    }

    return 0; 
}

#include <stdio.h>
#include <string.h>

int main()
{
    int numCasos, numPessoas, altura, primeiro;
    int contagemAlturas[231];  // Array para armazenar a contagem das alturas

    // Lê o número de casos de teste
    scanf("%d", &numCasos);

    // Loop para cada caso de teste
    for (int caso = 0; caso < numCasos; ++caso)
    {
        // Inicializa o array de contagem com zeros
        memset(contagemAlturas, 0, sizeof(contagemAlturas));

        // Lê o número de pessoas
        scanf("%d", &numPessoas);

        // Lê as alturas e incrementa as respectivas posições no array
        for (int i = 0; i < numPessoas; ++i)
        {
            scanf("%d", &altura);
            contagemAlturas[altura]++;
        }

        // Flag para controlar a formatação da saída
        primeiro = 1;
        
        // Imprime as alturas em ordem crescente
        for (int i = 20; i < 231; ++i)
        {
            for (int j = 0; j < contagemAlturas[i]; ++j)
            {
                if (primeiro)
                    primeiro = 0;  // Após o primeiro número, desativa a flag
                else
                    printf(" ");  // Adiciona um espaço antes de imprimir os próximos números
                printf("%d", i);  // Imprime a altura
            }
        }
        printf("\n");  // Nova linha após cada caso de teste
    }

    return 0;
}

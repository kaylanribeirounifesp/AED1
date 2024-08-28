#include <stdio.h>
#include <string.h>

void busca_palavras(char *texto, char *palavra) {
    int pos = 0;
    int encontrou = 0;
    int tam_palavra = strlen(palavra);
    int tam_texto = strlen(texto);
    
    while (pos <= tam_texto - tam_palavra) {
        // Verifica se encontrou a palavra
        if (strncmp(&texto[pos], palavra, tam_palavra) == 0) {
            // Verifica se é uma palavra isolada
            if ((pos == 0 || texto[pos - 1] == ' ') &&
                (texto[pos + tam_palavra] == ' ' || texto[pos + tam_palavra] == '\0')) {
                if (encontrou)
                    printf(" ");
                printf("%d", pos);
                encontrou = 1;
            }
        }
        pos++;
    }
    
    if (!encontrou)
        printf("-1");
    
    printf("\n");
}

int main() {
    char texto[10001];
    int n;
    char palavras[128][51];

    // Lê o texto
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0';  // Remove o newline, se existir

    // Lê a quantidade de palavras
    scanf("%d", &n);
    getchar(); // Remove newline residual

    // Lê as palavras de busca
    for (int i = 0; i < n; i++) {
        scanf("%s", palavras[i]);
    }

    // Para cada palavra, faz a busca no texto
    for (int i = 0; i < n; i++) {
        busca_palavras(texto, palavras[i]);
    }

    return 0;
}
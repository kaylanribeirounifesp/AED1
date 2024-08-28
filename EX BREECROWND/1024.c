#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main() {
    int numTestes, tamanho;
    char tempChar, linha[1001]; // 'linha' armazena as strings de entrada

    // Leitura do número de testes
    scanf("%d\n", &numTestes);

    // Processa cada linha de entrada
    for (int indice = 0; indice < numTestes; ++indice) {
        // Leitura da linha de texto
        scanf("%[^\n]\n", linha);

        // Obtém o comprimento da string
        tamanho = strlen(linha);

        // Aplicação da cifra de deslocamento: desloca cada letra por 3 posições na tabela ASCII
        for (int pos = 0; pos < tamanho; ++pos) {
            if (isalpha(linha[pos])) { // Verifica se o caractere é uma letra
                linha[pos] += 3; // Desloca o caractere para frente
            }
        }

        // Inverte a string
        for (int pos = 0; pos < tamanho / 2; ++pos) {
            tempChar = linha[pos]; // Armazena o caractere atual em 'tempChar'
            linha[pos] = linha[tamanho - 1 - pos]; // Troca com o caractere na posição oposta
            linha[tamanho - 1 - pos] = tempChar; // Completa a troca
        }

        // Ajusta os caracteres da segunda metade da string: decrementa cada caractere por 1
        for (int pos = tamanho / 2; pos < tamanho; ++pos) {
            --linha[pos]; // Desloca o caractere para trás na tabela ASCII
        }

        // Imprime a string transformada
        printf("%s\n", linha);
    }

    return 0;
}

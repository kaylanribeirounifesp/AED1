#include <stdio.h>
#include <string.h>

// Função que retorna a quantidade de LEDs necessária para cada dígito
int ledsPorDigito(char digito) {
    switch (digito) {
        case '0': return 6;
        case '1': return 2;
        case '2': return 5;
        case '3': return 5;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 3;
        case '8': return 7;
        case '9': return 6;
        default: return 0; // Caso inválido, não esperado
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    // Limpar o buffer de entrada após ler o número de casos
    while (getchar() != '\n');

    char valor[10101]; // Máximo de 10100 dígitos + 1 para '\0'

    for (int i = 0; i < N; ++i) {
        // Ler a linha com o número
        fgets(valor, sizeof(valor), stdin);

        // Remover o caractere de nova linha, se presente
        valor[strcspn(valor, "\n")] = '\0';

        int totalLeds = 0;
        for (int j = 0; valor[j] != '\0'; ++j) {
            totalLeds += ledsPorDigito(valor[j]);
        }

        // Imprimir o total de LEDs necessários
        printf("%d leds\n", totalLeds);
    }

    return 0;
}

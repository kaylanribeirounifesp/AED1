#include <stdio.h>

int main() {
    int distancia, tempo;

    // Lê a distância de entrada
    scanf("%d", &distancia);

    // Calcula o tempo necessário
    tempo = 2 * distancia;

    // Imprime o tempo seguido da mensagem "minutos"
    printf("%d minutos\n", tempo);

    return 0;
}

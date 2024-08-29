#include <stdio.h>

int main() {
    int totalSegundos;
    scanf("%d", &totalSegundos);  // Lê o número total de segundos

    // Calcula o número de horas
    int horas = totalSegundos / 3600;
    // Calcula o restante dos segundos após contar as horas
    totalSegundos = totalSegundos % 3600;

    // Calcula o número de minutos
    int minutos = totalSegundos / 60;
    // Calcula o restante dos segundos após contar os minutos
    int segundos = totalSegundos % 60;

    // Imprime o resultado no formato solicitado
    printf("%d:%d:%d\n", horas, minutos, segundos);

    return 0;
}

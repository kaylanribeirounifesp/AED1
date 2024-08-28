#include <stdio.h>

// Função para encontrar o maior entre dois números
int maior(int a, int b) {
    return (a + b + abs(a - b)) / 2;
}

int main() {
    int a, b, c, maior_ab, maior_total;

    // Leitura dos três valores
    scanf("%d %d %d", &a, &b, &c);

    // Encontrar o maior entre os dois primeiros
    maior_ab = maior(a, b);

    // Encontrar o maior entre o resultado anterior e o terceiro valor
    maior_total = maior(maior_ab, c);

    // Imprimir o resultado no formato correto
    printf("%d eh o maior\n", maior_total);

    return 0;
}

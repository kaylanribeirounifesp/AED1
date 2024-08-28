#include <stdio.h>

// Função recursiva embaralhar
int embaralhar(int a, int c, int p) {
    int b;

    // Calcula o valor de b conforme a fórmula fornecida
    if (2 * a <= p) {
        b = 2 * a;
    } else {
        b = 2 * a - (p + 1);
    }

    // Verifica se b é igual a 1 para retornar c ou chamar a função recursivamente
    if (b == 1) {
        return c;
    } else {
        return embaralhar(b, c + 1, p);
    }
}

int main() {
    int p;

    // Lê o valor de p
    printf("Digite o valor de p: ");
    scanf("%d", &p);

    // Chama a função embaralhar com a = 1 e c = 1
    int resultado = embaralhar(1, 1, p);

    // Imprime o resultado
    printf("Resultado: %d\n", resultado);

    return 0;
}

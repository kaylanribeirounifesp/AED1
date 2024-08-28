#include <stdio.h>

struct numero {
    int numerador;
    int denominador;
};

typedef struct numero num;

// Função para calcular o maior divisor comum (MDC)
int calcularMDC(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Função para simplificar a fração
num simplificar(int numerador, int denominador) {
    int mdc = calcularMDC(numerador, denominador);
    num s;
    s.numerador = numerador / mdc;
    s.denominador = denominador / mdc;
    if (s.denominador < 0 && s.numerador > 0){
        s.denominador = s.denominador * -1;
        s.numerador = s.numerador * -1;
    }
    return s;
}

int main() {
    num x, y, r;
    char op, barra;
    int n;

    // Solicita o número de operações
    do {
        scanf("%d", &n);
    } while (n < 1 || n > 10000);

    for (int i = 0; i < n; i++) {
        scanf("%d %c %d %c %d %c %d", &x.numerador, &barra, &x.denominador, &op, &y.numerador, &barra, &y.denominador);

        switch (op) {
            case '+':
                r.numerador = (x.numerador * y.denominador) + (x.denominador * y.numerador);
                r.denominador = x.denominador * y.denominador;
                break;
            case '-':
                r.numerador = (x.numerador * y.denominador) - (x.denominador * y.numerador);
                r.denominador = x.denominador * y.denominador;
                break;
            case '*':
                r.numerador = x.numerador * y.numerador;
                r.denominador = x.denominador * y.denominador;
                break;
            case '/':
                r.numerador = x.numerador * y.denominador;
                r.denominador = x.denominador * y.numerador;
                break;
            default:
                printf("Operador inválido!\n");
                continue;  // Pula para a próxima iteração
        }

        num s = simplificar(r.numerador, r.denominador);
        printf("%d/%d = %d/%d\n", r.numerador, r.denominador, s.numerador, s.denominador);
    }

    return 0;
}

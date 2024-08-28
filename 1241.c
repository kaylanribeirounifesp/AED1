#include <stdio.h>
#include <string.h>

// Função para verificar se B é um sufixo de A
int verificaSufixo(const char *A, const char *B) {
    int lenA = strlen(A);
    int lenB = strlen(B);

    // Se B é maior que A, não pode ser um sufixo
    if (lenB > lenA) {
        return 0; // Não encaixa
    }

    // Comparar os últimos lenB caracteres de A com B
    return strcmp(A + lenA - lenB, B) == 0;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        char A[1001], B[1001];

        // Leitura dos valores A e B
        scanf("%s %s", A, B);

        // Verificar se B é sufixo de A
        if (verificaSufixo(A, B)) {
            printf("encaixa\n");
        } else {
            printf("nao encaixa\n");
        }
    }

    return 0;
}

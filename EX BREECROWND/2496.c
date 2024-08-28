#include <stdio.h>
#include <string.h>

int podeOrdenarComUmaTroca(char *s, int n) {
    // Identificar as posições onde a sequência está fora de ordem
    int pos1 = -1, pos2 = -1;

    // Encontrar as posições onde a sequência está fora de ordem
    for (int i = 0; i < n - 1; i++) {
        if (s[i] > s[i + 1]) {
            if (pos1 == -1) {
                pos1 = i;
            } else {
                pos2 = i + 1;
                break;
            }
        }
    }

    if (pos1 == -1) {
        // A sequência já está ordenada
        return 0;
    }

    // Se só encontramos uma posição fora de ordem, é necessário verificar a próxima posição
    if (pos2 == -1) {
        pos2 = pos1 + 1;
    }

    // Trocar os caracteres nas posições encontradas
    char temp = s[pos1];
    s[pos1] = s[pos2];
    s[pos2] = temp;

    // Verificar se a sequência está ordenada após a troca
    for (int i = 0; i < n - 1; i++) {
        if (s[i] > s[i + 1]) {
            return 1; // Não está ordenada
        }
    }
    return 0; // Está ordenada
}

int main() {
    int N, M;
    char s[27]; // Máximo de 26 letras + terminador nulo

    scanf("%d", &N);
    while (N--) {
        scanf("%d", &M);
        scanf("%s", s);

        if (podeOrdenarComUmaTroca(s, M)) {
            printf("There aren't the chance.\n");
        } else {
            printf("There are the chance.\n");
        }
    }

    return 0;
}

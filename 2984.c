#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    scanf("%s", s);
    
    int pendentes = 0;  // Contador de assuntos pendentes

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            pendentes++;  // Novo assunto pendente
        } else if (s[i] == ')') {
            if (pendentes > 0) {
                pendentes--;  // Fecha um assunto pendente
            }
        }
    }

    if (pendentes > 0) {
        printf("Ainda temos %d assunto(s) pendente(s)!\n", pendentes);
    } else {
        printf("Partiu RU!\n");
    }

    return 0;
}

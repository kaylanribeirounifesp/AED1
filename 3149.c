#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int hora;
    int minuto;
    char nome[101];
} Relato;

// Função de comparação para ordenar os relatos
int compara(const void *a, const void *b) {
    Relato *relatoA = (Relato *)a;
    Relato *relatoB = (Relato *)b;

    // Compara horas
    if (relatoA->hora != relatoB->hora) {
        return relatoA->hora - relatoB->hora;
    }

    // Se horas são iguais, compara minutos
    return relatoA->minuto - relatoB->minuto;
}

int main() {
    int P, Q;
    scanf("%d %d", &P, &Q);

    Relato relatos[1000];
    int totalRelatosValidos = 0;

    // Lê os relatos e filtra aqueles que estão no intervalo "próximo da meia-noite"
    for (int i = 0; i < Q; i++) {
        char horario[6], nome[101];
        scanf("%s %s", horario, nome);

        int hora, minuto;
        sscanf(horario, "%d:%d", &hora, &minuto);

        // Ajusta horas de 00 para 24 para facilitar a comparação
        if (hora == 0) hora = 24;

        // Verifica se o relato está dentro do intervalo considerado "próximo da meia-noite"
        if ((hora == 23 && minuto >= 60 - P) || (hora == 24 && minuto <= P)) {
            relatos[totalRelatosValidos].hora = hora;
            relatos[totalRelatosValidos].minuto = minuto;
            strcpy(relatos[totalRelatosValidos].nome, nome);
            totalRelatosValidos++;
        }
    }

    // Ordena os relatos válidos pelo horário
    qsort(relatos, totalRelatosValidos, sizeof(Relato), compara);

    // Imprime os nomes dos moradores que fizeram relatos válidos
    for (int i = 0; i < totalRelatosValidos; i++) {
        printf("%s\n", relatos[i].nome);
    }

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int hora;
    int minuto;
    char nome[101];
} Relato;

// Função de comparação para ordenar os relatos
int compara(const void *a, const void *b) {
    Relato *relatoA = (Relato *)a;
    Relato *relatoB = (Relato *)b;

    // Compara horas
    if (relatoA->hora != relatoB->hora) {
        return relatoA->hora - relatoB->hora;
    }

    // Se horas são iguais, compara minutos
    return relatoA->minuto - relatoB->minuto;
}

int main() {
    int P, Q;
    scanf("%d %d", &P, &Q);

    Relato relatos[1000];
    int totalRelatosValidos = 0;

    // Lê os relatos e filtra aqueles que estão no intervalo "próximo da meia-noite"
    for (int i = 0; i < Q; i++) {
        char horario[6], nome[101];
        scanf("%s %s", horario, nome);

        int hora, minuto;
        sscanf(horario, "%d:%d", &hora, &minuto);

        // Ajusta horas de 00 para 24 para facilitar a comparação
        if (hora == 0) hora = 24;

        // Verifica se o relato está dentro do intervalo considerado "próximo da meia-noite"
        if ((hora == 23 && minuto >= 60 - P) || (hora == 24 && minuto <= P)) {
            relatos[totalRelatosValidos].hora = hora;
            relatos[totalRelatosValidos].minuto = minuto;
            strcpy(relatos[totalRelatosValidos].nome, nome);
            totalRelatosValidos++;
        }
    }

    // Ordena os relatos válidos pelo horário
    qsort(relatos, totalRelatosValidos, sizeof(Relato), compara);

    // Imprime os nomes dos moradores que fizeram relatos válidos
    for (int i = 0; i < totalRelatosValidos; i++) {
        printf("%s\n", relatos[i].nome);
    }

    return 0;
}

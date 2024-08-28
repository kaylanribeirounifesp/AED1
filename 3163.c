
//tempo limite excedido
#include <stdio.h>
#include <stdlib.h>

// Função para exibir a fila resultante
void exibir(char* fila[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%s", fila[i]);
        if (i < tamanho - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int ponto; // Ponto cardeal do avião
    char id[5]; // Identificador do voo (ex: "A123")

    // Filas para cada ponto cardeal
    char* fila_leste[1000]; // Fila para aviões do lado Leste
    char* fila_norte[500];  // Fila para aviões do lado Norte
    char* fila_sul[500];    // Fila para aviões do lado Sul
    int qtd_leste = 0, qtd_norte = 0, qtd_sul = 0; // Contadores para cada fila

    // Inicializa as filas
    for (int i = 0; i < 1000; i++) {
        fila_leste[i] = NULL;
    }
    for (int i = 0; i < 500; i++) {
        fila_norte[i] = NULL;
        fila_sul[i] = NULL;
    }

    while (1) {
        scanf("%d", &ponto);
        if (ponto == 0) {
            break;
        }
        
        while (scanf("%s", id) && id[0] != '0') {
            char* novo_id = malloc(5 * sizeof(char));
            if (novo_id == NULL) {
                fprintf(stderr, "Erro de alocação de memória\n");
                exit(1);
            }
            snprintf(novo_id, 5, "%s", id);
            
            if (ponto == -4) { // Leste
                fila_leste[qtd_leste++] = novo_id;
            } else if (ponto == -3) { // Norte
                if (qtd_norte < 500) {
                    fila_norte[qtd_norte++] = novo_id;
                }
            } else if (ponto == -2) { // Sul
                if (qtd_sul < 500) {
                    fila_sul[qtd_sul++] = novo_id;
                }
            } else if (ponto == -1) { // Oeste
                // Desloca os aviões na fila do Leste para abrir espaço
                for (int i = 1000; i > 0; i--) {
                    fila_leste[i] = fila_leste[i - 1];
                }
                fila_leste[0] = novo_id;
                qtd_leste++;
            }
        }
    }

    // Cria a fila final
    char* fila_final[2000];
    int tamanho_final = 0;

    // Adiciona aviões do Oeste na fila final
    for (int i = 0; i < qtd_leste; i++) {
        fila_final[tamanho_final++] = fila_leste[i];
    }

    // Alterna entre aviões do Norte e do Sul
    int i_norte = 0, i_sul = 0;
    while (i_norte < qtd_norte || i_sul < qtd_sul) {
        if (i_norte < qtd_norte) {
            fila_final[tamanho_final++] = fila_norte[i_norte++];
        }
        if (i_sul < qtd_sul) {
            fila_final[tamanho_final++] = fila_sul[i_sul++];
        }
    }

    // Adiciona aviões do Leste na fila final
    for (int i = 0; i < qtd_leste; i++) {
        fila_final[tamanho_final++] = fila_leste[i];
    }

    // Exibe o resultado
    exibir(fila_final, tamanho_final);

    // Liberação de memória
    for (int i = 0; i < tamanho_final; i++) {
        free(fila_final[i]);
    }

    return 0;
}

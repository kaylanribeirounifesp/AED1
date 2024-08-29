#include <stdio.h>
#include <string.h>

int main() {
    int q, i, j, k, texto_tam, palavra_tam;
    char texto[129], palavra[129];
    
    scanf("%d", &q);
    
    for (i = 0; i < q; i++) {
        scanf(" %[^\n]", texto);
        scanf(" %s", palavra);
        
        texto_tam = strlen(texto);
        palavra_tam = strlen(palavra);
        int encontrado = 0;
        
        for (j = 0; j <= texto_tam - palavra_tam; j++) {
            // Verifica se a substring do texto é igual à palavra
            if (strncmp(&texto[j], palavra, palavra_tam) == 0) {
                if (j == 0 || texto[j-1] == ' ') {
                    if (j + palavra_tam == texto_tam || texto[j + palavra_tam] == ' ') {
                        if (encontrado) {
                            printf(" ");
                        }
                        printf("%d", j);
                        encontrado = 1;
                    }
                }
            }
        }
        
        if (!encontrado) {
            printf("-1");
        }
        
        printf("\n");
    }
    
    return 0;
}
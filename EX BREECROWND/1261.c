//pontos de feno

#include <stdio.h>
#include <string.h>

typedef struct {
    char cargo[20];
    int comissao; // Corrigido para tipo 'int' diretamente
} funcao;

typedef struct {
    char palavra[300];
} string;

int procuraPalavra(funcao *, char *, int);
int posicao;

int main() { // Alterado para retornar 'int'
    int numPalavras, qtsCargos;
    char texto[10000], *palavraTmp;
    long qtsSalarioTotal;
    string dicionario[10000];
    int i, j;

    scanf("%d %d", &numPalavras, &qtsCargos);

    funcao cargos[numPalavras];

    for (i = 0; i < numPalavras; i++) {
        cargos[i].cargo[0] = '\0'; // Inicializa a string como vazia
        cargos[i].comissao = 0;     // Inicializa o valor da comissão como 0
    }

    for (i = 0; i < numPalavras; i++)
        scanf(" %s %d", cargos[i].cargo, &cargos[i].comissao);

    while (qtsCargos--) {
        qtsSalarioTotal = 0;
        while (true) {
            // Leitura do texto descritivo de funções;
            scanf(" %[^\n]", texto);

            // O caractere '.' marca o final de um caso de teste;
            // Podem haver várias strings em várias linhas diferentes de entrada;
            if (strcmp(texto, ".") == 0)
                break;

            i = 0;
            palavraTmp = strtok(texto, " ");
            if (palavraTmp) {
                strcpy(dicionario[i++].palavra, palavraTmp);
            }

            // Separação da string em palavras individuais
            // Usando o caractere espaço como token;
            while ((palavraTmp = strtok(NULL, " ")) != NULL) {
                strcpy(dicionario[i++].palavra, palavraTmp);
            }

            // Laço itera sobre as structs dicionario e cargos. Soma
            // Os valores para os quais existem descrição na string texto;
            for (j = 0; j < i; j++) {
                if (procuraPalavra(cargos, dicionario[j].palavra, numPalavras)) {
                    qtsSalarioTotal += cargos[posicao].comissao;
                }
            }
        }

        // Impressão do resultado final;
        printf("%ld\n", qtsSalarioTotal);
    }

    return 0; // Adicionado retorno 'int'
}

// Função procura no vetor determinada palavra passada como parâmetro;
int procuraPalavra(funcao *cargos, char *palavra, int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        if (strcmp(cargos[i].cargo, palavra) == 0) {
            posicao = i;
            return 1; // Retorna verdadeiro
        }
    }
    return 0; // Retorna falso
}

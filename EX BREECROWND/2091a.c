#include <stdio.h>
//por algum motivo o tipo int esta dando 10% de erro agora o long long não
int main() {
    int n, num;
    
    // Loop para processar vários casos de teste
    while (scanf("%d", &n) == 1 && n != 0) {
        int result = 0;  // Variável para armazenar o número solitário
        
        // Ler e processar os N números do caso de teste
        for (int i = 0; i < n; i++) {
            scanf("%d", &num);  // Ler o próximo número
            result ^= num;      // Aplicar XOR entre o número atual e o resultado acumulado
        }
        
        // Imprimir o número que ficou sozinho
        printf("%d\n", result);
    }
    
    return 0;  // Termina a execução do programa
}

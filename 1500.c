#include <stdio.h>
#include <stdlib.h>

void adicionaV(int * vetor , int p , int q , int v){
    
    for(int i = p; i <= q ; i++){
        vetor[i] = v;
    }
}

void somaV(int * vetor , int p , int q){
    int soma = 0;
    for(int i = p ; i <= q ; i++){
        soma += vetor[i];
    }
    printf("%d\n",soma);
}

void imprime(int * vetor , int n){
    
    for (int i = 0 ; i < n ; i++){
        printf("saida :%d", vetor[i]);
    }
    printf("\n");
}

int main (){
    int   t, n , c , p, q , op , v;

    scanf("%d",&t);

    for (int  j = 0 ; j < t ; j++){
        scanf("%d %d", &n ,&c);

        int *vetor = (int *)malloc(n*sizeof(int));
                                                    //como iniciar todos iguais a zero
        if (vetor != NULL) {
            for (int i = 0; i < n; i++) {
                vetor[i] = 0;
            }
        }

        for(int i = 0 ; i < c ; i++){
            scanf("%d %d %d",&op , &p ,&q);
              //  analisar funcionamento do scanf
            if(op == 0){
                scanf("%d", &v);
                adicionaV(vetor,p,q,v);
                //imprime(vetor, n);
            }else if(op == 1){
                somaV(vetor, p, q);
                
            }
        }
        
    }
}
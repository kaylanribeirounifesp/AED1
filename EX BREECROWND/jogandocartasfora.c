#include <stdio.h>
#include <stdlib.h>

struct PILHA{
    int val;
    struct PILHA* seg;
};
typedef struct PILHA pilha;

void insere(pilha * p, int x){
    pilha * novo =(pilha *) malloc(sizeof(pilha));
    if(novo == NULL){
        printf("deu ruim");
    };

    novo-> val = x;
    novo->seg = p->seg;
    p->seg = novo;
}

int desempilha(pilha * p){
    int x;
    pilha * lixo, *q, *ant;
    
    if (p->seg == NULL)return -1;
    lixo = p->seg;
    p->seg = lixo->seg;
    x = lixo-> val;
    free(lixo);
    
    q = p->seg;
    if(q == NULL) return x;
    while(q!= NULL && q ->seg != NULL){
        q = q->seg;
    };

    ant = p->seg;  // salva o primeiro
    q->seg = ant; // faz o ultimo apontar pro primeiro
    p->seg = ant ->seg; // o primeiro da pilha vai ser o segundo elemento agr
    ant ->seg = NULL; // o antigo primeiro é o ultimo
    
    return x;
}

void imprime(pilha * p){
    pilha *q = p ->seg;
    while( q != NULL){
        printf("%d", q->val);
        q = q->seg;
    }
    printf("\n");
}


int main(){
    int n, v;
    pilha p;
    pilha *topo = &p;
    topo ->seg = NULL;

    do{
        scanf("%d", &n);                      //  do while mal colocado
        if(n == 0) return 0;
        for(int i = 0 ; i < n ; i++){
            insere(topo, n - i);
        }
//        imprime(topo);
        printf("Discarded cards: ");

         for(int i = 0 ; i < n-1  ; i++){
            v = 0;
             if( i != 0)printf(", ");
            v = desempilha(topo);
            printf("%d",v);
        }
        v = desempilha(topo);
        printf("\nRemaining card: %d\n",v);
        
    }while(n != 0 && n < 50 );

    
}
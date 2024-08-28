#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pilha
{
    char c;
    struct Pilha *seg;
};
typedef struct Pilha pilha;

pilha* empilhar(pilha * p, char x){
    pilha * nova = (pilha*)malloc(sizeof(pilha));
    nova -> c  = x;
    nova -> seg = p; 
    return nova;    
}

pilha* desempilha(pilha *p , char* x){
    pilha *q;
    if(p == NULL)return NULL;
    q = p;
    p = p ->seg;
    *(x) = q->c;
    free(q);
    return p;
}


int minerar(char exp []){
    int i;
    int tam  = strlen(exp);
    int contador = 0;
    char x;
    pilha * cabeca;
    cabeca = NULL;

    for(i = 0 ; i < tam ; i++){
        switch (exp[i]){

            case '<':
            cabeca  = empilhar(cabeca,exp[i]);
                break;

            case '>':
                cabeca = desempilha(cabeca, &x); // nao esta salvando o bagulho
                if(x == '<') contador++;
                x = '0';
                break;

            default:
                break;
        }
    }
    return contador;
}


int main(){
    int n, diamantes; 
    char exp[1001];

    scanf("%d",&n );
    getchar();

    for(int i = 0 ; i < n ; i++){
        fgets(exp , sizeof(exp), stdin);
        diamantes = minerar(exp);
        printf("%d\n",diamantes);

    }
}
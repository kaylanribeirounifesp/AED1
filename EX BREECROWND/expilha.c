#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct cel{
    char op;
    struct cel *seg;
}celula;

void empilha(char c, celula*p){
    celula *nova =(celula*) malloc(sizeof(celula));
    nova ->op = c;
    nova ->seg = p->seg;
    p->seg = nova;
}

int desempilha(celula *p){
    int x ; celula *q;
    q = p->seg;
    x = q->op;
    p->seg = q->seg;
    free(q);
    return x;
}


char *testar(char infix[],celula *p){
    int x;
    int n = strlen(infix);
    char *posfix =(char*) malloc(n*sizeof(char));

    for(int i = 0; infix[i]!= '/0';i++){
        switch (infix[i]){
        case '(':
            empilha(infix[i],p);
            break;
        case ')':
            x = desempilha(p);
            while(x != '('){
                posfix[j++] = x;
                x = desempilha(p);
            }
            break;

        case '+':
        case '-':
        while(p-> seg != NULL && p->seg->op != '('){
            x = desempilha(p);
            posfix[j++]= x;
        }
        empilha(infix[i], p);
        break;

        case '*':
        case '/':
        while(p->seg != NULL && (p->seg->op) != '+' && (p->seg-> op) != '-'  ){
            x = desempilha(p);
        }
        empilha(infix[i], p);
        
        default:
            posfix[j++] = infix[i];
            break;
        }
    }
    while(p->seg != NULL){
        x = desempilha(infix[i--];p);
        empilha(x,p);
    }
    free (p);
    return &posfix;
}


int main(){
    int n;
    celula cabeca;
    celula *p;
    p = &cabeca;
    p->seg = NULL;
    char expressao[300];
    char *posfix;
    
    for(int i = 0 ; i< n ; i++){
    fgets(expressao, sizeof(expressao),stdin);
     posfix = testar(expressao,p);
     printf("%s",posfix);
    }
    
}
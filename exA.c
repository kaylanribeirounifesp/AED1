#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct LISTA{
    char conteudo[20];
    struct LISTA* prox;
};
typedef struct LISTA lista;


void insere(lista *p , char* item){
    lista *novo = malloc(sizeof(lista));
    strcpy(novo -> conteudo ,item);
     novo->prox = p-> prox;
     p->prox = novo;

}
void imprime(lista *cabeca){
    lista *p = cabeca->prox;

    if(p == NULL)printf("erro");
    for(  ; p != NULL ; p= p-> prox){
        printf("%s ", p->conteudo);
    }
    printf("\n");
}
void libera(lista *cabeca){
    lista *p;
    lista *lixo;
    p = cabeca-> prox;
    while(p!=NULL){
    lixo = p;
    p = p->prox;
    free(lixo);
    }
}

int main(){
    int n = 0;
    char frase [21000];
    char *item;
    lista *c = malloc(sizeof(lista));
    c -> prox = NULL;
    
    scanf("%d",&n);
    getchar();
    for (int i = 0; i < n; i++){
        fgets(frase,sizeof(frase),stdin);
        
        item = strtok(frase, " ");
        while(item!=NULL){
            insere(c,item);
            item = strtok(NULL , " ");
        }

        imprime(c);
        libera(c);
        c ->prox = NULL;
    }
    
    free(c);

}
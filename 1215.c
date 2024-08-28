#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct LISTA {
    char conteudo[50];
    struct LISTA *seg;
};
typedef struct LISTA lista;

void insere(lista * lst, char* aluno){
    lista *q = lst->seg;
    lista *ant = NULL;
    lista *novo =(lista*) malloc(sizeof(lista));
    
    if(novo == NULL){
        printf("erro de alocação");
        return;
    }
    strcpy(novo->conteudo,aluno);

    if(q == NULL){
        lst->seg = novo; // primeriro elemento da lista
        novo->seg = NULL;
        return;
    }
    
    while(q!=NULL && strcmp(novo->conteudo , q->conteudo) > 0){
        ant = q;
        q = q->seg; 
    }
    if(ant == NULL){
        novo->seg = lst->seg;
        lst->seg = novo;
    }else{
        novo->seg = ant->seg;
        ant->seg = novo;
    }
}

void imprime(lista *cabeca){
    lista *p = cabeca->seg;

    if(p == NULL)return;

    for(  ; p != NULL ; p= p-> seg){
        printf("%s", p->conteudo);
        if(p->seg!= NULL)printf("\n");
    }
    
}

lista* procurar(lista * lst, int posicao){
    int i = 1;
    lista* q = lst ->seg;

    while(q!= NULL && i!= posicao){
        q = q->seg;
        i++;
    }
    return q;
}
void limpa(lista * c){
    if(c ->seg == NULL)return;
    lista *lixo;
    while(c->seg != NULL){
        lixo = c->seg;
        c->seg = lixo->seg;
        free(lixo);
    }
}

int main(){
    char frase[5000];
    char * item;
    lista * C = malloc(sizeof(lista));
    C->seg = NULL;
     while (fgets(frase, sizeof(frase), stdin) != NULL) {
        // Remove o caractere de nova linha, se presente
        frase[strcspn(frase, "\n")] = '\0';
         
         
        item = strtok(frase, " ");
            while (item){   
                insere(C,item);
                item = strtok(NULL , " ");
            }

        imprime(C);
        limpa(C);
    }


}
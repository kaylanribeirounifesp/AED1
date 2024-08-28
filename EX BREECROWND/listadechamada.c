#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct LISTA {
    char conteudo[21];
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

void limpar(lista* lst){
    lista *lixo = lst ->seg;
    while(lst->seg != NULL){
        lst ->seg = lixo->seg;
        free(lixo);
        lixo = lst->seg;
    }
}

int main(){
    char aluno[21];
    int n, posicao;
    lista * chamada , *sorteado;
    lista l;
    chamada = &l;
    chamada ->seg = NULL;

    scanf("%d %d", &n , &posicao);  
    getchar();

    if(n < 1 || n > 100){
        return 0;
    }

    for(int i = 0 ; i < n ; i++){
        fgets(aluno ,sizeof(aluno), stdin);
        aluno[strlen(aluno) -1] = '/0';  //remove o barra n do final
        insere(chamada,aluno);
    }
    sorteado = procurar(chamada,posicao);    
    printf("%s\n",sorteado->conteudo);
    limpar(chamada);

}
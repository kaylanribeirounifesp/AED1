#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct cel{
    char nome[20];
    struct cel * seg;
};
typedef struct cel celula;

void insere(celula *lst,char * amigo){
    celula * nova= (celula*)malloc (sizeof (celula));
    strcpy(nova-> nome, amigo);
    celula *p;
    p = lst;
    while(p->seg != NULL)p = p->seg;
    nova ->seg = NULL;
    p->seg = nova;
}
void concatenar(celula *l,celula*n,char indicacao[]){
    celula * p, *q,*ant;
    p = l->seg;
    q = n->seg;
    if(strcmp (indicacao, "nao") == 0){
        while(p->seg != NULL)p = p-> seg;
        p -> seg =  q;
    }else{
        ant =NULL;
        while (p != NULL && (strcmp(p->nome , indicacao) )!= 0){
            ant = p;
            p = p->seg;
        }

        if(ant ==NULL){
            l->seg = q;
            while(q->seg != NULL)q = q->seg;
            q ->seg = p;
            
        }else{
            ant ->seg = q;
            while(q->seg != NULL)q = q->seg;
            q->seg = p;
        }
    }


}
void imprima(celula *lst){
    celula * p = lst ->seg;
    while(p != NULL){
        printf("%s", p->nome);
        if(p ->seg != NULL )printf(" ");
        p = p->seg;
    }
}

void limpar(celula *l) {
    celula *p = l->seg;
    while (l->seg != NULL) {
        l->seg = p->seg;
        free(p);
        p = l->seg;
    }
}

int main (){
    char lista[1000];
    char novoamigos[1000];
    char indicacao[20];
    char * item;
    celula cabeca;
    celula head;
    celula * l;
    celula * n;
    l = &cabeca;
    n = &head;
    n->seg = l -> seg = NULL;

    fgets(lista,sizeof(lista),stdin);
    lista[strcspn(lista, "\n")] = '\0'; // Remove o '\n'

    item = strtok(lista, " ");
        while (item){   
            insere(l,item);
            item = strtok(NULL , " ");
        }

    fgets(novoamigos,sizeof(novoamigos),stdin);
    novoamigos[strcspn(novoamigos, "\n")] = '\0'; // Remove o '\n'
    
        item = strtok(novoamigos, " ");
        while (item){   
            insere(n,item);
            item = strtok(NULL , " ");
        }

    fgets(indicacao,sizeof(indicacao),stdin);
    indicacao[strcspn(indicacao, "\n")] = '\0'; // Remove o '\n'
    concatenar(l,n,indicacao);
    imprima(l);
    limpar(l);   
    printf("\n");
    return 0;
}
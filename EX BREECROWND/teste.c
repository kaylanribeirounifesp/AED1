#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct LISTA{
    char conteudo[100];
    struct LISTA* seg;
};
typedef struct LISTA lista;


void insere(lista *p , char* item){
    lista *novo = malloc(sizeof(lista));
    lista *q = p;
    strcpy(novo -> conteudo ,item);
    novo->seg = NULL; 
    while(q->seg != NULL)q = q ->seg;
    q ->seg = novo;
}

void insereordenado(lista *lst , char* item){
    lista *novo = (lista*)malloc(sizeof(lista));
    lista *q = lst->seg;
    lista *ant = NULL;
    strcpy(novo -> conteudo ,item);
     if(q == NULL){
        lst->seg = novo;
        novo->seg = NULL;
        return;

     }
    while(q!= NULL && strcmp(q->conteudo , novo->conteudo)==-1){
            ant = q;    
            q=q->seg; 
        }

        if(q!= NULL && strcmp(q->conteudo, novo->conteudo)== 0){
            free(novo);
            return;
        }
        if(ant == NULL){
            lst->seg = novo;
            novo->seg = q;
        }else{
            ant -> seg = novo;
            novo->seg = q;
        }
    }


void imprime(lista *cabeca){
    lista *p = cabeca->seg;

    if(p == NULL)printf("erro");
    for(  ; p != NULL ; p= p-> seg){
        printf("%s", p->conteudo);
        if(p->seg!= NULL)printf(" ");
    }
    printf("\n");
}
void libera(lista *cabeca){
    lista *p;
    lista *lixo;
    p = cabeca-> seg;
    while(p!=NULL){
    lixo = p;
    p = p->seg;
    free(lixo);
    }
}

/*lista*ordenar(lista * p , lista *q){
    lista *q, * p,aux;
    p = lst->seg;
    q  = p ->seg;

    while( p != NULL || q! NULL){
        if(strcmp(p -> conteudo , q->conteudo) == 1){
            p ->seg = q->seg;
            q = p->seg;
            if (ant == NULL){
                lst -> seg = q;
            }
            aux = p;
            p = q;
            q = aux;
            q = q->seg;
            return p;
        }
        else if(strcmp(p -> conteudo , q->conteudo)== -1){
          return p->seg = ordenar(p->seg, q);
          q = q->seg;
        }
    }

}
lista* troca( lista * p , lista * q){
    p->seg = q->seg;
    q->seg = p;
    
    return q;
    
}*/
int main(){
    int n = 0;
    char frase [21000];
    char *item;
    lista *c = malloc(sizeof(lista));
    c -> seg = NULL;
    
    scanf("%d",&n);
    getchar();
    for (int i = 0; i < n; i++){
        fgets(frase, sizeof(frase), stdin);     // nao lembro como usar scanf
        frase[strcspn(frase, "\n")] = '\0'; // Remove o '\n'

        item = strtok(frase, " ");
        while(item!=NULL){
            insereordenado(c,item);
            item = strtok(NULL , " ");
        }

        imprime(c);
        libera(c);
        c ->seg = NULL;
    }
    printf("\n");   
    free(c);

}
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
    lista *q = lst->seg;
    lista *ant = NULL;
    lista *novo = (lista*)malloc(sizeof(lista));
    strcpy(novo -> conteudo ,item);
    
    if(q == NULL){
        lst->seg = novo;  // se a lista estiver vazia
        novo->seg = NULL;
        return;
     }
    while(q!= NULL && strcmp(q->conteudo , novo->conteudo)==-1){ // se a palavra inserida for alfabeticamente menor q outra palavra da lista ira parar o while
            ant = q;    
            q=q->seg; 
        }

        if(q!= NULL && strcmp(q->conteudo, novo->conteudo)== 0){ // se a alfabeticamente for igual não ira inserir
            free(novo);
            return;
        }
        if(ant == NULL){
            lst->seg = novo;  // atualizao primeiro caso o while de cima nao rode
            novo->seg = q;
        }else{
            ant -> seg = novo; // insere antes do q parou
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
salvalista(lista* lst, lista* array[],int n){
    array [n] = lst;
}


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
        frase[strcspn(frase, "\n")] = '\0'; // Remove o '\n' do final da frase

        item = strtok(frase, " ");
        while(item!=NULL){
            insereordenado(c,item);    //divide a frase quando encontrar um espaço e insere numa lista
            item = strtok(NULL , " ");
        }
        salvalista(i,c);
        libera(c);
        c ->seg = NULL;

    }
    for{
        
    }
    printf("\n");   
    free(c);

}
#include <stdio.h>
#include <stdlib.h>

struct cel {
    int conteudo;
    struct cel *seg; /* seguinte */
};
typedef struct cel celula;

//imprime sem cabeça
void Imprimas(celula *lst) {
    celula *p;
    for (p = lst; p != NULL; p = p->seg)
        printf("%d\n", p->conteudo);
}

//imprime lista com cabeça
void Imprima(celula *lst) {  // lista com cabeça é apenas não armazenar nada no primeiro conteúdo
    celula *p;                    //acessar e modificar apenas o segundo
    for (p = lst->seg; p != NULL; p = p->seg)
        printf("%d\n", p->conteudo);
}

//função de busca
celula *Busca(int x, celula *lst) {
    celula *p;
    p = lst->seg;
    while (p != NULL && p->conteudo != x)
        p = p->seg;
    return p;
}


//remove espaços alocados
void Remove(celula *p) {
    if (p->seg == NULL) exit(1);
    celula *lixo;
    lixo = p->seg;
    p->seg = lixo->seg;
    free(lixo);
}

// insere
void Insere(int y, celula *p) {
    celula * aux = p->seg;
    celula * ant = NULL;
     celula *nova;
    nova = malloc(sizeof(celula));
    nova->conteudo = y;
    if(p->seg != NULL)
    {
       while( aux != NULL && aux->conteudo != y){
        ant = aux;
        aux = aux ->seg;
       }
       if(aux != NULL){
        if(ant == NULL)p->seg = ant;
        ant -> seg = nova->seg;
        free(aux);
        free(nova);
       }else{
        nova->seg = p->seg;
        p->seg = nova;
    
       }
      } 
    nova->seg = p->seg;
    p->seg = nova;
    


}

int main(){
    int n;
    int x;
    celula * G = malloc(sizeof(celula));
    G->seg = NULL;

    do{
        scanf("%d",&n);
        int * v = malloc(n*sizeof(int));
        for(int i = 0 ; i< n; i++){
        scanf("%d",&x);
        Insere(x, G);
        }
         for(int i = 0 ; i< n; i++){
            printf("%d",v[i]);
        }
        printf("\n");
        Imprima(G);

    }while(n !=0);
}
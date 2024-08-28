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

// busca recursiva
celula *BuscaR(int x, celula *lst) {
    if (lst->seg == NULL)
        return NULL;
    if (lst->seg->conteudo == x)
        return lst->seg;
    return BuscaR(x, lst->seg);
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
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->conteudo = y;
    nova->seg = p->seg;
    p->seg = nova;
}

void limpa(celula *l) {
    celula *p = l->seg;
    while (l->seg != NULL) {
        l->seg = p->seg;
        free(p);
        p = l->seg;
    }
}
celula *Buscamin(celula*lst){
    celula *p = lst->seg;
    celula *q = p->seg;
    while (q!=NULL){
        if(p->conteudo > q->conteudo) p=q;
        q=q->seg;
    }
    return p;
}

void removeX(celula*lst ,int x ){
    celula* ant;
    celula* p;
    ant = lst;
    p = lst->seg;

    if(p->seg  == NULL && p->conteudo == x ){
        lst = p;
        free(p);
    }
    while(p!=NULL){
        if(p->conteudo == x){
            ant->seg = p->seg;
            free(p);
            p = ant ->seg; 
        }else{
            ant = p;
            p = p->seg;
        }
    }
}

void retiramin(celula*lst){
    celula *p = lst->seg;
    celula *q = p->seg;
    celula *z = p;
    printf("nosas");
    while(q!= NULL){
        if(p->conteudo > q-> conteudo)p=q;
        q=q->seg;
    }
    while(z->seg->conteudo != p ->conteudo)z=z->seg;
        z->seg = p->seg;
        free(p);
}

void VL(int v[], celula *lst, int tam){              //vetoor -> lista
    int i = 0;
    for(; i < tam ; i++){
        celula*nova = malloc(sizeof(celula));
        nova->seg = lst->seg;
        lst->seg = nova;
        nova ->conteudo= v[i]; 
    }
}
void RVL(int v[],celula *lst,int n){
    if(n <= 0)return;                           //vetor ->lista recursiva
    celula *nova = malloc(sizeof(celula));
    nova -> conteudo = v[n-1];
    nova->seg = lst->seg;
    lst->seg = nova;
    RVL(v, nova, n-1);
}
int * lv(celula * lst){
    int t= 0, i = 0;
    celula *p =lst ->seg;

    while(p!=NULL){
        t++;
        p = p->seg;
    }
    int *vetor = malloc(t*sizeof(int));
    p= lst->seg;

    while(p!= NULL){
        vetor[i++] = p->conteudo;
        p = p->seg;
    }
    for(int j = 0 ; j< t ;j++){
        printf("%d ",vetor[j]);
    }
    return vetor;
}
int main() {
    celula *c = malloc(sizeof(celula));
    c->seg = NULL;
    int *v;
        Insere(1, c);
        Insere(5, c);
        Insere(25, c);
        Insere(50, c);
        Insere(0, c);
        Insere(70, c);
        //RVL(vetor,c,tam);
        v = lv(c);
        printf("\n");
        Imprima(c);
        limpa(c);
        free(c);
    return 0;
};
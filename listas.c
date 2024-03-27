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

int main() {
    celula *c = malloc(sizeof(celula));
    c->seg = NULL;
    celula *min;
    Insere(20, c);
    Insere(10, c);
    Insere(70, c);
    Imprima(c);
    printf("\n");
    min = Buscamin(c);
    Imprima(min);
    limpa(c);
    free(c);
    free(min);
    return 0;
};
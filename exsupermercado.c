#include <stdio.h>
#include <stdlib.h>

struct CLIENTE {
    int Nitens;
    int identidade;
    struct CLIENTE *prox;
};
typedef struct CLIENTE cliente;

typedef struct funcio {
    int temptrabalho;
    int tempacumulado;
    int identificacao;
    struct CLIENTE *pri;
    struct CLIENTE *ult;
} funcionario;

void inicializa(funcionario *lst, int vi) {
    lst->pri = NULL;
    lst->ult = NULL;
    lst->temptrabalho = vi;
    lst->tempacumulado = 0;
}

funcionario* verifica(funcionario *p, int N) {
    int menor = p[0].tempacumulado;
    int posicao = 0;
    for (int i = 1; i < N; i++) {
        if (p[i].tempacumulado == 0) return &p[i];
        if (menor > p[i].tempacumulado) {
            menor = p[i].tempacumulado;
            posicao = i;
        }
    }
    return &p[posicao];
}

void insere(funcionario *p, int cj, int i,int n) {
    cliente *novo = (cliente*)malloc(sizeof(cliente));
    novo->Nitens = cj;
    novo->prox = NULL;

    if (p[i].pri == NULL) {
        p[i].pri = p[i].ult = novo;
    } else {
        funcionario *s = verifica(p, n);
        s->ult->prox = novo;
        s->ult = novo;
    }
    p[i].tempacumulado += (p[i].temptrabalho) * (novo->Nitens);
}
void limpa(funcionario*p,int N){
    cliente* lixo;
    for (int i = 0; i< N; i++){
        while(p->pri!= NULL){
            lixo = p[i].pri;
            p[i].pri= lixo -> prox;
            free(lixo);
        }
    }    
}
void imprime(funcionario*p,int n){
    int maior = -1;
    for(int i = 0; i< n; i++){
        if(maior < p[i].tempacumulado)maior = p[i].tempacumulado;
    }
    printf("%d", maior);
}
int main() {
    int N, M;

    scanf("%d %d", &N, &M);
    funcionario *LOJA = (funcionario*)malloc(N * sizeof(funcionario));
    int vi[N], cj[M];

    for (int i = 0; i < N; i++) {
        scanf("%d", &vi[i]);
        inicializa(&LOJA[i], vi[i]);
    }

    for (int i = 0; i < M; i++) {
        scanf("%d", &cj[i]);
        insere(LOJA, cj[i], i,N);
    }
    
    imprime(LOJA,N);
    limpa(LOJA,N);
    free(LOJA);

    return 0;
}
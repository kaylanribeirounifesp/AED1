#include <stdio.h>
#include <stdlib.h>

struct CLIENTE{
    int Nitens;
    int identidade;
    struct CLIENTE *prox;
};
typedef struct CLIENTE cliente;
typedef struct funcio{
    int temptrabalho;
    int tempacumulado = 0;
    int identificacao;
    struct CLIENTE* pri;
    struct CLIENTE* ult;

} funcionario;

funcionario *criaFila(int v[] ){
    funcionario * caixa= (funcionario*)malloc (sizeof(funcionario));
    
    caixa->prim = NULL;
    caixa->ult = NULL;
    caixa->temptrabalho = v;
}

funcionario* buscamin(funcionario *p){
int menor;
int a, b;
for(int i= 0 ; i< N ;i++)
 menor = p[i].tempacumulado;
 if(menor == 0)return 

}


void insere(funcionario*p,int cj[],N){
    funcionario *q;
    cliente *novo = malloc(sizeof(cliente));
    
    buscamin(p);
    novo->Nitens = cj;  
    p. tempacumulado += (p. temptrabalho)*cj;
    novo->prox = NULL;
for(int i = 0   ; q!= NULL&& i < N   ; i++ ){
   for(int j= i ; j => i; j--){
   q[i]-> tempacumulado > q[j] -> tempacumlado;
   }
}

    if(p->prim == NULL) p-> prim = p-> ult = novo;
    else{p->ult->prox = novo;
    p->ult= novo;
    }

}

int main(){
int N, M;

scanf("%d %d", &N, &M);
funcionario* atendentes[N];
  for (int i = 0; i < N; i++) {
        filas[i] = criarFila();
    }
    
  
  int vi[N], cj[m];
  for(int i = 0 ; i < N; i++){
    scanf("%d",&vi[i]);
  }
  for(int i = 0 ; i< N ; i++){
    inicializa(&caixa[i],v[i])
  }
  for(int i = 0  ; i < M ; i+++){
    scanf("%d",&cj);
    insere(&caixa[i], cj[i]);
  }



}
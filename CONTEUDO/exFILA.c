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

void inicializa(funcionario* lst,int vi ){
    funcionario * caixa= (funcionario*)malloc (sizeof(funcionario));
     
    caixa->prim = NULL;
    caixa->ult = NULL;
    caixa->temptrabalho = vi;
}

funcionario* verifica(funcionario **p, n){
int menor,posicao;
menor = p[0]->tempacumulado;
for(int i= 1; i< N ;i++){
  if(p[i]->tempacumulado == 0 )return p[i];
  if(menor > p[i]->tempacumulado){
    menor = p[i]->tempacumulado;
    posicao = i;
  }
}
  return p[posicao];
}


void insere(funcionario**p,int cj,int i){
    funcionario *q= p[i],s;

    cliente *novo = malloc(sizeof(cliente));
    novo->Nitens = cj;
    novo-prox = NULL;


    if(p[i]->pri == NULL){    
      p[i]->prim = p -> ult = novo;  
      p[i]->tempacumulado += (p->temptrabalho)*(novo->Nitens);
      
    }else{
      s = verifica(p);
      s->ult = novo;
      novo->prox=NULL;
      s->tempacumulado += (s->temptrabalho)*(novo->Nitens);

    }

}

int main(){
  int N, M;

  scanf("%d %d", &N, &M);
  funcionario **LOJA;
  funcionario *filas[N];
  LOJA = filas;
  int vi[N], cj[m];
  
  for(int i = 0 ; i < N; i++){
    scanf("%d",&vi[i]);
  }
  for(int i = 0 ; i< N ; i++){
    inicializa(filas[i],vi[i]);
  }
  for(int i = 0  ; i < M ; i++){
    scanf("%d",&cj);
    insere(LOJA, cj[i],i);
  }



}
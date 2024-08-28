
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 struct PILHA{
    char c ;
    struct PILHA* seg;
 };
 typedef struct PILHA pilha;

  void empilhar(pilha* cabeca , char c){
    pilha *novo = (pilha*)malloc(sizeof(pilha));
    if(!novo)return;
    novo -> c = c;
    novo->seg = cabeca->seg;
    cabeca -> seg = novo;
  }

  void desempilhar(pilha* cabeca, char* x){;
    if(cabeca->seg == NULL){
        *x = -1;
        return;  //se estiver vazia é pq esta errada
    }
    pilha * lixo = cabeca ->seg;
     *(x) = lixo ->c;
    cabeca->seg = lixo->seg;
    free(lixo);
    return;
  }

  void limpar(pilha * c){
    pilha* lixo = c->seg;

    while(lixo!= NULL){
        c->seg = lixo->seg;
        free(lixo);
        lixo = c->seg;
    }
  }

  void parenteses(char exp[]){
    char x;
    pilha *cabeca = (pilha*)malloc(sizeof(pilha));
    cabeca->seg = NULL;
    int tam = strlen(exp);

    for( int j = 0; j < tam; j++){

            switch (exp[j])
            {
            case '(':
                empilhar(cabeca , exp[j]);  // empilha apenas (
                break;
            case ')':
                desempilhar(cabeca,&x);  // retira um elementod a ppilha se nao for ( entao a expressao esta errada
                if(x != '('){
                    printf("incorrect\n"); //nao eesta certo
                    x = 0;
                    limpar(cabeca);
                    free(cabeca);
                    return;
                }
                break;
            default:
                    break;
                }

            }

            if(cabeca ->seg == NULL){
                printf("correct\n");   // verifica se soubrou alguem na pilha

            }else{
                printf("incorrect\n");
            }

            limpar(cabeca);
            free(cabeca);

  }
 int main (){
    int n ;
    char exp[1001];

    scanf("%d",&n);
    getchar();

    for(int i = 0 ; i < 1000 ; i++){
        fgets(exp, sizeof(exp) , stdin);
        parenteses(exp);
    }

 }
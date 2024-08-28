#include <stdio.h>
#include <stdlib.h>
#define vertex int

#include <stdio.h>
#include <stdlib.h>

struct No{
   int  w;
   struct No* seg;
};
typedef struct No no;

struct graph {
   int V; 
   int A; 
   no **adj; 
};
typedef struct graph* Grafo;

Grafo grafoinit(int V){
   Grafo G = malloc(sizeof*G);
   G->A = 0;
   G->V = V;
   G->adj = malloc(V*sizeof(int*));
   for(int i = 0 ; i < V; i++)G->adj[i] = NULL;

   return G;
}

no* Newnode(int w , no* V){
   no* novo = malloc (sizeof(no));
   novo -> w = w;
   novo -> seg = V;
   return novo;
}

void Grafoinsere(Grafo G , int v , int w){
   no* a;

   for(a = G->adj[v] ; a!=NULL ; a = a->seg)if(a->w == w)return;
   G->adj[v] = Newnode(w,G->adj[v]);
   G->A++;
}

void GrafoRemove(Grafo G , int v , int w){
   no * aux , *ant;
   ant = NULL;
   if(v > G->V)return;
   for(aux = G->adj[v];aux != NULL && aux->w != w ; aux = aux->seg){
      ant = aux;
   }
   if(aux == NULL)return;
   if(ant == NULL){
      G->adj[v]= aux->seg;
      free(aux);
   }else{
      ant->seg = aux->seg;
      free(aux); 
   }

}

void Grafoimprime(Grafo G){
   no * aux;

   for(int i = 0 ; i < G->V ; i++){
      printf("%d : ",i);
      for(aux = G->adj[i]; aux != NULL ; aux = aux->seg){
         printf("%d",aux->w);
         if(aux ->seg != NULL)printf(" ");
      }
      printf("\n");
   }
}


int main(){
   int v = 5;
   Grafo G = grafoinit(v);

   Grafoinsere(G,0,1);
   Grafoinsere(G,0,2);
   Grafoinsere(G,0,3);
   Grafoinsere(G,4,1);
   Grafoinsere(G,2,3);
   Grafoinsere(G,4,0);
   Grafoinsere(G,3,2);
   Grafoimprime(G);
   printf("\n");
   GrafoRemove(G,4,1);
   Grafoimprime(G);

}
#include <stdio.h>
#include <stdlib.h>

struct graph {
   int V; 
   int A; 
   int **adj; 
};
typedef struct graph *Graph;

// Protótipo da função MATRIXint
static int **MATRIXint(int r, int c, int val);

Graph GRAPHinit(int V) {        
   Graph G = malloc(sizeof *G);   
   if (G == NULL) {
       printf("Erro: falha na alocação de memória para o grafo.\n");
       exit(1);
   }
   G->V = V; 
   G->A = 0;
   G->adj = MATRIXint(V, V, 0);    
   return G;
}

static int **MATRIXint(int l, int c, int val) { 
   int **m = malloc(l * sizeof(int *));       
   if (m == NULL) {
       printf("Erro: falha na alocação de memória para a matriz.\n");
       exit(1);
   }
   for (int i = 0; i < l; ++i) {
      m[i] = malloc(c * sizeof(int));  
      if (m[i] == NULL) {
          printf("Erro: falha na alocação de memória para a matriz.\n");
          exit(1);
      }
   }
   for (int i = 0; i < l; ++i)
      for (int j = 0; j < c; ++j)
         m[i][j] = val;                   
   return m;
}

void GRAPHinsertArc(Graph G, int v, int w) { 
   if (G->adj[v][w] == 0) {
      G->adj[v][w] = 1; 
      G->A++;
   }
}

void GRAPHremoveArc(Graph G, int v, int w) { 
   if (G->adj[v][w] == 1) {
      G->adj[v][w] = 0; 
      G->A--;
   }
}

void GRAPHshow(Graph G) { 
   for (int v = 0; v < G->V; ++v) {
      printf("%d:", v);
      for (int w = 0; w < G->V; ++w)
         if (G->adj[v][w] == 1) 
            printf(" %d", w);
      printf("\n");
   }
}

int * indentificainsik(Graph G){
   int* insik= malloc((G->V)*sizeof(int));
   for(int i = 0 ; i < G->V;i++){
      insik[i] = 1;
      for(int j = 0 ; j < G->V; j++){
         if(G->adj[i][j] != 0){
            insik[i] = 0;
            break;
         }

      }

   }
   return insik;
}

int * indentificainsider(Graph G){
   int* insider= malloc((G->V)*sizeof(int));
   for(int i = 0 ; i < G->V;i++){
      insider[i] = 1;
      for(int j = 0 ; j < G->V; j++){
         if(G->adj[j][i] != 0){
            insider[i] = 0;
            break;
         }

      }

   }
   return insider;
}
int isolado(Graph G, int v){
   int isolado = 1;
   for(int i = 0 ; i < G->V ; i++)if(G->adj[v][i] != 0)isolado = 0;
   for(int i = 0 ; i< G->V ; i++)if(G->adj[i][v] != 0)isolado = 0;

   return isolado;
}

void Graphindeg(Graph G , int v){
   int grau = 0;
   for(int i = 0 ; i < G->V; i++){
      if(G->adj[i][v] == 1)grau++;
   } 
   printf("grau de entrada :%d",grau);
}



// verificar se matriz é dirigida

int graphhundir(Graph G){
   
   for(int i = 0 ; i < G->V; i++){
      for(int j = 0 ; j < G->V ; j++ ){
         if(G->adj[i][j] != G->adj[j][i])return 0;
      }
   }
   return 1;
}

void UGRAPHinserearesta(Graph G , int v , int w){
   G->adj[v][w] = 1;
   G->adj[w][v] = 1;
   return;
}

int main() {
   int V = 5; // Número de vértices
   int x = 4;
   int dirigido;
   Graph G = GRAPHinit(V); // Inicializa o grafo com V vértices
   int *vetor;
   int *vetor0;
   // Inserindo alguns arcos
   GRAPHinsertArc(G, 0, 1);
   GRAPHinsertArc(G, 1, 4);
   GRAPHinsertArc(G, 3, 2);
   GRAPHinsertArc(G, 2, 1);
   UGRAPHinserearesta(G , 0 , 4);
   UGRAPHinserearesta(G , 3 , 4);

   // Mostrando o grafo
   printf("Grafo após insercao dos arcos:\n");
   // GRAPHshow(G);

   // Removendo um arco
   GRAPHremoveArc(G, 3, 4);

   // Mostrando o grafo após remoção do arco
   GRAPHshow(G);

  // vetor = indentificainsik(G); //grau de saida nulo
  // vetor0 = indentificainsider(G); //grau de entrada nulo

   int sinal;
   sinal = isolado(G,x);

   printf("\nvertice %d é isolado : %d", x , sinal);
   printf("\n");
  
   Graphindeg(G,x);

   dirigido = graphhundir(G);
   printf("grafo e dirigido: %d", dirigido);

   // Liberar a memória alocada
   for (int i = 0; i < V; i++) {
       free(G->adj[i]);
   }
   free(G->adj);
   free(G);

   return 0;
}

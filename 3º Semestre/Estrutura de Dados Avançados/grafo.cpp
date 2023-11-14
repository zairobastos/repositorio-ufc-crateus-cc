// Fonte:https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/graphdatastructs.html

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A estrutura graph representa um grafo. 
O campo adj é um ponteiro para a matriz de adjacências do grafo. 
O campo V contém o número de vértices e o campo A contém o número de arcos do grafo. */
#include<stdio.h>
#include<stdlib.h>

#define vertex int
struct graph {
   int V; 
   int A; 
   int **adj; 
};

/* Um Graph é um ponteiro para um graph, ou seja, um Graph contém o endereço de um graph. */

typedef struct graph *Graph;

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função MATRIXint() 
aloca uma matriz com linhas 0..r-1 e colunas 0..c-1. Cada elemento da matriz recebe valor val. */

static int **MATRIXint( int r, int c, int val) { 
   int **m = (int **)malloc( r * sizeof (int *));
   for (vertex i = 0; i < r; ++i) 
      m[i] = (int*) malloc( c * sizeof (int));
   for (vertex i = 0; i < r; ++i)
      for (vertex j = 0; j < c; ++j)
         m[i][j] = val;
   return m;
}


Graph GRAPHinit( int V) { 
   Graph G = (Graph)malloc( sizeof (Graph));
   G->V = V; 
   G->A = 0;
   G->adj = MATRIXint( V, V, 0);
   return G;
}


/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHinsertArc() 
insere um arco v-w no grafo G. A função supõe que v e w são distintos, 
positivos e menores que G->V. Se o grafo já tem um arco v-w, a função não faz nada. */

void GRAPHinsertArc( Graph G, vertex v, vertex w) { 
   if (G->adj[v][w] == 0) {
      G->adj[v][w] = 1; 
      G->adj[w][v] = 1; 
      G->A++;
   }
}

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHremoveArc() 
remove do grafo G o arco v-w. A função supõe que v e w são distintos, 
positivos e menores que G->V. Se não existe arco v-w, a função não faz nada. */

void GRAPHremoveArc( Graph G, vertex v, vertex w) { 
   if (G->adj[v][w] == 1) {
      G->adj[v][w] = 0; 
      G->adj[w][v] = 0; 
      G->A--;
   }
}

/* REPRESENTAÇÃO POR MATRIZ DE ADJACÊNCIAS: A função GRAPHshow() imprime, 
para cada vértice v do grafo G, em uma linha, todos os vértices adjacentes a v. */

void GRAPHshow( Graph G) { 
   for (vertex v = 0; v < G->V; ++v) {
      printf( "%2d:", v);
      for (vertex w = 0; w < G->V; ++w)
         if (G->adj[v][w] == 1) 
            printf( " %2d", w);
      printf( "\n");
   }
}

int main() {
  Graph g;
  g = GRAPHinit(6);
  GRAPHinsertArc(g,0,1);
  GRAPHinsertArc(g,1,2);
  GRAPHinsertArc(g,3,1);
  GRAPHinsertArc(g,4,0);
  GRAPHinsertArc(g,5,3);
  GRAPHshow(g);
 
}

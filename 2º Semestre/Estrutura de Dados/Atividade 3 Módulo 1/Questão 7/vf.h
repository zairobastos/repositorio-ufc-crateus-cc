
typedef struct elemento Elemento;
typedef struct pilha Pilha;

Pilha*inicilizaPilha();
Elemento * inicializaElemento(int n);

void FPVazia(Pilha * pilha);
int vazia(Pilha * pilha);
void empilha (Elemento *n,Pilha * pilha);
int tamanho(Pilha * pilha);
void imprime(Pilha* pilha);
void verificav(Pilha *pilha);

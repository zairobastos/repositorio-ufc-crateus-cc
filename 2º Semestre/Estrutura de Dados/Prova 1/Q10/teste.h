#ifndef TESTE_H_INCLUDED
#define TESTE_H_INCLUDED

typedef struct elemento Elemento;
typedef struct pilha Pilha;

Pilha* pilha_createe();
Elemento * inicializaElemento(int n);

void FPVazia(Pilha * pilha);
int vazia(Pilha * pilha);
void empilha (Elemento *n,Pilha * pilha);
int tamanho(Pilha * pilha);
void imprime(Pilha* pilha);
void teste_pilha(Pilha * pilha, int e);
void mostra(Pilha * pilha);

#endif // TESTE_H_INCLUDED

#ifndef CARACTERES_H_INCLUDED
#define CARACTERES_H_INCLUDED

typedef struct fila Fila;
typedef struct elemento Elemento;
typedef struct pilha Pilha;

Pilha*inicilizaPilha();
Elemento * inicializaElemento(char n);
Fila * inicializaFila();
void definir(Fila * w);
int vazia(Fila * w);
int cheia(Fila * w);
int inserir(Fila * w,char item);
int remover(Fila * w,char * item);
int tamanho(Fila * w);
void imprime(Fila *w);
void teste(Fila *w);

void FPVazia(Pilha * pilha);
void empilha (Elemento *n,Pilha * pilha);
int vaziap(Pilha * pilha);

#endif // CARACTERES_H_INCLUDED

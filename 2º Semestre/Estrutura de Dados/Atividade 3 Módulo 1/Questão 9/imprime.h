#ifndef IMPRIME_H_INCLUDED
#define IMPRIME_H_INCLUDED

typedef struct fila Fila;

Fila * inicializaFila();
void definir(Fila * w);
int vazia(Fila * w);
int cheia(Fila * w);
int inserir(Fila * w,int item);
int remover(Fila * w,int * item);
int tamanho(Fila * w);
int comeco_fi(Fila * w,int * item);
void imprime(Fila *w);

#endif // IMPRIME_H_INCLUDED

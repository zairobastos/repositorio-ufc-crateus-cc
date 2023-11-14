#ifndef IMPRIME_H_INCLUDED
#define IMPRIME_H_INCLUDED

typedef struct fila Fila;
typedef int FilaItem;

Fila * fila_create();
void definir(Fila * w);
int vazia(Fila * w);
int cheia(Fila * w);
int fila_insert(Fila * w,FilaItem);
int tamanho(Fila * w);
void print_rec(Fila *w,int i);

#endif // IMPRIME_H_INCLUDED

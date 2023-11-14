#ifndef CONCATENA_H_INCLUDED
#define CONCATENA_H_INCLUDED

typedef struct fila Fila;

Fila * inicializaFila();
void definir(Fila * w);
int vazia(Fila * w);
int cheia(Fila * w);
int inserir(Fila * w,int item);
int remover(Fila * w,int * item);
int tamanho(Fila * w);
int comeco_fi(Fila * w,int * item);
void imprime1(Fila *w);
void imprime2(Fila *w);
void imprime3(Fila *w);
void concate(Fila *w1,Fila *w2);

#endif // CONCATENA_H_INCLUDED

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct Lista lista;

lista * inicializaLista();
void create(lista *a,int n);
void ini(lista *a);
int isFull(lista *a);
int isEmpty(lista *a);
int size(lista *a);
int add(lista *a,int e);
int remover(lista *a,int e);
void imprime(lista *a);
int linearSearch(lista *a,int e);
int bynarySearch(lista *a,int e);
void clear(lista *a);

#endif // LISTA_H_INCLUDED

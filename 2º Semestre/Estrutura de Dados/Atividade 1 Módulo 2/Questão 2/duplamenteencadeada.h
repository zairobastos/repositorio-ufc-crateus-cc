#ifndef DUPLAMENTEENCADEADA_H_INCLUDED
#define DUPLAMENTEENCADEADA_H_INCLUDED

typedef struct Elemento elemento;
typedef struct Lista lista;

lista* create();
elemento* createElemento(int n);

int size(lista* q);
int isEmpty(lista* q);
int add(lista* q, elemento* num);
int remove_(lista* q,int valor);
void imprime(lista* q);
int find(lista* q, elemento* num);
int clear(lista* q);

#endif // DUPLAMENTEENCADEADA_H_INCLUDED
